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

    checkBox = new QCheckBox("Black and White Mode");

    layout->addWidget(checkBox);

    camera = new QCamera(cameraDevice, this);
    session = new QMediaCaptureSession();
    session->setCamera(camera);

    videoSink = new QVideoSink();
    session->setVideoSink(videoSink);
    QObject::connect(videoSink,&QVideoSink::videoFrameChanged, [&](const QVideoFrame &frame) {
        if(!frame.isValid()) return;
        QVideoFrame cloneFrame(frame);
        cloneFrame.map(QVideoFrame::ReadOnly);
        QImage image = cloneFrame.toImage();
        cloneFrame.unmap();
        currentFrame = checkBox->isChecked() ? image.convertToFormat(QImage::Format_Grayscale8) : image;
        videoLabel->setPixmap(QPixmap::fromImage(currentFrame).scaled(videoLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    });

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

