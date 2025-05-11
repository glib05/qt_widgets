#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlitedatabaseloader.h"

const QString DBPATH = "D:\\CVs\\Ozzylogik_test_task\\qt_widgets\\db\\OM system.db";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(1);
    loader = new SQLiteDatabaseLoader(DBPATH);
    const auto countriesData = loader->loadCountries();
    for (const auto &countryData : countriesData){
        addRoot(countryData);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete loader;
}

void MainWindow::addRoot(const Country &countryData){
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, countryData.name+" ("+countryData.code+")");
    ui->treeWidget->addTopLevelItem(itm);

    const auto operatorsData = loader->loadOperatorsForCountry(countryData.code);
    for (const auto &operatorData : operatorsData){
        addChild(itm, operatorData);
    }
}

void MainWindow::addChild(QTreeWidgetItem *parent, const Operator &operatorData){
    QTreeWidgetItem *itm = new QTreeWidgetItem(parent);
    itm->setText(0, operatorData.name + " (" +
                        QString::number(operatorData.mcc) + "-" +
                        QString::number(operatorData.mnc) + ")");
    parent->addChild(itm);
}
