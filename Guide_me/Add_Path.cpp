#include "Add_Path.h"
#include "Delete_Path.h"
#include "Add_Country.h"
#include "Delete_Country.h"
#include "Update_Path.h"
#include "MainWindow.h"

Add_Path::Add_Path(Graph* graph, QWidget* parent) : QWidget(parent)
{
    GuideMe = graph;
    QPixmap bkgnd("backGround.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    setWindowTitle("Add Path");
    setFixedSize(1540, 790);
    move(0, 0);

    mainlayout = new QHBoxLayout();
    setLayout(mainlayout);

    settinglayout = new QVBoxLayout();
    settinglayout->setSpacing(5);
    // Button
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

    //Buttons style
    add_path->setStyleSheet(currentButton);
    delet_path->setStyleSheet(buttonStyle);
    update_path->setStyleSheet(buttonStyle);
    add_country->setStyleSheet(buttonStyle);
    delet_country->setStyleSheet(buttonStyle);
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

    function = new QLabel("Add Your Path");
    //function->setAlignment(Qt::AlignCenter);
    function->setStyleSheet("color : white; font : bold 50px;");
    function->setFixedSize(400, 50); // Set a fixed size for the label

    rightlayout->addWidget(function);



    forminfo = new QFormLayout();
    forminfo->setVerticalSpacing(30);
    datainfo->setLayout(forminfo);
    rightlayout->addWidget(datainfo);

    // country from 
    country_from_label = new QLabel("Country From");
    country_from_input = new QComboBox();
    // call graph contries
    list<string> items = graph->allCountries();
    QStringList countries;
    for (const auto& item : items) {
        countries.append(QString::fromStdString(item));
    }
    country_from_input->addItems(countries);
    forminfo->addRow(country_from_label, country_from_input);

    // country to 
    country_to_label = new QLabel("Country To");
    country_to_input = new QComboBox();
    country_to_input->addItems(countries);
    forminfo->addRow(country_to_label, country_to_input);

    // travelmethod way
    travel_way_label = new QLabel("The Way");
    travel_way_input = new QComboBox();
    travel_way_input->addItem("Car");
    travel_way_input->addItem("Bus");
    travel_way_input->addItem("Microbus");
    travel_way_input->addItem("Uber");
    travel_way_input->addItem("Plane");
    travel_way_input->addItem("Boat");
    travel_way_input->addItem("Metro");
    travel_way_input->addItem("Train");
    forminfo->addRow(travel_way_label, travel_way_input);

    // travelmethod cost
    travel_cost_label = new QLabel("The cost");
    travel_cost_input = new QSpinBox();
    travel_cost_input->setFixedWidth(1000);

    travel_cost_input->setMinimum(0);
    travel_cost_input->setMaximum(INT_MAX);
    forminfo->addRow(travel_cost_label, travel_cost_input);

    // layout to center add button 
    QHBoxLayout* centeradd = new QHBoxLayout();

    // add pushbutton
    add = new QPushButton("Add");
    //add->setFixedSize(100, 30);
    add->setStyleSheet(spcialButton);
    add->setFixedHeight(50);
    add->setFixedWidth(200);
    //add->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed); // Fixed height
    centeradd->addWidget(add);
    rightlayout->addLayout(centeradd);



    mainlayout->addLayout(rightlayout);


    connect(add, &QPushButton::clicked, this, &Add_Path::Add_Path_pressed);
    connect(delet_path, &QPushButton::clicked, this, &Add_Path::Delete_Path_pressed);
    connect(delet_country, &QPushButton::clicked, this, &Add_Path::Delete_Country_pressed);
    connect(update_path, &QPushButton::clicked, this, &Add_Path::Update_Path_pressed);
    connect(add_country, &QPushButton::clicked, this, &Add_Path::Add_Country_pressed);
    connect(Home, &QPushButton::clicked, this, &Add_Path::Home_Button);

}

void Add_Path::Add_Path_pressed()
{
    string country1 = country_from_input->currentText().toStdString();
    string country2 = country_to_input->currentText().toStdString();
    string methodName = travel_way_input->currentText().toStdString();
    int cost = travel_cost_input->value();
    GuideMe->addPath(country1, country2, methodName, cost);
    QMessageBox messBox;
    messBox.setText("Added Successfully.\t");
    messBox.show();
}

void Add_Path::Delete_Path_pressed()
{
    Delete_Path* deletepathWindow = new Delete_Path(GuideMe);
    deletepathWindow->show();
    this->close();
}

void Add_Path::Add_Country_pressed()
{
    Add_Country* addcountryWindow = new Add_Country(GuideMe);
    addcountryWindow->show();
    this->close();
}

void Add_Path::Delete_Country_pressed()
{
    Delete_Country* Delete_CountryWindow = new Delete_Country(GuideMe);
    Delete_CountryWindow->show();
    this->close();
}

void Add_Path::Update_Path_pressed()
{
    Update_Path* Update_PathWindow = new Update_Path(GuideMe);
    Update_PathWindow->show();
    this->close();
}

void Add_Path::Home_Button()
{
    MainWindow* HomeWindow = new  MainWindow(GuideMe);
    HomeWindow->show();
    this->close();
}
Add_Path::~Add_Path()
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
    delete add;
    delete function;
    delete country_from_label;
    delete country_to_label;
    delete travel_cost_label;
    delete travel_way_label;
    delete datainfo;
    delete forminfo;
    delete country_from_input;
    delete country_to_input;
    delete travel_cost_input;

}
