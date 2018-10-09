#include "config.h"
#include "main_window.h"
#include <QApplication>
#include <QScreen>

float gScaledSize; /* for screen resolution fit */

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QScreen* screen = QGuiApplication::primaryScreen();
    gScaledSize = screen->geometry().width() * 1.0 / 1920;

    MainWindow w;
    w.show();

    return a.exec();
}
