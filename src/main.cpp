#include "config.h"
#include "main_window.h"
#include <QApplication>
#include <QScreen>
#include <QFile>
#include <QTextCodec>

float gScaledSize; /* for screen resolution fit */

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    /* set qss style for the app */
    QFile file(":/qss/main.qss");
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QString qss = codec->toUnicode(file.readAll());
        qApp->setStyleSheet(qss);
        file.close();
    }

    QScreen* screen = QGuiApplication::primaryScreen();
    gScaledSize = screen->geometry().width() * 1.0 / 1920;

    MainWindow w;
    w.show();

    return a.exec();
}
