#include "MainWindow.h"

MainWindow::MainWindow() :QWidget(nullptr)
{
    setWindowTitle("Guide Me");



    // setting background
    setFixedSize(1540, 790);
    move(0, 0);
    QPixmap bkgnd(":/new/prefix1/images/peakpx (1).jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

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


    AddPathButton = new QPushButton("Add Path", this);
    UpdatePathButton = new QPushButton("Update Path", this);
    DeletePathButton = new QPushButton("Delete Path", this);
    AddCountryButton = new QPushButton("Add Country", this);
    DeleteCountryButton = new QPushButton("Delete Country", this);
    Graphvisualization = new QPushButton("Graph visualization", this);
    BFSButton = new QPushButton("BFS Search", this);
    DFSButton = new QPushButton("DFS Search", this);
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
        "background-color: #c82333;" // Darken the color on hover
        "border-color: #c82333;" // Darken the border color on hover
        "}";

    // adding the style
    AddPathButton->setStyleSheet(buttonStyle);
    UpdatePathButton->setStyleSheet(buttonStyle);
    DeletePathButton->setStyleSheet(buttonStyle);
    AddCountryButton->setStyleSheet(buttonStyle);
    DeleteCountryButton->setStyleSheet(buttonStyle);
    Graphvisualization->setStyleSheet(buttonStyle);
    BFSButton->setStyleSheet(buttonStyle);
    DFSButton->setStyleSheet(buttonStyle);
    GetPathsButton->setStyleSheet(buttonStyle);
    Exit->setStyleSheet(exitButtonStyle);

    //
   // Set fixed width for the buttons
    int buttonWidth = 300; // Adjust the width as needed
    AddPathButton->setFixedWidth(buttonWidth);
    UpdatePathButton->setFixedWidth(buttonWidth);
    DeletePathButton->setFixedWidth(buttonWidth);
    AddCountryButton->setFixedWidth(buttonWidth);
    DeleteCountryButton->setFixedWidth(buttonWidth);
    Graphvisualization->setFixedWidth(buttonWidth);
    BFSButton->setFixedWidth(buttonWidth);
    DFSButton->setFixedWidth(buttonWidth);
    GetPathsButton->setFixedWidth(buttonWidth);
    Exit->setFixedWidth(80);
    Exit->setFixedHeight(35);

    //buttons functions
    connect(Exit, &QPushButton::clicked, this, &MainWindow::onExitClicked);
    connect(AddPathButton, &QPushButton::clicked, this, &MainWindow::onAddPathButtonClicked);
    connect(UpdatePathButton, &QPushButton::clicked, this, &MainWindow::onUpdatePathButtonClicked);
    connect(DeletePathButton, &QPushButton::clicked, this, &MainWindow::onDeletePathButtonClicked);
    connect(AddCountryButton, &QPushButton::clicked, this, &MainWindow::onAddCountryButtonClicked);
    connect(DeleteCountryButton, &QPushButton::clicked, this, &MainWindow::onDeleteCountryButtonClicked);
    connect(Graphvisualization, &QPushButton::clicked, this, &MainWindow::onGraphvisualizationClicked);
    connect(BFSButton, &QPushButton::clicked, this, &MainWindow::onBFSButtonClicked);
    connect(DFSButton, &QPushButton::clicked, this, &MainWindow::onDFSButtonClicked);
    connect(GetPathsButton, &QPushButton::clicked, this, &MainWindow::onGetPathsButtonClicked);

    // layout 
    QGridLayout* layout = new QGridLayout(this);
    int row = 0;
    int column = 0;
    int space = 1000;

    layout->addWidget(AddPathButton, row, column);
    layout->addWidget(UpdatePathButton, row, column + 1);
    layout->addWidget(DeletePathButton, row, column + 2);
    row++;
    layout->addItem(new QSpacerItem(space, 50), row, column, 1, 3); // Add a spacer item for column spacing
    row++;
    layout->addWidget(AddCountryButton, row, column);
    layout->addWidget(DeleteCountryButton, row, column + 1);
    layout->addWidget(GetPathsButton, row, column + 2);
    row++;
    layout->addItem(new QSpacerItem(space, 50), row, column, 1, 3);
    row++;
    layout->addWidget(Graphvisualization, row, column);
    layout->addWidget(BFSButton, row, column + 1);
    layout->addWidget(DFSButton, row, column + 2);
    row++;
    layout->addItem(new QSpacerItem(space, 50), row, column, 1, 3);
    Exit->move(5, 5);


    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);

}

void MainWindow::onExitClicked()
{
    this->close();
}

void MainWindow::onAddPathButtonClicked()
{
    this->close();
}

void MainWindow::onUpdatePathButtonClicked()
{
    this->close();
}

void MainWindow::onDeletePathButtonClicked()
{
    this->close();
}

void MainWindow::onAddCountryButtonClicked()
{
    this->close();
}

void MainWindow::onDeleteCountryButtonClicked()
{
    this->close();
}

void MainWindow::onGraphvisualizationClicked()
{
    this->close();
}


void MainWindow::onBFSButtonClicked()
{
    this->close();
}

void MainWindow::onDFSButtonClicked()
{
    this->close();
}

void MainWindow::onGetPathsButtonClicked()
{
    this->close();
}
