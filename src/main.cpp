#include "config.h"
#include "main_window.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>

float g_scaledSize; /* for screen resolution fit */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<QScreen*> screenList = QGuiApplication::screens();
    VA_DEBUG(screenList.size());
    VA_DEBUG(screenList.at(0)->geometry());
    VA_DEBUG(screenList.at(1)->geometry());

    MainWindow w;
    w.show();

    return a.exec();
}
