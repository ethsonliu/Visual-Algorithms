#include "config.h"
#include "main_window.h"
#include <QApplication>

float g_scaledSize; /* for screen resolution fit */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGuiApplication::primaryScreen();

    MainWindow w;
    w.show();

    return a.exec();
}
