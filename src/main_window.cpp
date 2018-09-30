#include "main_window.h"
#include <QToolBar>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle(tr("Visual Algorithms"));
    QMenuBar* menuBar = this->menuBar();
}
