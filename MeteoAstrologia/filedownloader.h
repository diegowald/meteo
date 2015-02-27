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
    virtual ~FileDownloader();

    QByteArray downloadedData() const;
signals:
    void downloaded();

private slots:
    void fileDownloaded(QNetworkReply *reply);

private:
    QNetworkAccessManager webCtrl;
    QByteArray _downloadedData;
};

#endif // FILEDOWNLOADER_H
