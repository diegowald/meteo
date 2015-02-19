#ifndef FILELOADWIDGET_H
#define FILELOADWIDGET_H

#include <QWidget>
#include <QFile>
#include <QList>
#include <QFileDialog>
#include <QProgressBar>
#include <QDebug>
#include <QtSql>

namespace Ui {
class fileLoadWidget;
}

class fileLoadWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit fileLoadWidget(QWidget *parent = 0);
    ~fileLoadWidget();
public slots:
    void    addFiles();
    void    removeFiles();
    void    processFiles();
    void    refresh();

private:
    bool    processDiaryWeather(QString filename);
    bool    processNinoMonthly(QString filename);
    bool    processDiarySunspots(QString filename);
    bool    processMonthlySunspots(QString filename);

    Ui::fileLoadWidget *ui;

    QList<QString> filenames;
    QList<int> fileprogress;
};

#endif // FILELOADWIDGET_H
