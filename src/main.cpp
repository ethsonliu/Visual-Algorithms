#include "main_window.h"
#include <QApplication>

double g_scaledSize; // for screen resolution fit

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
