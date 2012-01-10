#ifndef POSTER_H
#define POSTER_H

#include <QtCore/QCoreApplication>
#include <QtNetwork>

class Poster : public QObject
{
    Q_OBJECT

    QUrl url;
    QByteArray content;
    QNetworkAccessManager *manager;
    QNetworkReply* reply;

public slots:
    void readyread();

public:
    Poster(QUrl URL, QByteArray content_to_post);

    void post();
    
};

#endif // POSTER_H
