#ifndef SQLDATABASELOADER_H
#define SQLDATABASELOADER_H

#include "databaseloader.h"
#include <QtSql/QSqlDatabase>

class SQLDatabaseLoader : public DatabaseLoader
{
public:
    virtual ~SQLDatabaseLoader() = default;
    void loadCountries() override;
    void loadOperatorsForCountry(const QString &countryCode) override;
protected:
    QSqlDatabase db;
};

#endif // SQLDATABASELOADER_H
