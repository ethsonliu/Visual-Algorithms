#include "main_window.h"
#include <QIcon>
#include <QToolBar>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFontDatabase>
#include <QToolButton>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    /* https://filosophy.org/writing/visual-algorithms-precision-and-recall/ */
    /* icons download by https://www.iconfinder.com */
    this->setWindowTitle(tr("Visual Algorithms"));
    this->setWindowState(Qt::WindowMaximized);

    createToolBar();
    createNavWidget();
    createTabWidget();

    m_centralWidget = new QWidget;
    QHBoxLayout* hLayout = new QHBoxLayout(m_centralWidget);
    hLayout->addWidget(m_navWidget);
    hLayout->addWidget(m_tabWidget);
    this->setCentralWidget(m_centralWidget);
}

void MainWindow::createToolBar()
{
    /* create menubar object, and add some menus to it */
    QMenuBar* menuBar = new QMenuBar;
    QMenu* fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(tr("Open Source Code Directory..."));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Exit"));
    QMenu* languagesMenu = menuBar->addMenu(tr("Languages"));
    languagesMenu->addAction(tr("(System Language)"));
    languagesMenu->addAction(tr("English"));
    languagesMenu->addAction(tr("Simplified Chinese"));
    QMenu* tabsMenu = menuBar->addMenu(tr("Tabs"));
    tabsMenu->addAction(tr("Go to Home Tab"));
    tabsMenu->addSeparator();
    tabsMenu->addAction(tr("Next Tab"));
    tabsMenu->addAction(tr("Previous Tab"));
    QMenu* donateMenu = menuBar->addMenu(tr("Donate"));
    donateMenu->addAction(tr("Donate to Me"), this, &MainWindow::rewardMeSlot);
    QMenu* helpMenu = menuBar->addMenu(tr("Help"));
    helpMenu->addAction(tr("Feedbacks"), this, &MainWindow::feedbackSlot);
    helpMenu->addAction(tr("Software Updates"), this, &MainWindow::updateSlot);
    helpMenu->addSeparator();
    helpMenu->addAction(tr("About Visual Algorithms"), this, &MainWindow::aboutVASSlot);
    menuBar->setFixedHeight(menuBar->minimumSizeHint().height());

    /* add the menubar above to the toolbar */
    QToolBar* menuToolBar = this->addToolBar(tr("Menu"));
    menuToolBar->addWidget(menuBar);
    menuToolBar->setMovable(false);

    QString toolButtonQss;
    toolButtonQss.sprintf("QToolButton{margin: %dpx; padding: 0px %dpx;}", FIT(2), FIT(3));
    QString sliderQss;
    sliderQss.sprintf("QSlider{padding: 0px %dpx;}", FIT(55));


    /* add some toolbuttons to the toolbar */
    QToolBar* toolBar = this->addToolBar(tr("Tool"));
    toolBar->addSeparator();
    QToolButton* playToolButton = new QToolButton;
    playToolButton->setIcon(QIcon(":/icons/play.svg"));
    playToolButton->setStyleSheet(toolButtonQss);
    toolBar->addWidget(playToolButton);
    toolBar->addSeparator();
    QToolButton* replayToolButton = new QToolButton;
    replayToolButton->setIcon(QIcon(":/icons/replay.svg"));
    replayToolButton->setStyleSheet(toolButtonQss);
    toolBar->addWidget(replayToolButton);
    QToolButton* restoreToolButton = new QToolButton;
    restoreToolButton->setIcon(QIcon(":/icons/restore.svg"));
    restoreToolButton->setStyleSheet(toolButtonQss);
    toolBar->addWidget(restoreToolButton);
    toolBar->addSeparator();
    toolBar->setMovable(false);

    /* add a slider to the toolbar */
    QToolBar* sliderToolBar = this->addToolBar(tr("Speed Slider"));
    m_speedSlider = new QSlider(Qt::Horizontal);
    //m_speedSlider->setStyleSheet(sliderQss);
    m_speedSlider->setRange(0, 100);
    m_speedSlider->setValue(m_speedSlider->maximum() >> 1);
    sliderToolBar->setFixedWidth(FIT(240));
    sliderToolBar->addWidget(m_speedSlider);
    sliderToolBar->setMovable(false);
    QToolBar* emptyToolBar = this->addToolBar(tr("Empty"));
    emptyToolBar->setMovable(false);
}

void MainWindow::createNavWidget()
{
    m_searchLineEdit = new QLineEdit;
    m_searchLineEdit->setPlaceholderText(tr("Type here to search"));
    m_searchLineEdit->addAction(QIcon(":/icons/search.svg"), QLineEdit::LeadingPosition);

    m_treeWidget = new QTreeWidget;

    m_navWidget = new QWidget;
    m_navWidget->setFixedWidth(FIT(400));
    QVBoxLayout* vLayout = new QVBoxLayout(m_navWidget);
    vLayout->addWidget(m_searchLineEdit);
    vLayout->addWidget(m_treeWidget);

}

void MainWindow::createTabWidget()
{
    m_tabWidget = new QTabWidget;
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

void MainWindow::aboutVASSlot()
{

}
