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
    /*qDebug() << i;
    qDebug() << i.data();*/
    if(role == Qt::BackgroundRole){
        /*qDebug() << index;
        qDebug() << index.data();*/
        QModelIndex i = index.sibling(index.row(), 0);
        /*qDebug() << i;
        qDebug() << i.data();*/
        if(t_type == days){
            QDateTime d = QDateTime::fromString(i.data().toString(), "yyyy-MM-dd hh:mm:ss");
            specialBackground = (d == t_date);
        };
        if(t_type == noaa){
            QDateTime d;
            d.setDate(QDate::fromString(i.data().toString(), "yyyy-MM-dd"));
            specialBackground = (d.date() == t_date.date());
        };
        if(t_type == month){
            QDateTime d;
            d.setDate(QDate::fromString(i.data().toString(), "yyyy-MM-dd"));
            //qDebug() << i.data().toString() << d << QDate::fromString(i.data().toString(), "yyyy-MM-dd");
            /*qDebug() << ((d.date().year() == t_date.date().year()) && (d.date().month() == t_date.date().month())) ;
            qDebug() << d.date() << t_date();*/
            specialBackground = ((d.date().year() == t_date.date().year()) && (d.date().month() == t_date.date().month()));

        };
        /*if(t_type == days && t_date == i.data().toDateTime()){};
        if(t_type == noaa && t_date.daysTo(i.data().toDateTime()) == 0){};
        if(t_type == month && t_date.date().month() == i.data().toDateTime().date().month()){};*/
        if(specialBackground){
            return QColor(Qt::green);
        };
    };

    return QSqlTableModel::data(index, role);
}
