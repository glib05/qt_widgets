#ifndef DATABASESTRUCTURES_H
#define DATABASESTRUCTURES_H

#include <QString>

struct Country {
    int mcc;
    QString code;
    QString name;
    int mncLength;
};

struct Operator {
    int mcc;
    int mnc;
    QString name;
};

#endif // DATABASESTRUCTURES_H
