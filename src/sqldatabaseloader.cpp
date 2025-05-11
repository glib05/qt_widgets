#include "sqldatabaseloader.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

// SQLDatabaseLoader::SQLDatabaseLoader() {}
// inline SQLDatabaseLoader::~SQLDatabaseLoader() = default;

QVector<Country> SQLDatabaseLoader::loadCountries() {
    QVector<Country> countries;

    QSqlQuery query("SELECT DISTINCT name, code FROM countries ORDER BY name ASC", db);

    if (!query.exec()) {
        qCritical() << "Countries Table:" << query.lastError().text();
        return countries;
    }

    while (query.next()) {
        Country c;
        c.code = query.value(1).toString();
        c.name = query.value(0).toString();
        countries.append(c);
    }

    return countries;
}

QVector<Operator> SQLDatabaseLoader::loadOperatorsForCountry(const QString &countryCode) {
    QVector<Operator> operators;

    QSqlQuery query(db);
    query.prepare(R"(
        SELECT o.mcc, o.mnc, o.name
        FROM operators o
        JOIN countries c ON o.mcc = c.mcc
        WHERE c.code = :code
    )");
    query.bindValue(":code", countryCode);

    if (!query.exec()) {
        qCritical() << "Operators table:" << query.lastError().text();
        return operators;
    }

    while (query.next()) {
        Operator op;
        op.mcc = query.value(0).toInt();
        op.mnc = query.value(1).toInt();
        op.name = query.value(2).toString();
        operators.append(op);
    }

    return operators;
}
