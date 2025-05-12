#ifndef DATABASELOADERFACTORY_H
#define DATABASELOADERFACTORY_H

#include "databaseloader.h"
#include <memory>
#include <QString>

class DatabaseLoaderFactory
{
public:
    virtual ~DatabaseLoaderFactory() = default;
    virtual DatabaseLoader* createLoader(const QString &connectionString) = 0;
};

#endif // DATABASELOADERFACTORY_H
