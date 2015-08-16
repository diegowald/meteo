#include "specialrowtablemodel.h"
#include <QColor>

specialRowTableModel::specialRowTableModel(QDateTime d, modelType t, QObject *parent) :
    QSqlTableModel(parent)
{
    t_date = d;
    t_type = t;
}

QVariant specialRowTableModel::data(const QModelIndex &index, int role) const
{
    bool specialBackground = false;
    if(role == Qt::BackgroundRole){
        QModelIndex i = index.sibling(index.row(), 0);
        if(t_type == days){
            QDateTime d = QDateTime::fromString(i.data().toString(), "yyyy-MM-dd hh:mm:ss");
            specialBackground = (d == t_date);
        }
        if(t_type == noaa){
            QDateTime d;
            d.setDate(QDate::fromString(i.data().toString(), "yyyy-MM-dd"));
            specialBackground = (d.date() == t_date.date());
        }
        if(t_type == month){
            QDateTime d;
            d.setDate(QDate::fromString(i.data().toString(), "yyyy-MM-dd"));
            specialBackground = ((d.date().year() == t_date.date().year()) && (d.date().month() == t_date.date().month()));

        }
        if(specialBackground){
            return QColor(Qt::green);
        }
    }

    return QSqlTableModel::data(index, role);
}
