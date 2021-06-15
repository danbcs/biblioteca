#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bancodedados.h"
#include "livro.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_enviar_clicked()
{
    bancodedados bd_open = bancodedados("/home/daniel/Biblioteca/biblioteca/db_biblioteca");
    livro bkp_livro;

    bkp_livro.isbn = ui->le_isbn->text();
    bkp_livro.nome = ui->le_nome->text();
    bkp_livro.autor = ui->le_autor->text();
    bkp_livro.categoria = ui->le_categ->text();

    if(!bkp_livro.addBook(bd_open))
        qDebug() << "Error add livro";
    bd_open.close();
}

void MainWindow::on_bt_pesq_clicked()
{
    bancodedados bd_open = bancodedados("/home/daniel/Biblioteca/biblioteca/db_biblioteca");
    livro bkp_livro;
    QString campo = ui->cb_pesq->currentText();
    QString valor = ui->le_pesq->text();

    if(!bkp_livro.returnBook(bd_open, campo, valor))
        qDebug() << "Livro não encontrado";

    bd_open.close();

    ui->le_isbn_2->setText(bkp_livro.isbn);
    ui->le_nome_2->setText(bkp_livro.nome);
    ui->le_autor_2->setText(bkp_livro.autor);
    ui->le_categ_2->setText(bkp_livro.categoria);

}

void MainWindow::on_bt_atualizar_clicked()
{
    bancodedados bd_open = bancodedados("/home/daniel/Biblioteca/biblioteca/db_biblioteca");
    livro bkp_livro;
    bkp_livro.isbn = ui->le_isbn_2->text();
    bkp_livro.nome = ui->le_nome_2->text();
    bkp_livro.autor = ui->le_autor_2->text();
    bkp_livro.categoria = ui->le_categ_2->text();

   if(bkp_livro.updateBook(bd_open))
        qDebug() << "livro Atualizado.";

    bd_open.close();

}

void MainWindow::on_bt_remov_clicked()
{
    bancodedados bd_open = bancodedados("/home/daniel/Biblioteca/biblioteca/db_biblioteca");
    livro bkp_livro;
    bkp_livro.isbn = ui->le_remov->text();

    if(bkp_livro.removeBook(bd_open))
        qDebug() << "livro Removido.";

    bd_open.close();



}

