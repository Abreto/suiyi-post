/** Poster 类的实现 */
#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <QTextCodec>
#include "poster.h"

extern QTextStream cout;


void Poster::readyread()
{
    cout<<(QString::fromUtf8(reply->readAll()))<<endl;
    exit(0);
}

Poster::Poster(QUrl URL, QByteArray content_to_post)
{
    url = URL;
    content = content_to_post;
}

void Poster::post()
{
    int length = content.length();
    QNetworkRequest request;
    manager = new QNetworkAccessManager( this );

    request.setUrl( url );
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, length);
    reply = manager->post( request, content );

    connect(reply, SIGNAL(finished()), this, SLOT(readyread()));
}
