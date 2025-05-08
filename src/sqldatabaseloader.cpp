#include "sqldatabaseloader.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

// SQLDatabaseLoader::SQLDatabaseLoader() {}
// inline SQLDatabaseLoader::~SQLDatabaseLoader() = default;

void SQLDatabaseLoader::loadCountries(){
    QSqlQuery query("SELECT mcc, code, name, mnc_length FROM countries");
    if (!query.exec()) {
        qCritical() << "Помилка запиту:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        qDebug() << query.value(0).toInt() << query.value(1).toString()
        << query.value(2).toString() << query.value(3).toInt();
    }
}

void SQLDatabaseLoader::loadOperatorsForCountry(const QString &countryCode){
    QSqlQuery query;
    query.prepare(R"(
        SELECT o.mcc, o.mnc, o.name
        FROM operators o
        JOIN countries c ON o.mcc = c.mcc
        WHERE c.code = :code
    )");
    query.bindValue(":code", countryCode);

    if (!query.exec()) {
        qCritical() << "Помилка запиту операторів:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        qDebug() << query.value(0).toInt() << query.value(1).toInt() << query.value(2).toString();
    }
}
