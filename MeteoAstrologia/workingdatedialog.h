#ifndef WORKINGDATEDIALOG_H
#define WORKINGDATEDIALOG_H

#include <QDialog>
#include <QDateTime>
#include "mainwindow.h"

namespace Ui {
class workingDateDialog;
}

class workingDateDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit workingDateDialog(QWidget *parent = 0);
    ~workingDateDialog();
    
public slots:
    void    accepted();

signals:
    void    dateSubmited(QDateTime val);
private:
    Ui::workingDateDialog *ui;
};

#endif // WORKINGDATEDIALOG_H
