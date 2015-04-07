#ifndef EXCELEXPORTWIDGET_H
#define EXCELEXPORTWIDGET_H

#include <QWidget>
#include <QtSql>
#include <QDateTime>
#include <QDateTimeEdit>
#include <ActiveQt/QAxObject>
#include <QProgressDialog>

namespace Ui {
    class excelExportWidget;
}

class excelExportWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit excelExportWidget(QWidget *parent = 0);
    ~excelExportWidget();

public slots:
    void    addDateTime(QDateTime* date){ dateList << date; refreshList(); }
    void    addDate(QDate& date){ dateList << new QDateTime(date); refreshList(); }
    void    del();
    void    add();
    void    added();
    void    cancel();
    void    refreshList();
    void    filter();
    void    excelExport();
    
private:
    Ui::excelExportWidget *ui;

    QList<QDateTime*> dateList;
};

#endif // EXCELEXPORTWIDGET_H
