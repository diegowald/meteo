#ifndef BATCHASTROLOGICGRABDATA_H
#define BATCHASTROLOGICGRABDATA_H

#include <QWidget>
#include <QDateTime>
#include <QList>
#include <QtSql>
#include <QMessageBox>
#include <QProcess>
#include <astroinfo.h>
#include <QClipboard>

namespace Ui {
    class batchAstrologicGrabData;
}

class batchAstrologicGrabData : public QWidget
{
    Q_OBJECT

public:
    explicit batchAstrologicGrabData(QWidget *parent = 0);
    ~batchAstrologicGrabData();

public slots:
    void    loadFechas();
    void    saveData();
    void    next();

    /*get data*/
    void    clipboardChanged();

    void    parseData();
    void    log(QString msg);

private:
    Ui::batchAstrologicGrabData *ui;
    QList<QDateTime> fechas;
    QList<QString> tipos;
    QProcess*           starFisher;
    QProcess*           starFisherParser;
    QString         currentType;
    QDateTime       currentDate;
    astroInfo       information;


    void    parseAspectarium(QString basedata);
    void    parseBasicInfo(QString basedata);
    void    saveSignLine(int x, int y, QString data, QFile* file = 0);
    void    saveHouseLine(int x, int y, QString data, QFile* file = 0);
    void    saveQuadrantLine(int x, int y, QString data, QFile* file = 0);
    void    savePositionLine(int x, int y, QString data, QFile* file = 0);
    void    savePosition2Line(int x, int y, QString data, QFile* file = 0);
    //void    parse

    QList<int>      getPlanetaNumber(QString data);
    int     getHoroscopeNumber(QString data);

    QClipboard      *clipboard;
    QFile           *file;

    QString         trstring;
    QString         htmlstring;
    QString         basicinfostring;
};

#endif // BATCHASTROLOGICGRABDATA_H
