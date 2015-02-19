#ifndef WEATHERDIALOG_H
#define WEATHERDIALOG_H

#include <QDialog>
#include "dataprocessor.h"

namespace Ui {
    class weatherDialog;
}

class weatherDialog : public QDialog
{
    Q_OBJECT

public:
    explicit weatherDialog(metAstro::weatherParameter* weather = 0, bool isNOAA = false, QWidget *parent = 0);
    ~weatherDialog();

public slots:
    void    accepted();
    void    closed();
    void    typeChanged(QString val);

signals:
    void    weatherAdd(metAstro::weatherParameter *weather);
    void    weatherMod(metAstro::weatherParameter *weather);

private:
    void    loadWeather();
    bool    isMod;
    Ui::weatherDialog *ui;
    metAstro::weatherParameter    *meinWeather;
    bool    isNOAA;
};

#endif // WEATHERDIALOG_H
