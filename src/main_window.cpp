#include "main_window.h"
#include <QToolBar>
#include <QMenuBar>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    this->setWindowTitle(tr("Visual Algorithms"));
    //this->setWindowFlags(Qt::Window);
    //this->showMaximized();
    this->setWindowState(Qt::WindowMaximized);


    QMenuBar* menuBar = new QMenuBar;
    QMenu* fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(tr("Open Current Source Code File..."));
    fileMenu->addAction(tr("Open All Source Code Files..."));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Export..."));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Exit"));
    QMenu* settingMenu = menuBar->addMenu(tr("Settings"));
    settingMenu->addAction(tr("Preferences"));
    QMenu* helpMenu = menuBar->addMenu(tr("Help"));
    helpMenu->addAction(tr("Reward Me"), this, &MainWindow::rewardMeSlot);
    helpMenu->addSeparator();
    helpMenu->addAction(tr("Feedbacks"), this, &MainWindow::feedbackSlot);
    helpMenu->addAction(tr("Software Updates"), this, &MainWindow::updateSlot);
    helpMenu->addSeparator();
    helpMenu->addAction(tr("About Me"), this, &MainWindow::aboutMeSlot);
    helpMenu->addAction(tr("About Visual Algorithms"), this, &MainWindow::aboutVASSlot);

    QToolBar* menuToolBar = this->addToolBar(tr("Menu"));
    menuToolBar->addWidget(menuBar);
    menuToolBar->setMovable(false);
    QToolBar* toolBar = this->addToolBar(tr("Tool"));
    toolBar->addAction(tr("Start"));
    toolBar->addAction(tr("Replay"));
    toolBar->addAction(tr("Reset"));
    toolBar->setMovable(false);
}

void MainWindow::rewardMeSlot()
{

}

void MainWindow::feedbackSlot()
{

}

void MainWindow::updateSlot()
{

}

void MainWindow::aboutMeSlot()
{

}

void MainWindow::aboutVASSlot()
{

}
