#include "src/main_window.h"

#include <QApplication>
#include <QScreen>

float gScaleSize; // for screen resolution fit

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QScreen* screen = QGuiApplication::primaryScreen();
    gScaleSize = screen->geometry().width() * 1.0 / 1920; // 1920 is the width of my computer monitor developed this app

    qApp->setStyleSheet("QWidget{font-family: 'Microsoft YaHei UI';}");

    MainWindow w;
    w.show();

    return a.exec();
}
