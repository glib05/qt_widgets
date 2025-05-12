#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaseloaderfactory.h"
#include <QVBoxLayout>
#include "omdelegate.h"


const QString DBNAME = "system.db";


MainWindow::MainWindow(DatabaseLoaderFactory *loaderFactory, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(1);

    ui->treeWidget->setItemDelegate(new OMDelegate(ui->treeWidget));

    dir = QDir(QCoreApplication::applicationDirPath());

    loader = loaderFactory->createLoader(dir.filePath(DBNAME));
    // loader = new SQLiteDatabaseLoader("OM system.db");

    const auto countriesData = loader->loadCountries();
    for (const auto &countryData : countriesData){
        addRoot(countryData);
    }

    delete loaderFactory;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete loader;
}

void MainWindow::addRoot(const Country &countryData){
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, countryData.name + " (" + countryData.code + ")");
    itm->setData(0, Qt::DecorationRole, QIcon(dir.filePath("Icons") + "/"+
                                              countryData.code + ".png"));
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
    itm->setData(0, Qt::DecorationRole, QIcon(dir.filePath("Icons") + "/" +
                                              QString::number(operatorData.mcc) + "_" +
                                              QString::number(operatorData.mnc) + ".png"));
    parent->addChild(itm);
}

