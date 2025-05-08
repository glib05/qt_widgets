#include "mainwindow.h"

#include <QApplication>
#include <sqlitedatabaseloader.h>

const QString DBPATH = "D:\\CVs\\Ozzylogik_test_task\\qt_widgets\\db\\OM system.db";

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow w;
//     w.show();
//     return a.exec();
// }

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    DatabaseLoader *loader = new SQLiteDatabaseLoader(DBPATH);
    loader->loadCountries();
    loader->loadOperatorsForCountry("US");
    delete loader;
}
