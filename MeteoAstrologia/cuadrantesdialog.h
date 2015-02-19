#ifndef CUADRANTESDIALOG_H
#define CUADRANTESDIALOG_H

#include <QDialog>
#include "dataprocessor.h"

namespace Ui {
    class cuadrantesDialog;
}

class cuadrantesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit cuadrantesDialog(metAstro::cuadrantesParameter *cuadrante = 0, QWidget *parent = 0);
    ~cuadrantesDialog();

public slots:
    void    accepted();
    void    closed();
signals:
    void    cuadranteAdded(metAstro::cuadrantesParameter *param);
    void    cuadranteModded(metAstro::cuadrantesParameter *param);
private:
    void    loadData();
    bool    isMod;
    metAstro::cuadrantesParameter *meinCuadrante;
    Ui::cuadrantesDialog *ui;
};

#endif // CUADRANTESDIALOG_H
