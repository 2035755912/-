#include "widget.h"
#include<config.h>
#include <QApplication>
#include<QResource>
#include<QIcon>
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
