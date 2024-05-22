#include "HID.h"
#include "ui_HID.h"

#define TX_MAXSIZE 64

HID::HID(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HID),
        handle(nullptr),// 初始化设备句柄为nullptr
        hid_info(nullptr) // 初始化设备信息链表为nullptr
{
    ui->setupUi(this);
    setStyleSheet("background-color: white;");
    Init();
    setStyle();
}

HID::~HID()
{
    delete ui;
    delete timer;
}

void HID::Init(){
    HID_Start=0;

    ui->VID_Edit->setText("0x485");
    ui->PID_Edit->setText("0x5740");
    ui->Timer_cycle->setText("1000");
    ReceiveFormat=Decimal;
    SendFormat=Decimal;

    showTimestamp=false;

    ui->label_5->setText("接口号: 未知");
    ui->label_6->setText("厂商字: 未知");
    ui->label_7->setText("设备: 未知");
    ui->label_8->setText("版本号: 未知");
    ui->Hid_Start->setText("设备已断开");

    connect(ui->Receivebtn_Clear, SIGNAL(clicked()), ui->Receive_Edit, SLOT(clear()));
    connect(ui->Sendbtn_Clear, SIGNAL(clicked()), ui->Send_Edit, SLOT(clear()));
    connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(onSaveToFileBtnClicked()));

    //时间戳
    connect(ui->ShowTimebtn,&QCheckBox::clicked,this, [&]{
        if(showTimestamp){
            showTimestamp=false;
        }else{
            showTimestamp=true;
        }
    });
    //进制格式
    connect(ui->Receive_Formatbtn,&QCheckBox::clicked,this, [&]{
        if(ReceiveFormat==Decimal){
            ReceiveFormat=Hexadecimal;
        }else{
            ReceiveFormat=Decimal;
        }
    });
    connect(ui->Send_Formatbtn,&QCheckBox::clicked,this, [&]{
        if(SendFormat==Decimal){
            SendFormat=Hexadecimal;
        }else{
            SendFormat=Decimal;
        }
    });


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &HID::read_from_device);
    connect(ui->Timer_cycle, &QLineEdit::editingFinished, this, &HID::updateTimerInterval);
    timer->start(1000);

}

void HID::setStyle(){
    QString buttonStyle="QPushButton {"
                          "border-radius: 5px;"
                          "background-color: white;"
                          "color: black;"
                          "padding: 5px 5px;"
                          "border: 2px solid #CCCCCC;"
                          "}";

    foreach (QWidget *widget, QApplication::allWidgets()) {
        QPushButton *button = qobject_cast<QPushButton*>(widget);
        if (button) {
            button->setStyleSheet(buttonStyle);
        }
    }
    qApp->setStyleSheet("QLineEdit, QPlainTextEdit {"
                        "color: black;"
                        "background-color: white;"
                        "border: 1px solid gray;"
                        "border-radius: 5px;"  // 可选的圆角边框
                        "padding: 2px 5px;"    // 可选的内边距
                        "}");



}

// 打开设备并返回设备句柄
hid_device* HID::open_device() {
    hid_device_info *hid_info = nullptr;
    hid_device *handle = nullptr;

    vid=ui->VID_Edit->text().toUShort(nullptr,16);
    pid=ui->PID_Edit->text().toUShort(nullptr,16);

    if (vid == 0 || pid == 0) {
        ui->Hid_Start->setText("VID或PID为空");
        return nullptr;
    }

    /* 打开指定VID PID设备 */
    hid_info = hid_enumerate(vid, pid);
    if (hid_info == nullptr) {
        ui->Hid_Start->setText("未找到指定设备");
        return nullptr;
    }

    /* 获取设备信息 */
    handle = hid_open_path(hid_info->path);
    if (handle == nullptr) {
        ui->Hid_Start->setText("无法打开设备");
        hid_free_enumeration(hid_info);
        return nullptr;
    }

    /* 释放链表 */
    hid_free_enumeration(hid_info);

    return handle;
}

// 关闭设备
void HID::close_device() {
    if (handle != nullptr) {
        hid_close(handle);
    }
}

// 读取设备数据并显示到界面
void HID::read_from_device() {
    int res;
    uint8_t buf[TX_MAXSIZE + 1]; // 加1以包含报告ID
    if(HID_Start==1){
        res = hid_read(handle, buf, 64 + 1);
        if (res < 0) {
            /* 返回值查看 */
            qDebug("读取错误: %ls\n", hid_error(handle));
        }else if(res==0){
            return;
        }
        QString dataText;
        if (showTimestamp) {
            // 添加当前时间
            QTime currentTime = QTime::currentTime();
            dataText += currentTime.toString("[------>>>hh:mm:ss.zzz------>>>]") + "\n"; // 格式化时间并添加空格
        }
        if (ReceiveFormat == Decimal) {
            // 十进制格式
            for (int i = 0; i < 64; i++) {
                dataText += QString("%1").arg(buf[i]);
                //QString text = QString("buf[%1]: %2").arg(i).arg(buf[i]);
                if (i < 63) {
                    dataText += " ";  // 在每两个数据之间添加空格
                }
            }
        } else {
            // 十六进制格式
            for (int i = 0; i < 64; i++) {
                dataText += QString("0x%1 ").arg(buf[i], 2, 16, QChar('0'));
                //QString text = QString("buf[%1]: 0x%2").arg(i).arg(buf[i], 2, 16, QChar('0'));
                if (i < 63) {
                    dataText += " ";  // 在每两个数据之间添加空格
                }
            }
        }
        // 一次性添加所有数据到文本框
        ui->Receive_Edit->appendPlainText(dataText);
    }
}

