/** Program 0.1 - Suiyi-Poster */
#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <QTextCodec>
#include "poster.h"


#ifndef cout
//标准输入和标准输出
QTextStream cout(stdout);
#endif

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Poster* poster;
    QUrl *url = NULL;
    QByteArray *contents = NULL;


    // 字符集
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));


    /** 如果少于三个参数(即没带任何参数或参数不够) */
    if( (QString(argv[1]) != "-h" && QString(argv[1]) != "--help") && argc < 3 )
    {
        cout<<"用法: suiyi-post-cmd <URL> <需POST的内容>"<<endl<<endl;
        return 0;
    }

    /** 请求帮助信息 */
    if ( QString(argv[1]) == "-h" || QString(argv[1]) == "--help" )
    {
        // 输出帮助信息
        cout<<"用法: suiyi-post-cmd <URL> <要POST的内容>"<<endl;
        return 0;
    }

    url = new QUrl( QString(argv[1]) );
    contents = new QByteArray( argv[2] );

    poster = new Poster( *url , *contents );

    poster->post();

    return a.exec();
}


