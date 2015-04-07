#include "filedownloader.h"

FileDownloader::FileDownloader(QUrl url, QObject *parent) : QObject(parent)
{
    connect(&webCtrl, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(fileDownloaded(QNetworkReply*)));

    QNetworkRequest request(url);
    webCtrl.get(request);
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

    emit downloaded(reply->url().fileName());
}

QByteArray FileDownloader::downloadedData() const
{
    return _downloadedData;
}
