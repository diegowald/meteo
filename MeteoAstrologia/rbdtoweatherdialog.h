#ifndef RBDTOWEATHERDIALOG_H
#define RBDTOWEATHERDIALOG_H

#include <QDialog>
#include <QProgressDialog>
#include <QtSql>

namespace Ui {
class RBDtoWeatherDialog;
}

class RBDtoWeatherDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit RBDtoWeatherDialog(QWidget *parent = 0);
    ~RBDtoWeatherDialog();

public slots:
    void    doCalc();
    
private:
    Ui::RBDtoWeatherDialog *ui;
    void    processDay(QDateTime date);
};

#endif // RBDTOWEATHERDIALOG_H
