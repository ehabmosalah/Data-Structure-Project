#include <QtWidgets/QApplication>
#include <iostream>
#include "Graph.h"
#include "MainWindow.h"
#include "Add_Path.h"
#include "Delete_Path.h"
#include "Update_Path.h"
#include "getPathsWindow.h"
#include "Add_Country.h"
#include "Delete_Country.h"
#include "TraverseWindow.h"


using namespace std;
#define FREE_PALESTINE            \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);


int main(int argc, char* argv[])
{
    //  FREE_PALESTINE

    /*  QApplication app(argc, argv);
      Guide_Me mainWidget;
      mainWidget.show();
      return app.exec();*/
    Graph* graph=new Graph;

    QApplication app(argc, argv);
    //Guide_Me mainWidget;
    //Add_Path mainWidget(graph);
    //Delete_Country mainWidget(graph);
     //Delete_Path mainWidget(graph);
    //Update_Path mainWidget(graph);
    MainWindow mainWidget(graph);
    mainWidget.show();
   // int exe = app.exec();
   // if (exe == 0) delete graph;
    return app.exec();
}
