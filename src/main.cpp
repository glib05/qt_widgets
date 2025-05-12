#include "mainwindow.h"

#include <QApplication>
#include "sqlitedatabaseloaderfactory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(new SQLiteDatabaseLoaderFactory());
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
