#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QMdiSubWindow>
#include <QDir>
#include <QFile>
#include <QProgressDialog>
#include <QTime>
#include "astroinfo.h"
#include "batchprocesswidget.h"
#include "optionswidget.h"
#include "fileloadwidget.h"
#include "sweph.h"
#include "version.h"
#include "excelexportwidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void    connectToDatabase();
    static MainWindow* instance();
    QDateTime   getWorkingDate(){ return date; }
    excelExportWidget*  getExcelExport(){ return excel; }

public slots:
    void    setWorkingDate(QDateTime val){ date = val; }
    void    workingDate();

    void    cargaDeDia();
    void    cargaDeSizigia();
    void    modifyData();
    void    browseTables();
    void    browseMonth();
    void    showOptions();
    void    loadTPSData();
    void    loadSQLiteData();
    void    loadRDBData();
    void    weatherToNOAA();
    void    refreshFromRBD();
    void    refreshWeather();

    //void    processData();
    void    processByWeather();
    void    processByAspects();
    void    processByCycles();
    void    processByDignity();
    void    processByMonthRain();
    void    showDays();
    void    showSizigias();
    void    showExcel();

    void    recalcMothlyValues();
    void    calcPrimordialPoints();

    void    batchProcessor();
    void    fileProcessor();
    void    showForm(QWidget *form, bool modal = false);

    //void    doBatch();

private:    
    Ui::MainWindow *ui;
    excelExportWidget *excel;
    QSqlDatabase db;
    static MainWindow* mahself;
    QDateTime   date;
};

#endif // MAINWINDOW_H
