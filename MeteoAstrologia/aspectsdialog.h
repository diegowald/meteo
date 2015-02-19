#ifndef ASPECTSDIALOG_H
#define ASPECTSDIALOG_H

#include <QDialog>
#include <QList>
#include "dataprocessor.h"

namespace Ui {
    class aspectsDialog;
}

class aspectsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit aspectsDialog(metAstro::aspectParameter *aspect = 0, bool modif = false, QWidget *parent = 0);
    ~aspectsDialog();

public slots:
    void    accepted();
    void    closed();

signals:
    void    aspectsAdd(metAstro::aspectParameter *aspect);
    void    aspectsMod(metAstro::aspectParameter *aspect);

private:
    void    loadAspect();
    Ui::aspectsDialog *ui;
    metAstro::aspectParameter *meinAspect;
    bool    isMod;
};

#endif // ASPECTSDIALOG_H
