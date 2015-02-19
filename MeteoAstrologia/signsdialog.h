#ifndef SIGNSDIALOG_H
#define SIGNSDIALOG_H

#include <QDialog>
#include "dataprocessor.h"

namespace Ui {
    class signsDialog;
}

class signsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit signsDialog(metAstro::signsParameter *param = 0, QWidget *parent = 0);
    ~signsDialog();

public slots:
    void    accepted();
    void    closed();

signals:
    void    signsAdded(metAstro::signsParameter *sign);
    void    signsModded(metAstro::signsParameter *sign);
private:
    void    loadData();
    bool    isMod;
    metAstro::signsParameter  *meinSign;
    Ui::signsDialog *ui;
};

#endif // SIGNSDIALOG_H
