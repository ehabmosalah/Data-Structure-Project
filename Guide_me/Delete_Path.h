#pragma once

//#include <QWidget>
//#include "ui_Delete_Path.h"
#include <QWidget>
#include "Graph.h"
//#include "ui_Delete_Path.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QSpinBox>
class Delete_Path : public QWidget
{
    Q_OBJECT

public:
    Delete_Path(Graph* graph, QWidget* parent = nullptr);
    void Add_Path_pressed();
    void Home_Button();
    void Delete_Path_pressed();
    ~Delete_Path();
    void Add_Country_pressed();
    void Delete_Country_pressed();
    void Update_Path_pressed();
private:
    // Ui::Delete_PathClass ui;
    QHBoxLayout* mainlayout;
    QVBoxLayout* settinglayout;
    QVBoxLayout* rightlayout;

    QPushButton* add_path;
    QPushButton* delet_path;
    QPushButton* update_path;
    QPushButton* add_country;
    QPushButton* delet_country;
    QPushButton* Home;
    QPushButton* delet;

    QLabel* function;
    QLabel* country_from_label;
    QLabel* country_to_label;
    QLabel* method_way_label;

    QGroupBox* datainfo;

    QFormLayout* forminfo;

    QComboBox* country_from_input;
    QComboBox* country_to_input;

    QComboBox* method_way_input;
    Graph* GuideMe;
};