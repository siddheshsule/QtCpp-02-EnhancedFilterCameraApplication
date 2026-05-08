#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    centralWidget = new QWidget();
    layout = new QVBoxLayout();

    cameraDevice = QMediaDevices::defaultVideoInput();

    if(cameraDevice.isNull()) {
        QLabel *errorLabel = new QLabel("No Camera Available!");
        errorLabel->setAlignment(Qt::AlignCenter);

        layout->addWidget(errorLabel);

        setCentralWidget(centralWidget);
        resize(700,600);

        return;

    }


    videoLabel = new QLabel("Camera Feed");

    videoLabel->setMaximumSize(640,488);
    videoLabel->setStyleSheet("background-color: white");
    videoLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(videoLabel);

    camera = new QCamera(cameraDevice, this);
    camera->start();

    centralWidget->setLayout(layout);

    this->setCentralWidget(centralWidget);
    this->setWindowTitle("Camera App");
    this->resize(700,600);

}

MainWindow::~MainWindow()
{
    delete ui;
}

