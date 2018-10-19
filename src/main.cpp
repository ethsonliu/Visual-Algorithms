#include "config.h"
#include "main_window.h"
#include <QApplication>
#include <QScreen>
#include <QFont>
float gScaledSize; /* for screen resolution fit */

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
//    QFont font;
//    font.setFamily("Microsoft YaHei");
//    QApplication::setFont(font);
    //VA_DEBUG(a.font());

    QScreen* screen = QGuiApplication::primaryScreen();
    gScaledSize = screen->geometry().width() * 1.0 / 1920;

    MainWindow w;
    w.show();

    return a.exec();
}
