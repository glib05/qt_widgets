#ifndef OMDELEGATE_H
#define OMDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>


class OMDelegate : public QStyledItemDelegate
{
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    // void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // OMDELEGATE_H
