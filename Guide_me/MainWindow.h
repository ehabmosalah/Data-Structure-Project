#pragma once
//#include "ui_GuideMe.h"
#include <QtWidgets/QApplication>
#include<qlabel.h>
#include<qbuttongroup.h>
#include <iostream>
#include "Graph.h"
#include<qpushbutton.h>
#include<qpixmap.h>
#include <QVBoxLayout>
#include<qgridlayout.h>
//#include"Options.h"
#include"TraverseWindow.h"
#include"Graph.h"
class MainWindow :public QWidget
{
private:
    QLabel* Title;
    QPushButton* options;
    QPushButton* TraverseButton;
    QPushButton* GraphInfoButton;
    QPushButton* GetPathsButton;
    QPushButton* Exit;
    Graph* GuideMe;
public:
    MainWindow(Graph* GuideMe);
    void onExitClicked();
    void onGraphInfoButtonClicked();
    void onTraverseButtonClicked();
    void onGetPathsButtonClicked();
    void onoptionsButtonClicked();
    ~MainWindow();
};