#pragma once

//#include <QWidget>
//#include "ui_Add_Path.h"
//#pragma once
#include "Graph.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QSpinBox>
#include <QString>

class Add_Path : public QWidget
{
    Q_OBJECT

public:
    Add_Path(Graph* graph, QWidget* parent = nullptr);
    void Add_Path_pressed();
    void Delete_Path_pressed();
    void Add_Country_pressed();
    void Delete_Country_pressed();
    void Update_Path_pressed();
    void Home_Button();

    ~Add_Path();

private slots:
private:
    QHBoxLayout* mainlayout;
    QVBoxLayout* settinglayout;
    QVBoxLayout* rightlayout;

    QPushButton* add_path;
    QPushButton* delet_path;
    QPushButton* update_path;
    QPushButton* add_country;
    QPushButton* delet_country;
    QPushButton* Home;
    QPushButton* add;

    QLabel* function;
    QLabel* country_from_label;
    QLabel* country_to_label;
    QLabel* travel_cost_label;
    QLabel* travel_way_label;

    QComboBox* travel_way_input;


    QGroupBox* datainfo;

    QFormLayout* forminfo;

    QComboBox* country_from_input;
    QComboBox* country_to_input;

    QSpinBox* travel_cost_input;

    Graph* GuideMe;
};
