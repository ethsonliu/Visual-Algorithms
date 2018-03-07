#include "main_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("Consolas",13));
    MainWindow w;
    w.show();
    return a.exec();
}
