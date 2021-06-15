#include "livro.h"

livro::livro()
{

}

bool livro::isEmpty()
{
    if(livro::isbn.isNull() || livro::nome.isNull() || livro::autor.isNull() || livro::categoria.isNull())
        return true;
    else
        return false;
}
