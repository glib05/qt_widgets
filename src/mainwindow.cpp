#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlitedatabaseloader.h"
#include <QVBoxLayout>

const QString DBPATH = "D:\\CVs\\Ozzylogik_test_task\\qt_widgets\\db\\OM system.db";

#include <QStyledItemDelegate>
#include <QPainter>

class CustomDelegate : public QStyledItemDelegate
{
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        painter->save();

        // Draw background and focus
        opt.widget->style()->drawPrimitive(QStyle::PE_PanelItemViewItem, &opt, painter, opt.widget);

        // Draw icon
        QRect iconRect = option.rect.adjusted(5, 5, -5, -5);
        QIcon icon = qvariant_cast<QIcon>(index.data(Qt::DecorationRole));
        if (!icon.isNull()) {
            icon.paint(painter, iconRect, Qt::AlignVCenter | Qt::AlignLeft);
        }

        // Draw text (shifted to the right to leave space for icon)
        int iconSize = 24;
        QRect textRect = option.rect.adjusted(iconSize + 10, 0, 0, 0);
        painter->drawText(textRect, Qt::AlignVCenter | Qt::AlignLeft, index.data(Qt::DisplayRole).toString());

        painter->restore();
    }
};



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(1);

    // Встановлюємо делегат
    ui->treeWidget->setItemDelegate(new CustomDelegate(ui->treeWidget));

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
    itm->setText(0, countryData.name + " (" + countryData.code + ")");
    itm->setData(0, Qt::DecorationRole, QIcon("D:/CVs/Ozzylogik_test_task/qt_widgets/db/Countries/" + countryData.code + ".png"));
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
    itm->setData(0, Qt::DecorationRole, QIcon("D:/CVs/Ozzylogik_test_task/qt_widgets/db/Operators/" +
                                              QString::number(operatorData.mcc) + "_" +
                                              QString::number(operatorData.mnc) + ".png"));
    parent->addChild(itm);
}

