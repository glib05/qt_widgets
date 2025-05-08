#ifndef DATABASELOADER_H
#define DATABASELOADER_H

#include <QString>

class DatabaseLoader
{
public:
    virtual ~DatabaseLoader() = default;
    virtual void loadCountries() = 0;
    virtual void loadOperatorsForCountry(const QString &countryCode) = 0;
};

#endif // DATABASELOADER_H
