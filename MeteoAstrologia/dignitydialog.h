#ifndef DIGNITYDIALOG_H
#define DIGNITYDIALOG_H

#include <QDialog>
#include "dataprocessor.h"

namespace Ui {
class dignityDialog;
}

class dignityDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit dignityDialog(QWidget *parent = 0);
    ~dignityDialog();

signals:
    void    addDignity(metAstro::dignityParam & param);
public slots:
    void    accepted();
private:
    Ui::dignityDialog *ui;
};

#endif // DIGNITYDIALOG_H
