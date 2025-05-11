#include "mainwindow.h"

#include <QApplication>
#include <sqlitedatabaseloader.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

// int main(int argc, char *argv[]){
//     QApplication app(argc, argv);
//     DatabaseLoader *loader = new SQLiteDatabaseLoader(DBPATH);
//     loader->loadCountries();
//     loader->loadOperatorsForCountry("US");
//     delete loader;
// }
