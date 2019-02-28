#include "src/config.h"
#include "src/main_window.h"

#include <QApplication>
#include <QScreen>
#include <QFile>
#include <QTextCodec>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    qApp->setStyleSheet("QWidget{font-family: 'Microsoft YaHei UI';}");

    MainWindow w;
    w.show();

    return a.exec();
}
