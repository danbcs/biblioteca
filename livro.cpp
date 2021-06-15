#include "livro.h"
#include <QDebug>

livro::livro()
{

}

bool livro::isEmpty()
{
    if(livro::isbn.isNull() || livro::nome.isNull() || livro::autor.isNull() || livro::categoria.isNull())
        return true;
    return false;
}

bool livro::addBook(bancodedados& bd)
{
        QString query = QString("INSERT INTO livro (ISBN, nome, autor, categoria) VALUES ('%1', '%2', '%3', '%4')").arg(isbn).arg(nome).arg(autor).arg(categoria);
        if(!bd.execute(query))
            return false;
    return true;
}

bool livro::removeBook(bancodedados& bd)
{
        if (!bookExists(bd, isbn))
            return false;
        QString query = QString("DELETE FROM livro WHERE ISBN = '%1'").arg(isbn);
        if(!bd.execute(query))
            return false;
    return true;
}

bool livro::bookExists(bancodedados& bd, const QString& isbn_aux) const
{
    QString query = QString("SELECT ISBN FROM livro WHERE ISBN = '%1'").arg(isbn_aux);
    if(!bd.execute(query))
        return false;
return true;
}

bool livro::updateBook(bancodedados& bd)
{
    QString query = QString("UPDATE livro SET nome = '%1', autor = '%2', categoria = '%3' WHERE ISBN = '%4'").arg(nome).arg(autor).arg(categoria).arg(isbn);

    if(!bd.execute(query))
        return false;

    return true;
}

bool livro::returnBook(bancodedados& bd, const QString campo, const QString valor){

    livro aux_livro;
    //ajustar forma de consulta

    QString query = QString("SELECT * FROM livro WHERE %1 = '%2'").arg(campo).arg(valor);

    QString strReturn = bd.executeReturn(query);

    if (strReturn == "0")
        return false;
    QStringList list_book = strReturn.split('*');

    isbn = list_book.at(0);
    nome = list_book.at(1);
    autor = list_book.at(2);
    categoria = list_book.at(3);
    return true;
}
