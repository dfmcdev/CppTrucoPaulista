#include "QtTrucoApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtTrucoApplication w;
    w.show();
    return a.exec();
}
