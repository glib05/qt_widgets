#ifndef SQLITEDATABASELOADERFACTORY_H
#define SQLITEDATABASELOADERFACTORY_H

#include "databaseloaderfactory.h"

#include "databaseloaderfactory.h"
#include "sqlitedatabaseloader.h"

class SQLiteDatabaseLoaderFactory : public DatabaseLoaderFactory
{
public:
    DatabaseLoader* createLoader(const QString &connectionString) override;
};

#endif // SQLITEDATABASELOADERFACTORY_H
