#include "config.h"
#include "main_window.h"
#include <QApplication>
#include <QScreen>
#include <QFile>
#include <QTextStream>

float gScaledSize; /* for screen resolution fit */

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QFile file(":/qss/main.qss");
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        //QTextStream in(&file);
        //qDebug() << file.size() << in.readAll();
        qApp->setStyleSheet(file.readAll());
        file.close();
    }

    QScreen* screen = QGuiApplication::primaryScreen();
    gScaledSize = screen->geometry().width() * 1.0 / 1920;

    MainWindow w;
    w.show();

    return a.exec();
}
