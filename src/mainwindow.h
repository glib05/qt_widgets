#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include "databaseloader.h"
#include <QDir>
#include "databaseloaderfactory.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void addRoot(const Country &countryData);
    void addChild(QTreeWidgetItem *parent, const Operator &operatorData);

public:
    MainWindow(DatabaseLoaderFactory *loaderFactory, QWidget *parent = nullptr );
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DatabaseLoader *loader;
    QDir dir;
};
#endif // MAINWINDOW_H
