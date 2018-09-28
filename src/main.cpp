#include "config.h"
#include "main_window.h"
#include <QApplication>
#include <QScreen>

float g_scaledSize; /* for screen resolution fit */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QScreen* screen = QGuiApplication::primaryScreen();
    g_scaledSize = screen->geometry().width() * 1.0 / 1920;

    MainWindow w;
    w.show();

    return a.exec();
}
