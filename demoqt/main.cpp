#include "demoqt.h"
#include <QtWidgets/QApplication>
#include<qlabel.h>
#include<qbuttongroup.h>
#include <iostream>
#include "Graph.h"
#include<qpushbutton.h>
#include<qpixmap.h>
#include <QVBoxLayout>
#include<qgridlayout.h>
#include"MainWindow.h"
using namespace std;
#define FREE_PALESTINE            \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);



int main(int argc, char *argv[])
{
    FREE_PALESTINE
    QApplication app(argc, argv);
    MainWindow mainWidget;
    mainWidget.show();
    return app.exec();
}
