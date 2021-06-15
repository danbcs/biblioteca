#include "bancodedados.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

bancodedados::bancodedados(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

bancodedados::~bancodedados()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool bancodedados::isOpen() const
{
    return m_db.isOpen();
}


bool bancodedados::execute(QString str){
    QSqlQuery query;
    qDebug() << str;
    query.prepare(str);

    if(!query.exec())
        return false;
return true;
}

QString bancodedados::executeReturn(QString str){
    QSqlQuery query;
    qDebug() << str;
    query.prepare(str);

    if(query.exec())
    {
        if(query.next())
        {
            QStringList list;
            list << query.value("ISBN").toString() << query.value("nome").toString() << query.value("autor").toString() << query.value("categoria").toString();
            return list.join('*');
        }
    }
    return "0";

}
/*
bool bancodedados::addBook(const livro& livro)
{
    bool success = false;
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO livro (ISBN, nome, autor, categoria) VALUES (:ISBN, :nome, :autor, :categoria)");
        queryAdd.bindValue(":ISBN", livro.isbn);
        queryAdd.bindValue(":nome", livro.nome);
        queryAdd.bindValue(":autor", livro.autor);
        queryAdd.bindValue(":categoria", livro.categoria);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add livro failed: " << queryAdd.lastError();
        }

        queryAdd.finish();

    return success;
}

bool bancodedados::removeBook(const QString& isbn)
{
    bool success = false;

    if (bookExists(isbn))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM livro WHERE ISBN = (:isbn)");
        queryDelete.bindValue(":isbn", isbn);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remoção falhou: " << queryDelete.lastError();
        }
        queryDelete.finish();
    }
    else
    {
        qDebug() << "livro não existe";
    }
    return success;
}

bool bancodedados::updateBook(const livro& livro)
{
    bool success = false;
        QSqlQuery queryAdd;
        queryAdd.prepare("UPDATE livro SET nome = :nome, autor = :autor, categoria = :categoria WHERE ISBN = :ISBN");
        queryAdd.bindValue(":ISBN", livro.isbn);
        queryAdd.bindValue(":nome", livro.nome);
        queryAdd.bindValue(":autor", livro.autor);
        queryAdd.bindValue(":categoria", livro.categoria);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "Update livro failed: " << queryAdd.lastError();
        }

        queryAdd.finish();

    return success;
}

bool bancodedados::bookExists(const QString& isbn) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT ISBN FROM livro WHERE ISBN = (:isbn)");
    checkQuery.bindValue(":isbn", isbn);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "ISBN não existe: " << checkQuery.lastError();
    }

    return exists;
}

/*
livro bancodedados::returnBook(const QString& campo, const QString& valor){

    livro aux_livro;
    QSqlQuery checkQuery;
    //ajustar forma de consulta

    if(campo == "ISBN")
        checkQuery.prepare("SELECT * FROM livro WHERE ISBN = :valor");
    else if(campo == "Nome")
        checkQuery.prepare("SELECT * FROM livro WHERE nome = :valor");
    else if(campo == "Autor")
        checkQuery.prepare("SELECT * FROM livro WHERE autor = :valor");
    else if(campo == "Categoria")
        checkQuery.prepare("SELECT * FROM livro WHERE categoria = :valor");

    checkQuery.bindValue(":valor", valor);


    if (checkQuery.exec())
    {
        if(checkQuery.next())
        {
            aux_livro.isbn = checkQuery.value("ISBN").toString();
            aux_livro.nome = checkQuery.value("nome").toString();
            aux_livro.autor = checkQuery.value("autor").toString();
            aux_livro.categoria = checkQuery.value("categoria").toString();
        }
    }
    else
    {
        qDebug() << "Não encontramos registros: " << checkQuery.lastError();
    }
    checkQuery.finish();
    return aux_livro;
}

*/
//para testes
bool bancodedados::removeAllBooks()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM livro");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "foram removidos: " << removeQuery.lastError();
    }

    return success;
}

void bancodedados::close() {

    if (m_db.isOpen())
    {
        m_db.close();
    }
}

