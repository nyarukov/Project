#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->CRC_btn, &QPushButton::clicked, this, &MainWindow::calculateCRC);
}

MainWindow::~MainWindow()
{
    delete ui;
}

quint16 CRC(const QByteArray &data) {
    quint16 crc = 0xFFFF; // 初始CRC值设为0xFFFF

    for (int i = 0; i < data.size(); i++) {
        crc ^= static_cast<quint8>(data.at(i)); // 与当前字节进行XOR操作

        for (int j = 0; j < 8; j++) {
            if (crc & 0x0001) { // 如果最低位为1
                crc >>= 1; // 右移一位
                crc ^= 0xA001; // 与多项式0xA001进行异或
            } else {
                crc >>= 1; // 右移一位
            }
        }
    }
    return crc;
}

void MainWindow::calculateCRC()
{
    QString inputData = ui->CRC_IN->toPlainText(); // 读取输入数据
    QByteArray byteArray = QByteArray::fromHex(inputData.toLatin1()); // 将输入数据转换为字节数组

    quint16 crcValue = CRC(byteArray); // 计算CRC校验值

    if(ui->CRCLH_Check->isChecked()){
        crcValue = (crcValue >> 8) | (crcValue << 8); // 将CRC校验值转换为大端字节序（高位在前）
    }else {
        crcValue = crcValue; // 将CRC校验值转换为小端字节序（低位在前）
    }

    QString crcHex = QString("%1").arg(crcValue, 4, 16, QLatin1Char('0')); // 将CRC校验值转换为十六进制字符串

    ui->CRC_OUT->setPlainText(QString("0x"+crcHex)); // 在输出控件中显示CRC校验值
}

