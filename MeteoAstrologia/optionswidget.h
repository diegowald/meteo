#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include <QWidget>
#include <QSettings>
#include <QFile>
#include <QFileDialog>

namespace Ui {
    class optionsWidget;
}

class optionsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit optionsWidget(QWidget *parent = 0);
    ~optionsWidget();
public slots:
    void    accept();

    void    searchForSFD();
    void    searchForRBD();
    void    searchForSF();

    QString searchForFile(QString kind);

private:
    Ui::optionsWidget *ui;
    QSettings       *sets;
};

#endif // OPTIONSWIDGET_H
