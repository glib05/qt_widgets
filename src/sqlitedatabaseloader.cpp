#include "sqlitedatabaseloader.h"
#include <QtSql/QSqlError>

SQLiteDatabaseLoader::SQLiteDatabaseLoader(const QString &dbPath) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        qCritical() << "Не вдалося відкрити SQLite:" << db.lastError().text();
    }
}
