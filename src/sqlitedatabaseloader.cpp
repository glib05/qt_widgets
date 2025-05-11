#include "sqlitedatabaseloader.h"
#include <QtSql/QSqlError>

SQLiteDatabaseLoader::SQLiteDatabaseLoader(const QString &dbPath) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        qCritical() << "Cannot open SQLite:" << db.lastError().text();
    }
}
