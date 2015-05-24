#ifndef AUTOMATICDOWNLOADERWIDGET_H
#define AUTOMATICDOWNLOADERWIDGET_H

#include <QWidget>
#include <QMap>
#include "filedownloader.h"

namespace Ui {
class AutomaticDownloaderWidget;
}

class AutomaticDownloaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AutomaticDownloaderWidget(QWidget *parent = 0);
    ~AutomaticDownloaderWidget();

private slots:
    void on_btnDescargar_released();
    void downloading(int id, qint64 bytes, qint64 total);
    void downloaded(int id, QString file);

private:
    void processFiles();
    bool processDiaryWeather(const QString &filename);
    bool processNinoMonthly(const QString &filename);
    bool processDiarySunspots(const QString &filename);
    bool processMonthlySunspots(const QString &filename);

    void obtenerEstaciones();
    void generarListadoArchivosADescargar();
    void addFile(const QString &filename, const QString &url, const QString &filetype);

    void doDownload();
    void updateDownloadQueue();
private:
    Ui::AutomaticDownloaderWidget *ui;
    QStringList _estaciones;
    QMap<int, QString> _downloadQueue;
    QMap<int, FileDownloader*> _downloaderQueue;
};

#endif // AUTOMATICDOWNLOADERWIDGET_H
