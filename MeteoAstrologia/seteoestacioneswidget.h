#ifndef SETEOESTACIONESWIDGET_H
#define SETEOESTACIONESWIDGET_H

#include <QWidget>
#include "filedownloader.h"

namespace Ui {
class SeteoEstacionesWidget;
}

class SeteoEstacionesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SeteoEstacionesWidget(QWidget *parent = 0);
    ~SeteoEstacionesWidget();

private slots:
    void on_btnRefresh_released();
    void fileDownloaded(const QString &filename);

    void on_btnSave_released();

private:
    void  processEstaciones(const QString &filename);
    void llenarListadoConEstaciones();
private:
    Ui::SeteoEstacionesWidget *ui;
    FileDownloader *_fileDownloader;
};

#endif // SETEOESTACIONESWIDGET_H
