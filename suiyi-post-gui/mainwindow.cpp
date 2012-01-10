#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include <QtNetwork/QNetworkRequest>
#include "global.h"

void MainWindow::post()
{
    QByteArray content( ui->leData->text().toAscii().constData() );
    int length = content.length();
    QUrl url( ui->leUrl->text() );
    QNetworkRequest request;

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, length);
    reply = manager->post(request, content);

    ui->btnPost->setText("POSTING..");

    connect(reply, SIGNAL(finished()), this, SLOT(readyread()));
}

void MainWindow::readyread()
{
    ui->tbResult->setText( QString::fromUtf8( reply->readAll() ) );
    ui->btnPost->setText("POST!!");
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

    ui->leUrl->setText( QString("http://jybox.net/cs.php?get=1") );
    ui->leData->setText( QString("post=1&data=test") );
    ui->btnPost->setText( QString("POST!!") );
    ui->tbResult->setText( QString::fromUtf8("<返回数据会显示在这里>") );

    connect(ui->btnPost, SIGNAL(clicked()), this, SLOT(post()));

    manager = new QNetworkAccessManager(this);
    if(!manager)
    {
        exit(0);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    DELETE(manager);
    DELETE(reply);
}
