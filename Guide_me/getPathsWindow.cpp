#include "getPathsWindow.h"
#include "MainWindow.h"

getPathsWindow::getPathsWindow(Graph* graph, QWidget* parent) : QWidget(parent) {
    GuideMe = graph;
    setWindowTitle("Guide Me");
    setFixedSize(1540, 790);

    mainlayout = new QHBoxLayout();
    setLayout(mainlayout);

    function = new QLabel("Get All Routes");
    function->setAlignment(Qt::AlignCenter);
    function->setStyleSheet("color : white; font : bold 50px;");
    function->setFixedSize(400, 50); // Set a fixed size for the label

    datainfo = new QGroupBox();
    datainfo->setTitle("Enter your Information ");

    settinglayout = new QVBoxLayout();
    settinglayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

    //back button
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
    Home = new QPushButton("Home");
    settinglayout->addWidget(Home);
    mainlayout->addLayout(settinglayout);
    Home->setStyleSheet(BackButtonStyle);

    // the right layout 
    rightlayout = new QVBoxLayout();
    rightlayout->addWidget(function);

    forminfo = new QFormLayout();
    forminfo->setVerticalSpacing(30);
    datainfo->setLayout(forminfo);
    rightlayout->addWidget(datainfo);

    //get all countries
    QStringList countries;
    for (auto it : GuideMe->graph)
        countries.append(QString::fromStdString(it.first));

    // country from 
    country_from_label = new QLabel("Country From");
    country_from_input = new QComboBox();
    country_from_input->addItems(countries);
    forminfo->addRow(country_from_label, country_from_input);

    // country to 
    country_to_label = new QLabel("Country To");
    country_to_input = new QComboBox();
    country_to_input->addItems(countries);
    forminfo->addRow(country_to_label, country_to_input);

    //cost
    cost_label = new QLabel("Cost");
    cost_input = new QSpinBox();
    cost_input->setMinimum(0);
    cost_input->setMaximum(INT_MAX);
    cost_input->setValue(1000);
    forminfo->addRow(cost_label, cost_input);
    cost_input->setFixedWidth(800);
    cost_input->setValue(1000);

    // layout to center add button 
    QHBoxLayout* centeradd = new QHBoxLayout();

    // get Paths pushbutton
    QString buttonStyle = "QPushButton {"
        "background-color: #007bff;" // Set background color to blue
        "border: 2px solid #007bff;"
        "color: #ffffff;" // Set text color to white
        "padding: 8px 16px;"
        "font-size: 20px;"
        "border-radius: 4px;"
        "}";

    get = new QPushButton("Get Routes");
    get->setFixedHeight(50);
    get->setFixedWidth(200);
    get->setStyleSheet(buttonStyle);
    centeradd->addWidget(get);
    rightlayout->addLayout(centeradd);
    mainlayout->addLayout(rightlayout);

    connect(get, &QPushButton::clicked, this, &getPathsWindow::getPressed);
    connect(Home, &QPushButton::clicked, this, &getPathsWindow::Home_Button);
}

void getPathsWindow::getPressed()
{
    string country1 = country_from_input->currentText().toStdString();
    string country2 = country_to_input->currentText().toStdString();
    int cost = cost_input->value();
    set<pair<long, list<pair<TravelMethod, string>>>> paths = GuideMe->getPaths(country1, country2, cost);

    QMessageBox messeageBox;
    string message;
    messeageBox.setWindowTitle("All Routes");
    messeageBox.setGeometry(650, 300, 6000, 2000);

    int i = 1;
    for (auto& path : paths) {
        message += "Path " + to_string(i) + ':' + "\n";
        for (const auto& step : path.second) {
            message += "Transportation : " + step.first.name + " (Cost: " + to_string(step.first.cost) + ") -> " + step.second + "\n";
        }
        message += "Total Cost For this path is: " + to_string(path.first);
        message += ".\n====================================\n";
        i++;
    }

    if (paths.empty() || paths.begin()->first == 0)
        message = "No Available Paths :(\t";

    messeageBox.setText(QString::fromStdString(message));
    messeageBox.exec();
}

void getPathsWindow::Home_Button()
{
    MainWindow* HomeWindow = new  MainWindow(GuideMe);
    HomeWindow->show();
    this->close();
}
getPathsWindow::~getPathsWindow() {
    delete mainlayout;
    delete settinglayout;
    delete rightlayout;
    delete Home;
    delete get;
    delete function;
    delete country_from_label;
    delete country_to_label;
    delete cost_label;
    delete datainfo;
    delete forminfo;
    delete country_from_input;
    delete country_to_input;
    delete cost_input;

}
