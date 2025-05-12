#include "sqlitedatabaseloaderfactory.h"

DatabaseLoader* SQLiteDatabaseLoaderFactory::createLoader(const QString &connectionString)
{
    return new SQLiteDatabaseLoader(connectionString);
}
