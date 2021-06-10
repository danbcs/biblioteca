#ifndef LIVRO_H
#define LIVRO_H

#include <QString>

class livro
{
public:
    livro();
    bool isEmpty();

    QString isbn;
    QString nome;
    QString autor;
    QString categoria;
};

#endif // LIVRO_H
