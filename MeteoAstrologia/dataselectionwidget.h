#ifndef DATASELECTIONWIDGET_H
#define DATASELECTIONWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QList>
#include <QStringList>
#include <QDate>

namespace Ui {
    class dataSelectionWidget;
}

class dataSelectionWidget : public QDialog
{
    Q_OBJECT

public:
    explicit dataSelectionWidget(QList<QStringList> *list, QWidget *parent = 0);
    QStringList getDataList(){ return returnList; }
    ~dataSelectionWidget();
public slots:
    void    select();

signals:
    void    dataSelected(QStringList l);
private:
    Ui::dataSelectionWidget *ui;
    QList<QStringList> *data;
    QStringList returnList;
};

#endif // DATASELECTIONWIDGET_H
