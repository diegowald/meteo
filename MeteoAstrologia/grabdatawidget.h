#ifndef GRABDATAWIDGET_H
#define GRABDATAWIDGET_H

#include <QWidget>
#include <QProcess>
#include <QSettings>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QtSql>
#include "astroinfo.h"
#include "dataselectionwidget.h"

namespace Ui {
    class grabDataWidget;
}

class grabDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit grabDataWidget(bool isSizigia = false, QWidget *parent = 0);
    ~grabDataWidget();
public slots:
    void    saveData2();
    void    saveData();
    void    addSatelmecData();
    void    addStarFisherData();
    void    calculateAstro();

private:
    Ui::grabDataWidget *ui;
    bool                sizigia;
    QProcess*           starFisher;
    QProcess*           starFisherParser;
    QList<QStringList> *wheaterData;
    astroInfo           information;
};

#endif // GRABDATAWIDGET_H
