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
#include "Graph.h"

class getPathsWindow : public QWidget
{
    Q_OBJECT
private:
public:
    void getPressed();
    void Home_Button();
    ~getPathsWindow();
    getPathsWindow(Graph* graph, QWidget* parent = nullptr);
    QHBoxLayout* mainlayout;
    QVBoxLayout* settinglayout;
    QVBoxLayout* rightlayout;

    QPushButton* Home;
    QPushButton* get;

    QLabel* function;
    QLabel* country_from_label;
    QLabel* country_to_label;
    QLabel* cost_label;

    QGroupBox* datainfo;

    QFormLayout* forminfo;

    QComboBox* country_from_input;
    QComboBox* country_to_input;
    QSpinBox* cost_input;
    Graph* GuideMe;
};