// 向设备写入数据
int HID::write_to_device() {
    int res;
    uint8_t buf[TX_MAXSIZE + 1]; // 加1以包含报告ID
    if(HID_Start==1){
        // 从Send_Edit获取数据
        QString sendData = ui->Send_Edit->toPlainText();

        // 将QString转换为字节数组
        QByteArray byteArray;

        if (SendFormat == Decimal) {
            // 文本格式
            byteArray = sendData.toUtf8();
        } else {
            // 十六进制格式
            QStringList hexList = sendData.split(" ");
            foreach (const QString &hex, hexList) {
                bool ok;
                int value = hex.toInt(&ok, 16);
                if (ok) {
                    byteArray.append(static_cast<char>(value));
                }
            }
        }

        const char* dataToSend = byteArray.constData();
        int dataSize = byteArray.size();

        // 确保数据不超过TX_MAXSIZE，如果超过则截断
        if (dataSize > TX_MAXSIZE) {
            dataSize = TX_MAXSIZE;
        }

        // 将数据存储到buf数组中
        buf[0] = 0x22; // 报告ID（自定义）
        for (int i = 0; i < dataSize; i++) {
            buf[i + 1] = dataToSend[i];
        }

        // 发送数据
        res = hid_write(handle, buf, TX_MAXSIZE + 1); // 这里也加1
        if (res < 0) {
            /* 返回值查看 */
            qDebug("写入错误: %ls\n", hid_error(handle));
            return -1;
        }
    }
    return 0;
}

//连接设备
void HID::on_connetcbtn_clicked()
{
    // 如果设备已经打开，先关闭设备
    if (handle != nullptr) {
        close_device();
        HID_Start=0;

    }
    // 打开设备并保存设备句柄
    handle = open_device();

    hid_info = hid_enumerate(vid, pid);
    if (handle != nullptr) {
        HID_Start=1;
         hid_set_nonblocking(handle, 1);
        ui->Hid_Start->setText("设备已连接");
        for (hid_device_info *curr_hid_info = hid_info; curr_hid_info != nullptr; curr_hid_info = curr_hid_info->next) {
            // 更新接口号标签
            ui->label_5->setText(QString("接口号: %1").arg(curr_hid_info->interface_number));
            // 更新厂商字符串标签
            if (curr_hid_info->manufacturer_string != nullptr) {
                ui->label_6->setText(QString("厂商: %1").arg(QString::fromWCharArray(curr_hid_info->manufacturer_string)));
            } else {
                ui->label_6->setText("厂商字: 未知");
            }
            // 更新设备字符串标签
            if (curr_hid_info->product_string != nullptr) {
                ui->label_7->setText(QString("设备: %1").arg(QString::fromWCharArray(curr_hid_info->product_string)));
            } else {
                ui->label_7->setText("字符串: 未知");
            }
            // 更新版本号标签
            ui->label_8->setText(QString("版本号: %1").arg(curr_hid_info->release_number));
        }
    }
    else {
        ui->Hid_Start->setText("连接失败");
        HID_Start=0;
    }
}

//关闭设备
void HID::on_closebtn_clicked()
{
    close_device();
    HID_Start=0;
    // 将设备句柄设为nullptr
    handle = nullptr;
    ui->label_5->setText("接口号: 未知");
    // 更新厂商字符串标签
    ui->label_6->setText("厂商字: 未知");
    // 更新设备字符串标签
    ui->label_7->setText("设备: 未知");
    // 更新版本号标签
    ui->label_8->setText("版本号: 未知");
    ui->Hid_Start->setText("设备已断开");
}

//发送数据
void HID::on_Sendbtn_clicked()
{
    write_to_device();
}

//数据刷新时间
void HID::updateTimerInterval() {
    bool ok;
    int interval = ui->Timer_cycle->text().toInt(&ok);
    if (ok && interval > 0) {
        timer->setInterval(interval);
        qDebug() << "定时器时间间隔已更新为：" << interval << "毫秒";
    } else {
        qDebug() << "无效的时间间隔";
    }
}

//保存数据
void HID::onSaveToFileBtnClicked() {
    // 弹出文件保存对话框
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));

    // 检查用户是否取消了对话框
    if (fileName.isEmpty()) {
        return;
    }
    // 打开文件
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件";
        return;
    }
    // 获取文本框内容
    QString content = ui->Receive_Edit->toPlainText();
    // 将内容写入文件
    QTextStream out(&file);
    out << content;
    // 关闭文件
    file.close();
}


