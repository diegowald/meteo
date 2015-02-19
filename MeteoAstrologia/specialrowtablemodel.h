#ifndef SPECIALROWTABLEMODEL_H
#define SPECIALROWTABLEMODEL_H

#include <QSqlTableModel>
#include <QDateTime>
#include <QDebug>

class specialRowTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    enum modelType{days, noaa, month};
    explicit specialRowTableModel(QDateTime d, modelType t, QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    inline QDateTime getDateTime() const{ return t_date; }
    inline modelType getModelType() const{ return t_type; }
    
signals:
    
public slots:
    void    setDateTime(QDateTime v){ t_date = v; }
    void    setType(modelType t){ t_type = t; }

private:
    QDateTime t_date;
    modelType t_type;
};

#endif // SPECIALROWTABLEMODEL_H
