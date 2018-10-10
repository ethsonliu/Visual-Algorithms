#include "main_window.h"
#include <QToolBar>
#include <QMenuBar>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    this->setWindowTitle(tr("Visual Algorithms"));
    this->setWindowState(Qt::WindowMaximized);

    QMenuBar* menuBar = new QMenuBar;
    QMenu* fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(tr("Open Source Code Directory..."));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Exit"));
    QMenu* languageMenu = menuBar->addMenu(tr("Languages"));
    languageMenu->addAction(tr("(System Language)"));
    languageMenu->addAction(tr("English"));
    languageMenu->addAction(tr("Simplified Chinese"));
    QMenu* tabsMenu = menuBar->addMenu(tr("Tabs"));
    tabsMenu->addAction(tr("Go to Home Tab"));
    tabsMenu->addSeparator();
    tabsMenu->addAction(tr("Next Tab"));
    tabsMenu->addAction(tr("Previous Tab"));
    QMenu* rewardMenu = menuBar->addMenu(tr("Donate"));
    rewardMenu->addAction(tr("Donate to Me"), this, &MainWindow::rewardMeSlot);
    QMenu* helpMenu = menuBar->addMenu(tr("Help"));
    helpMenu->addAction(tr("Feedbacks"), this, &MainWindow::feedbackSlot);
    helpMenu->addAction(tr("Software Updates"), this, &MainWindow::updateSlot);
    helpMenu->addSeparator();
    helpMenu->addAction(tr("About Me"), this, &MainWindow::aboutMeSlot);
    helpMenu->addAction(tr("About Visual Algorithms"), this, &MainWindow::aboutVASSlot);

    /* icons download by https://www.iconfinder.com */
    QToolBar* menuToolBar = this->addToolBar(tr("Menu"));
    menuToolBar->addWidget(menuBar);
    menuToolBar->setMovable(false);
    QToolBar* toolBar = this->addToolBar(tr("Tool"));
    toolBar->addAction(QIcon(":/icons/play.svg"), tr("Play"));
    toolBar->addAction(QIcon(":/icons/replay.svg"), tr("Replay"));
    toolBar->addAction(QIcon(":/icons/restore.svg"), tr("Restore"));
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
