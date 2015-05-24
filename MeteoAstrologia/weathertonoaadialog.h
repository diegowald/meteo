#ifndef WEATHERTONOAADIALOG_H
#define WEATHERTONOAADIALOG_H

#include <QDialog>
#include <QProgressDialog>
#include <QtSql>

namespace Ui {
class weatherToNoaaDialog;
}

class weatherToNoaaDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit weatherToNoaaDialog(QWidget *parent = 0);
    ~weatherToNoaaDialog();
public slots:
    void    doCalc();

private:
    QString usaf() const;
private:
    Ui::weatherToNoaaDialog *ui;
    void    processDay(QDateTime date);
};

#endif // WEATHERTONOAADIALOG_H
