/** Program 0.1.0 - Suiyi-post GUI */
#include <QtGui/QApplication>
#include "mainwindow.h"
#include "global.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
