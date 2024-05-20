#include "Add_Path.h"
#include "Delete_Path.h"
#include "Add_Country.h"
#include "Delete_Country.h"
#include "Update_Path.h"
#include "MainWindow.h"
#include <qmessagebox.h>


Delete_Country::Delete_Country(Graph* graph, QWidget* parent) : QWidget(parent)
{
    GuideMe = graph;

    QPixmap bkgnd("backGround.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    GuideMe = graph;
    setWindowTitle("Delete Country");
    setFixedSize(1540, 790);
    move(0, 0);

    mainlayout = new QHBoxLayout();
    setLayout(mainlayout);

    settinglayout = new QVBoxLayout();
    settinglayout->setSpacing(5);

    // Buttons 
    add_path = new QPushButton("Add Path");
    delet_path = new QPushButton("Delete Path");
    update_path = new QPushButton("Update Path");
    add_country = new QPushButton("Add Country");
    delet_country = new QPushButton("Delete Country");
    Home = new QPushButton("Home");

    // Button Style
    QString buttonStyle = "QPushButton {"
        "background-color: transparent;"
        "border: 2px solid #007bff;"
        "color: #007bff;"
        "padding: 8px 16px;"
        "font-size: 20px;"
        "border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "background-color: #007bff;"
        "color: #ffffff;"
        "}";
    // Back Button Style
    QString BackButtonStyle = "QPushButton {"
        "background-color: #dc3545;" // Bootstrap danger color
        "border: 2px solid #dc3545;" // Bootstrap danger color for border
        "color: #ffffff;"
        "padding: 8px 16px;"
        "font-size: 14px;"
        "border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "background-color: #c82333;" // Darken the color on hover
        "border-color: #c82333;" // Darken the border color on hover
        "}";

    QString spcialButton = "QPushButton {"
        "background-color: #0056b3;" // Set initial background color to a slightly darker blue
        "border: 2px solid #0056b3;"
        "color: #ffffff;" // Set text color to white
        "padding: 8px 16px;"
        "font-size: 20px;"
        "border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "background-color: #004080;" // Darken the background color slightly on hover
        "}";

    QString currentButton = "QPushButton {"
        "background-color: #007bff;" // Set background color to blue
        "border: 2px solid #007bff;"
        "color: #ffffff;" // Set text color to white
        "padding: 8px 16px;"
        "font-size: 20px;"
        "border-radius: 4px;"
        "}";

    add_path->setStyleSheet(buttonStyle);
    delet_path->setStyleSheet(buttonStyle);
    update_path->setStyleSheet(buttonStyle);
    add_country->setStyleSheet(buttonStyle);
    delet_country->setStyleSheet(currentButton);
    Home->setStyleSheet(BackButtonStyle);


    add_path->setFixedWidth(200);
    delet_path->setFixedWidth(200);
    update_path->setFixedWidth(200);
    add_country->setFixedWidth(200);
    delet_country->setFixedWidth(200);
    delet_country->setFixedWidth(200);
    Home->setFixedWidth(200);

    settinglayout->addWidget(add_path);
    settinglayout->addWidget(delet_path);
    settinglayout->addWidget(update_path);
    settinglayout->addWidget(add_country);
    settinglayout->addWidget(delet_country);
    settinglayout->addWidget(Home);
    mainlayout->addLayout(settinglayout);

    // the right layout 
    rightlayout = new QVBoxLayout();

    datainfo = new QGroupBox();
    datainfo->setTitle("Enter your Information ");

    function = new QLabel("Delete Your Country");
    //function->setAlignment(Qt::AlignCenter);
    function->setStyleSheet("color : white; font : bold 40px;");

    function->setFixedSize(400, 50); // Set a fixed size for the label

    rightlayout->addWidget(function);



    forminfo = new QFormLayout();
    forminfo->setVerticalSpacing(30);
    datainfo->setLayout(forminfo);
    rightlayout->addWidget(datainfo);

    // country delete 
    country_from_label = new QLabel("Country Want to Delete");
    country_input = new QComboBox();
    country_input->setFixedWidth(1000);
    country_input->setFixedWidth(1000);

    // call graph contries
    list<string> items = graph->allCountries();
    QStringList countries;
    for (const auto& item : items) {
        countries.append(QString::fromStdString(item));
    }
    country_input->addItems(countries);
    forminfo->addRow(country_from_label, country_input);



    // layout to center add button 
    QHBoxLayout* centeradd = new QHBoxLayout();

    // add pushbutton
    delet = new QPushButton("Delete");
    // Button style 
    delet->setStyleSheet(spcialButton);
    delet->setFixedHeight(50);
    delet->setFixedWidth(200);
    //add->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed); // Fixed height
    centeradd->addWidget(delet);

    rightlayout->addLayout(centeradd);

    mainlayout->addLayout(rightlayout);

    //buttons functions connection
    connect(add_path, &QPushButton::clicked, this, &Delete_Country::Add_Path_pressed);
    connect(delet, &QPushButton::clicked, this, &Delete_Country::Delete_Country_pressed);
    connect(update_path, &QPushButton::clicked, this, &Delete_Country::Update_Path_pressed);
    connect(delet_path, &QPushButton::clicked, this, &Delete_Country::Delete_Path_pressed);
    connect(add_country, &QPushButton::clicked, this, &Delete_Country::Add_Country_pressed);
    connect(Home, &QPushButton::clicked, this, &Delete_Country::Home_Button);

}
Delete_Country::~Delete_Country()
{
    delete mainlayout;
    delete settinglayout;
    delete rightlayout;
    delete add_path;
    delete delet_path;
    delete update_path;
    delete add_country;
    delete delet_country;
    delete Home;
    delete delet;
    delete function;
    delete country_from_label;
    delete datainfo;
    delete forminfo;
    delete country_input;
}

void Delete_Country::Add_Path_pressed()
{

    Add_Path* deletepathWindow = new  Add_Path(GuideMe);


    deletepathWindow->show();


    this->close();
}
void Delete_Country::Delete_Path_pressed()
{
    Delete_Path* deletepathWindow = new Delete_Path(GuideMe);
    deletepathWindow->show();
    this->close();
}

void Delete_Country::Delete_Country_pressed()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Confirmation", "Are you sure you want to perform this action?",
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
        return;
    else {

        GuideMe->deleteCountry((country_input->currentText()).toStdString());
    }

}

void Delete_Country::Add_Country_pressed()
{
    Add_Country* addcountryWindow = new Add_Country(GuideMe);
    addcountryWindow->show();
    this->close();
}


void Delete_Country::Update_Path_pressed()
{
    Update_Path* Update_PathWindow = new Update_Path(GuideMe);


    Update_PathWindow->show();


    this->close();
}

void Delete_Country::Home_Button()
{
    MainWindow* HomeWindow = new  MainWindow(GuideMe);
    HomeWindow->show();
    this->close();
}



