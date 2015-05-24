#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

class FileDownloader : public QObject
{
    Q_OBJECT
public:
    explicit FileDownloader(QUrl url, QObject *parent = 0);
    FileDownloader(int id, QUrl url, QObject *parent = 0);
    virtual ~FileDownloader();

    QByteArray downloadedData() const;
signals:
    void downloaded(const QString &file);
    void downloaded(int id, const QString &file);
    void downloadProgress(int id, qint64 bytes,qint64 total);

private slots:
    void fileDownloaded(QNetworkReply *reply);
    void onDownloadProgess(qint64 bytes,qint64 total);

private:
    QNetworkAccessManager webCtrl;
    QByteArray _downloadedData;
    QString filename;
    int _id;
};

#endif // FILEDOWNLOADER_H
