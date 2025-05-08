#ifndef DATABASELOADER_H
#define DATABASELOADER_H

#include <QString>
#include "databasestructures.h"
#include <QVector>

class DatabaseLoader
{
public:
    virtual ~DatabaseLoader() = default;
    virtual QVector<Country> loadCountries() = 0;
    virtual QVector<Operator> loadOperatorsForCountry(const QString &countryCode) = 0;
};

#endif // DATABASELOADER_H
