#ifndef MONTHCALCDIALOG_H
#define MONTHCALCDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QProgressDialog>

namespace Ui {
class monthCalcDialog;
}

class monthCalcDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit monthCalcDialog(QWidget *parent = 0);
    ~monthCalcDialog();
public slots:
    void        save();

private:
    Ui::monthCalcDialog *ui;
};

#endif // MONTHCALCDIALOG_H
