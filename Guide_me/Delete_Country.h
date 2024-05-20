
#pragma once

#include <QWidget>
#include "Graph.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QSpinBox>

class Delete_Country : public QWidget
{
    Q_OBJECT

public:
    Delete_Country(Graph* graph, QWidget* parent = nullptr);
    ~Delete_Country();
    void Add_Path_pressed();
    void Delete_Path_pressed();
    void Add_Country_pressed();
    void Delete_Country_pressed();
    void Update_Path_pressed();
    void Home_Button();

private:
    // Ui::Delete_CountryClass ui;
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



    QGroupBox* datainfo;

    QFormLayout* forminfo;

    QComboBox* country_input;

    Graph* GuideMe;

};