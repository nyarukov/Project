#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QTimer"
#include "QMessageBox"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Serial_Init();
    connect(ui->Serial_SendClear,SIGNAL(clicked()),ui->Serial_SendEdit,SLOT(clear()));
    connect(ui->Serial_ReceClear,SIGNAL(clicked()),ui->Serial_ReceEdit,SLOT(clear()));
    connect(ui->Serial_Open,&QPushButton::clicked,this,&MainWindow::Serial_Open_Clicked);
    //connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::USB_Mess);
    //QTimer *timer =new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(usbdataupdate()));
    //timer->start(100);

}

void MainWindow::Serial_Init(){

    //获取所有串口
    QSerialPortInfo::availablePorts();
    auto portInfo = QSerialPortInfo::availablePorts();
    for(auto& info:portInfo){
        qInfo()<<info.description()<<info.portName()<<info.systemLocation();
        //显示串口
        ui->Uart_com->addItem(info.portName()+":"+info.description(),info.portName());
    }
    //获取波特率
    auto Serial_BuadRates = QSerialPortInfo::standardBaudRates();
    for(auto & buad:Serial_BuadRates){
        ui->Serial_BuadRates->addItem(QString::number(buad));
    }
    ui->Serial_BuadRates->setCurrentText("115200");
    //获取数据位
    ui->Uart_DataBtis->addItem("7",QSerialPort::DataBits::Data7);
    ui->Uart_DataBtis->addItem("8",QSerialPort::DataBits::Data8);
    ui->Uart_DataBtis->setCurrentText("8");
    //获取停止位
    ui->Uart_StopBtis->addItem("1",QSerialPort::StopBits::OneStop);
    ui->Uart_StopBtis->addItem("1.5",QSerialPort::StopBits::OneAndHalfStop);
    ui->Uart_StopBtis->addItem("2",QSerialPort::StopBits::TwoStop);
    ui->Uart_StopBtis->setCurrentText("1");
    //获取校验位
    ui->Uart_CheckBits->addItem("无校验",QSerialPort::Parity::NoParity);
    ui->Uart_CheckBits->addItem("奇校验",QSerialPort::Parity::OddParity);
    ui->Uart_CheckBits->addItem("偶校验",QSerialPort::Parity::EvenParity);
    ui->Uart_CheckBits->setCurrentText("无校验");

    //connect(&serialport,&QSerialPort::readyRead,this,&MainWindow::Serial_Receive);
}

void MainWindow::Serial_Open_Clicked(){
    if(serialport.isOpen()){
        serialport.close();
        ui->Serial_Open->setText("打开");
        return;
    }
    auto portName =ui->Uart_com->currentData().toString();
    auto baudRate = ui->Serial_BuadRates->currentData().value<QSerialPort::BaudRate>();
    auto dataBits = ui->Uart_DataBtis->currentData().value<QSerialPort::DataBits>();
    auto stopBits = ui->Uart_StopBtis->currentData().value<QSerialPort::StopBits>();
    auto checkBits = ui->Uart_CheckBits->currentData().value<QSerialPort::Parity>();

    serialport.setPortName(portName);
    serialport.setBaudRate(baudRate);
    serialport.setDataBits(dataBits);
    serialport.setStopBits(stopBits);
    serialport.setParity(checkBits);

    if(!serialport.open(QIODevice::ReadWrite)){
        QMessageBox::warning(this,"Warning",portName+" open failed"+serialport.errorString());
        return;
    }else{
        ui->Serial_Open->setText("关闭");
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}


