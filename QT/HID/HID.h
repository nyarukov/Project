#ifndef HID_H
#define HID_H

#include <QMainWindow>

#include "QMessageBox"
#include <QTimer>
#include "QDebug"
#include <QFileDialog>


#include <Windows.h>
#include "hidapi-win/include/hidapi.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class HID;
}
QT_END_NAMESPACE

class HID : public QMainWindow
{
    Q_OBJECT

public:
    HID(QWidget *parent = nullptr);
    ~HID();

    void Init();

    void setStyle();

    hid_device* open_device();

    void close_device();

    void read_from_device();

    int write_to_device();

    void updateTimerInterval();


private slots:
    void on_connetcbtn_clicked();

    void on_closebtn_clicked();

    void onSaveToFileBtnClicked();

    void on_Sendbtn_clicked();

private:
    Ui::HID *ui;

    int HID_Start;

    quint16 vid;
    quint16 pid;

    QTimer *timer;

    hid_device *handle; // 设备句柄
    hid_device_info *hid_info; // 设备信息链表

    enum DisplayFormat { Decimal, Hexadecimal };

    DisplayFormat ReceiveFormat; // 接收显示格式
    DisplayFormat SendFormat; // 发送显示格式

    bool showTimestamp;
};
#endif // HID_H
