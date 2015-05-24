#include "filedownloader.h"

FileDownloader::FileDownloader(QUrl url, QObject *parent) : QObject(parent)
{
    connect(&webCtrl, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(fileDownloaded(QNetworkReply*)));

    QNetworkRequest request(url);

    QNetworkReply *reply = webCtrl.get(request);
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(onDownloadProgess(qint64,qint64)));
    _id = -1;
}

FileDownloader::FileDownloader(int id, QUrl url, QObject *parent) : QObject(parent)
{
    connect(&webCtrl, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(fileDownloaded(QNetworkReply*)));

    QNetworkRequest request(url);

    QNetworkReply *reply = webCtrl.get(request);
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(onDownloadProgess(qint64,qint64)));
    _id = id;
}

FileDownloader::~FileDownloader()
{

}

void FileDownloader::fileDownloaded(QNetworkReply *reply)
{
    qDebug() << reply->errorString();

    if(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 307 || reply->rawHeaderList().contains("Location"))
    {
        qDebug() << reply->header(QNetworkRequest::LocationHeader).toString();
        QNetworkRequest req(reply->header(QNetworkRequest::LocationHeader).toString());
        webCtrl.get(req);
        return;
    }
    _downloadedData = reply->readAll();
    reply->deleteLater();

    if (_id != -1)
    {
        emit downloaded(_id, reply->url().fileName());
    }
    else
    {
        emit downloaded(reply->url().fileName());
    }
}

QByteArray FileDownloader::downloadedData() const
{
    return _downloadedData;
}

void FileDownloader::onDownloadProgess(qint64 bytes, qint64 total)
{
    emit downloadProgress(_id, bytes, total);
}
