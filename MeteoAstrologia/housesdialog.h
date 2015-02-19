#ifndef HOUSESDIALOG_H
#define HOUSESDIALOG_H

#include <QDialog>
#include "dataprocessor.h"

namespace Ui {
    class housesDialog;
}

class housesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit housesDialog(metAstro::housesParameter *house = 0, QWidget *parent = 0);
    ~housesDialog();

public slots:
    void    accepted();
    void    closed();

signals:
    void    housesAdded(metAstro::housesParameter *param);
    void    housesModded(metAstro::housesParameter *param);

private:
    void    loadData();
    bool    isMod;
    metAstro::housesParameter *meinHouse;
    Ui::housesDialog *ui;
};

#endif // HOUSESDIALOG_H
