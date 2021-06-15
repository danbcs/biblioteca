#ifndef LIVRO_H
#define LIVRO_H

#include <QString>
#include "bancodedados.h"

class livro
{
public:
    livro();
    bool isEmpty();

    bool addBook(bancodedados& bd);

    bool removeBook(bancodedados& bd);

    bool updateBook(bancodedados& bd);

    bool returnBook(bancodedados& bd, const QString campo, const QString valor);

    bool bookExists(bancodedados& bd, const QString& isbn_aux) const;

    void printAllBooks() const;

    bool removeAllBooks();

    QString isbn;
    QString nome;
    QString autor;
    QString categoria;
};

#endif // LIVRO_H
