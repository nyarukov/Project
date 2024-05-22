#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSerialPort/QSerialPortInfo"
#include "QtSerialPort/QSerialPort"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int UsbOpenFlag = 0;     /* USB连接打开和关闭标志，0标志当前关闭，1表示当前打开   */

private slots:
    void Serial_Init();
    void Serial_Open_Clicked();
private:
    Ui::MainWindow *ui;
    QSerialPort serialport;

};
#endif // MAINWINDOW_H
