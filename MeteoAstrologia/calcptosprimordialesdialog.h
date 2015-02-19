#ifndef CALCPTOSPRIMORDIALESDIALOG_H
#define CALCPTOSPRIMORDIALESDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QProgressDialog>

namespace Ui {
class calcPtosPrimordialesDialog;
}

class calcPtosPrimordialesDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit calcPtosPrimordialesDialog(QWidget *parent = 0);
    ~calcPtosPrimordialesDialog();
    
public slots:
    void    doCalc();

private:
    Ui::calcPtosPrimordialesDialog *ui;
};

#endif // CALCPTOSPRIMORDIALESDIALOG_H
