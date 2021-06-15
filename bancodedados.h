#ifndef BANCODEDADOS_H
#define BANCODEDADOS_H

#include <QSqlDatabase>

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

    bool execute(QString);

    QString executeReturn(QString str);

    bool removeAllBooks();

    void close();

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
