#pragma once
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
class MainWindow :public QWidget
{
private:
    QLabel* Title;
    QLabel* backgroundlabel;
    QPushButton* AddPathButton;
    QPushButton* UpdatePathButton;
    QPushButton* DeletePathButton;
    QPushButton* AddCountryButton;
    QPushButton* DeleteCountryButton;
    QPushButton* Graphvisualization;
    QPushButton* BFSButton;
    QPushButton* DFSButton;
    QPushButton* GetPathsButton;
    QPushButton* Exit;
public:
    MainWindow();
    void onExitClicked();
    void onAddPathButtonClicked();
    void onUpdatePathButtonClicked();
    void onDeletePathButtonClicked();
    void onAddCountryButtonClicked();
    void onDeleteCountryButtonClicked();
    void onGraphvisualizationClicked();
    void onBFSButtonClicked();
    void onDFSButtonClicked();
    void onGetPathsButtonClicked();
};

