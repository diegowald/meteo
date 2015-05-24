#ifndef SIZIGIAEXCELREPORTWIDGET_H
#define SIZIGIAEXCELREPORTWIDGET_H

#include <QWidget>
#include <ActiveQt/QAxObject>
#include <QProgressDialog>
#include <QtSql>

namespace Ui {
class sizigiaExcelReportWidget;
}

class sizigiaExcelReportWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit sizigiaExcelReportWidget(QWidget *parent = 0);
    ~sizigiaExcelReportWidget();
    static int  moonTolerance;
    static int  sunTolerance;

private:
    QString usaf() const;

public slots:
    void    test();
    void    exportToExcel();
    void    filter();

    void    typeChange(QString value);
    
private:
    Ui::sizigiaExcelReportWidget *ui;
    QSqlQueryModel *fechaTable;
};

#endif // SIZIGIAEXCELREPORTWIDGET_H
