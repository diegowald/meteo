#ifndef BROWSETABLEWIDGET_H
#define BROWSETABLEWIDGET_H

#include <QWidget>
#include <QtSql>
#include "mainwindow.h"

namespace Ui {
    class browseTableWidget;
}

class browseTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit browseTableWidget(QWidget *parent = 0);
    ~browseTableWidget();
public slots:
    void    changeType();
    void    changeTable(int table);
    void    fechaChange(QString date);

private:
    QString usaf() const;

private:
    Ui::browseTableWidget *ui;
    //QSqlTableModel *comboModel;
    QSqlTableModel *model;
    QSqlQueryModel *fechaModel;
};

#endif // BROWSETABLEWIDGET_H
