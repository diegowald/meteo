#ifndef PROCESSBYASPECTWIDGET_H
#define PROCESSBYASPECTWIDGET_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>
#include <QProgressDialog>
#include <QList>
#include "dataprocessor.h"
#include "aspectsdialog.h"
#include "utils.h"
#include <QMenu>

namespace Ui {
class processByAspectWidget;
}

class processByAspectWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit processByAspectWidget(QWidget *parent = 0);
    ~processByAspectWidget();
    
public slots:
    void    add();
    void    del();

    void    aspectsAdded(metAstro::aspectParameter *asp);

    void    refreshAspects();
    void    refreshResult();
    void    doCalc();

    void    daysMenu(QPoint val);
    void    noaaMenu(QPoint val);


private:
    Ui::processByAspectWidget *ui;

    QList<metAstro::aspectParameter> aspects;
    QList<QDate> datesList;
    QSqlTableModel *astroModel, *dairyModel, *signModel;

    dataProcessor *information;
};

#endif // PROCESSBYASPECTWIDGET_H
