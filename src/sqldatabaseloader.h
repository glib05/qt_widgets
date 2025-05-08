#ifndef SQLDATABASELOADER_H
#define SQLDATABASELOADER_H

#include "databaseloader.h"
#include <QtSql/QSqlDatabase>

class SQLDatabaseLoader : public DatabaseLoader
{
public:
    virtual ~SQLDatabaseLoader() = default;
    QVector<Country> loadCountries() override;
    QVector<Operator> loadOperatorsForCountry(const QString &countryCode) override;
protected:
    QSqlDatabase db;
};

#endif // SQLDATABASELOADER_H
