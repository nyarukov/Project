#include "HID.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HID w;
    w.show();
    return a.exec();
}
