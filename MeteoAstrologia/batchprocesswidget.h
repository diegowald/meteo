#ifndef BATCHPROCESSWIDGET_H
#define BATCHPROCESSWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QtSql>
#include <astroinfo.h>
#include <utils.h>

namespace Ui {
    class BatchProcessWidget;
}

class BatchProcessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BatchProcessWidget(QWidget *parent = 0);
    ~BatchProcessWidget();

public slots:
    void    doCalc();

private:
    void    saveCurrentWeather(QDateTime date);
    void    saveCurrentAstrology(QDateTime date);
    void    saveCurrent();
    Ui::BatchProcessWidget *ui;
    astroInfo               information;
    QSqlDatabase db;
};

#endif // BATCHPROCESSWIDGET_H
