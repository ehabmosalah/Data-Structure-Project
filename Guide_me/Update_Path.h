#pragma once

//#include <QWidget>
//#include "ui_Update_Path.h"

//#include "ui_Update_Path.h"
#include "Graph.h"
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

class Update_Path : public QWidget
{
    Q_OBJECT

public:
    Update_Path(Graph* graph, QWidget* parent = nullptr);
    void Add_Path_pressed();
    void Delete_Path_pressed();
    void Update_Path_pressed();
    void Add_Country_pressed();
    void Delete_Country_pressed();
    void Home_Button();

    ~Update_Path();

private slots:

private:
    //Ui::Update_PathClass ui;
    QHBoxLayout* mainlayout;
    QVBoxLayout* settinglayout;
    QVBoxLayout* rightlayout;

    QPushButton* add_path;
    QPushButton* delet_path;
    QPushButton* update_path;
    QPushButton* add_country;
    QPushButton* delet_country;
    QPushButton* Home;
    QPushButton* update;

    QLabel* function;
    QLabel* country_from_label;
    QLabel* country_to_label;
    QLabel* old_method_label;
    QLabel* new_method_label;
    QLabel* method_cost_label;

    QComboBox* old_method_way;
    QComboBox* new_method_way;


    QGroupBox* datainfo;

    QFormLayout* forminfo;

    QComboBox* country_from_input;
    QComboBox* country_to_input;

    QSpinBox* method_cost_input;
    Graph* GuideMe;
};


