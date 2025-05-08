#ifndef SQLITEDATABASELOADER_H
#define SQLITEDATABASELOADER_H

#include "sqldatabaseloader.h"

class SQLiteDatabaseLoader : public SQLDatabaseLoader
{
public:
    SQLiteDatabaseLoader(const QString &dbPath);
};

#endif // SQLITEDATABASELOADER_H
