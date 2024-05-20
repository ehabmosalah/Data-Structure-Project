#pragma once
#include <list>
#include <string>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QSpinBox>
#include <QMessagebox>
#include <QRadiobutton>
#include <qbuttongroup.h>
#include "Graph.h"

class TraverseWindow : public QWidget
{
private:
public:
    TraverseWindow(Graph* graph, QWidget* parent = nullptr);
    void traversePressed();
    void Home_Button();
    ~TraverseWindow();
    QHBoxLayout* mainlayout;
    QVBoxLayout* settinglayout;
    QVBoxLayout* rightlayout;

    QPushButton* Home;
    QPushButton* Traverse;

    QLabel* function;
    QLabel* your_country_label;

    QGroupBox* datainfo;

    QFormLayout* forminfo;

    QComboBox* your_country_input;

    QRadioButton* bfs;
    QRadioButton* dfs;
    QVBoxLayout* radioButtons;

    Graph* GuideMe;
};

