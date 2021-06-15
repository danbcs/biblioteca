#ifndef BANCODEDADOS_H
#define BANCODEDADOS_H

#include <QSqlDatabase>
#include <livro.h>

class bancodedados
{
public:
    /**
     * @brief Constructor
     *
     * Constructor sets up connection with db and opens it
     * @param path - absolute path to db file
     */
    bancodedados(const QString& path);

    /**
     * @brief Destructor
     *
     * Close the db connection
     */
    ~bancodedados();

    bool isOpen() const;

    bool addBook(const livro& livro);

    bool removeBook(const QString& isbn);

     bool updateBook(const livro& livro);

     livro returnBook(const QString& campo, const QString& valor);

     bool bookExists(const QString& isbn) const;

     void printAllBooks() const;

    bool removeAllBooks();

    void close();

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
