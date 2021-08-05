#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QString>


//forward declared class
class QSqlDatabase;

const QString DATABASE_FILENAME = "rentals.db";
class DatabaseManager
{
 public:
    static DatabaseManager& instance();
    ~DatabaseManager();
protected:
    // I made this protected so the copy and assignement operator will not work, in order to make this class a
    //singleton
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);
private:
    QSqlDatabase* mDatabase;
};
#endif // DATABASEMANAGER_H
