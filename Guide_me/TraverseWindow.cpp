#include "TraverseWindow.h"
#include "MainWindow.h"

//Graph Guide_me;
TraverseWindow::TraverseWindow(Graph* graph, QWidget* parent)
{
    GuideMe = graph;
    QPixmap bkgnd("backGround.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    // Guide_me = GuideMe;
    setWindowTitle("Guide Me");

    setFixedSize(1540, 790);

    mainlayout = new QHBoxLayout();
    setLayout(mainlayout);

    function = new QLabel("Map Traverse");
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

    // your country  
    your_country_label = new QLabel("Your Country");
    your_country_input = new QComboBox();
    your_country_input->addItems(countries);
    your_country_input->setFixedWidth(1050);
    forminfo->addRow(your_country_label, your_country_input);

    //radio buttons
    bfs = new QRadioButton("  Nearest First");
    dfs = new QRadioButton("  Farthest First");
    radioButtons = new QVBoxLayout();
    radioButtons->addWidget(bfs);
    radioButtons->addWidget(dfs);
    radioButtons->setSpacing(10);
    bfs->setChecked(true);
    forminfo->addRow(radioButtons);
    forminfo->setSpacing(20);

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

    Traverse = new QPushButton("Traverse");
    Traverse->setFixedHeight(50);
    Traverse->setFixedWidth(200);
    Traverse->setStyleSheet(buttonStyle);
    centeradd->addWidget(Traverse);
    rightlayout->addLayout(centeradd);
    mainlayout->addLayout(rightlayout);

    connect(Traverse, &QPushButton::clicked, this, &TraverseWindow::traversePressed);
    connect(Home, &QPushButton::clicked, this, &TraverseWindow::Home_Button);
}

void TraverseWindow::traversePressed()
{
    string country = your_country_input->currentText().toStdString();
    list<string>path;


    if (bfs->isChecked())
        path = GuideMe->BFS(country);
    else
        path = GuideMe->DFS(country);

    QMessageBox messeageBox;
    messeageBox.setWindowTitle("The Route");
    messeageBox.setGeometry(700, 350, 6000, 2000);

    // edit the message here
    string message = path.front();
    path.pop_front();
    for (string country : path)
        message += " --> " + country;

    messeageBox.setText(QString::fromStdString(message));
    messeageBox.exec();
}

void TraverseWindow::Home_Button()
{
    MainWindow* HomeWindow = new  MainWindow(GuideMe);
    HomeWindow->show();
    this->close();
}
TraverseWindow::~TraverseWindow() {
    delete function;
    delete your_country_label;
    delete datainfo;
    delete forminfo;
    delete Home;
    delete Traverse;
    delete radioButtons;
    delete mainlayout;
    delete settinglayout;
    delete rightlayout;

}
