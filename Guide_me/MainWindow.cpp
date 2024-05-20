
#include "MainWindow.h"
#include "TraverseWindow.h"
#include "getPathsWindow.h"
#include "Add_Path.h"

MainWindow::MainWindow(Graph* graph) : QWidget(nullptr)
{
    GuideMe = graph;
    QPixmap bkgnd("backGround.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    GuideMe = graph;
    setWindowTitle("Guide Me");

    // setting background
    setFixedSize(1540, 790);
    move(0, 0);

    //The Title 
    Title = new QLabel("Guide Me", this);
    Title->setAlignment(Qt::AlignCenter);
    Title->setStyleSheet("QLabel {"
        "font-size: 28px;"
        "letter-spacing: 2.5px;"
        "font-weight: bold;"
        "padding: 10px;"
        "border-radius: 7px;"
        "color: #CECECE; "
        "border: 2px solid #f5f5f5 ;"
        "background-color: transparent;"
        "font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;"
        "}"
    );
    Title->setFixedSize(300, 55);
    Title->move((this->width() / 2) - 150, 30);

    //buttons
    options = new QPushButton("Options", this);
    GraphInfoButton = new QPushButton("Graph Info", this);
    TraverseButton = new QPushButton("Traverse", this);
    GetPathsButton = new QPushButton("Get Paths", this);
    Exit = new QPushButton("Exit", this);

    // styling buttons
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
    QString exitButtonStyle = "QPushButton {"
        "background-color: #dc3545;" // Bootstrap danger color
        "border: 2px solid #dc3545;" // Bootstrap danger color for border
        "color: #ffffff;"
        "padding: 8px 16px;"
        "font-size: 14px;"
        "border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "background-color: #c82333;"
        "border-color: #c82333;"
        "}";

    // adding the style

    options->setStyleSheet(buttonStyle);
    GraphInfoButton->setStyleSheet(buttonStyle);
    TraverseButton->setStyleSheet(buttonStyle);
    GetPathsButton->setStyleSheet(buttonStyle);
    Exit->setStyleSheet(exitButtonStyle);


    // Set fixed width for the buttons
    int buttonWidth = 300; // Adjust the width as needed
    options->setFixedWidth(buttonWidth);
    GraphInfoButton->setFixedWidth(buttonWidth);
    TraverseButton->setFixedWidth(buttonWidth);
    GetPathsButton->setFixedWidth(buttonWidth);
    Exit->setFixedWidth(80);
    Exit->setFixedHeight(35);

    //buttons functions
    connect(Exit, &QPushButton::clicked, this, &MainWindow::onExitClicked);
    connect(options, &QPushButton::clicked, this, &MainWindow::onoptionsButtonClicked);
    connect(GraphInfoButton, &QPushButton::clicked, this, &MainWindow::onGraphInfoButtonClicked);
    connect(TraverseButton, &QPushButton::clicked, this, &MainWindow::onTraverseButtonClicked);
    connect(GetPathsButton, &QPushButton::clicked, this, &MainWindow::onGetPathsButtonClicked);

    QGridLayout* layout = new QGridLayout(this);
    int space = 1000;

    // Adding widgets to the layout
    layout->addWidget(GetPathsButton, 2, 0);
    layout->addWidget(options, 2, 1);
    layout->addItem(new QSpacerItem(space, 50), 3, 0, 1, 2);
    layout->addWidget(GraphInfoButton, 4, 0);
    layout->addWidget(TraverseButton, 4, 1);
    layout->setAlignment(Qt::AlignCenter);

    // Set the layout to the MainWindow
    setLayout(layout);

    Exit->move(5, 5);

}


void MainWindow::onExitClicked()
{
    this->close();
}

void MainWindow::onGraphInfoButtonClicked()
{
    QMessageBox messeageBox;
    string message;
    messeageBox.setWindowTitle("Information From Graph");
    messeageBox.setGeometry(650, 100, 9000, 2000);
    messeageBox.setText(QString::fromStdString(GuideMe->printGraph()));
    messeageBox.exec();

}

void MainWindow::onTraverseButtonClicked()
{
    TraverseWindow* traverse = new TraverseWindow(GuideMe);
    traverse->show();
    this->close();
}

void MainWindow::onGetPathsButtonClicked()
{
    getPathsWindow* wind = new getPathsWindow(GuideMe);
    wind->show();
    this->close();

}

void MainWindow::onoptionsButtonClicked()
{
    Add_Path* wind = new Add_Path(GuideMe);
    wind->show();
    this->close();
}

MainWindow::~MainWindow() {
    delete Title;
    delete options;
    delete TraverseButton;
    delete GraphInfoButton;
    delete GetPathsButton;
    delete Exit;
}
