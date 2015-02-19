#ifndef POSITIONSDIALOG_H
#define POSITIONSDIALOG_H

#include <QDialog>
#include "dataprocessor.h"

namespace Ui {
    class positionsDialog;
}

class positionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit positionsDialog(metAstro::positionParameter *param = 0, bool modif = false, QWidget *parent = 0);
    ~positionsDialog();

public slots:
    void    accepted();
    void    closed();

signals:
    void    positionAdded(metAstro::positionParameter *position);
    void    positionModded(metAstro::positionParameter *position);

private:
    void    loadData();
    bool    isMod;
    metAstro::positionParameter   *meinPosition;
    Ui::positionsDialog *ui;
};

#endif // POSITIONSDIALOG_H
