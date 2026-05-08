#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QCameraDevice>
#include<QMediaDevices>
#include<QCamera>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

    //void setupUi();
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QLabel *videoLabel;
    QCameraDevice cameraDevice;
    QCamera *camera;

};
#endif // MAINWINDOW_H
