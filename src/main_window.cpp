﻿#include "main_window.h"
#include "panes/bfs_pane.h"
#include <QIcon>
#include <QToolBar>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    /* icons download by https://www.iconfinder.com */
    setWindowTitle(tr("Visual Algorithms"));
    setWindowState(Qt::WindowMaximized);

    createToolBar();
    createNavWidget();
    createTabWidget();

    QVBoxLayout* vLayout1 = new QVBoxLayout;
    vLayout1->addSpacing(22);
    vLayout1->addWidget(m_navWidget);
    vLayout1->addSpacing(8);

    QVBoxLayout* vLayout2 = new QVBoxLayout;
    vLayout2->addWidget(m_frame);
    vLayout2->addSpacing(8);

    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addLayout(vLayout1);
    hLayout->addLayout(vLayout2);
    hLayout->setSpacing(4);
    hLayout->setContentsMargins(8, 0, 0, 0);

    m_centralWidget = new QWidget;
    m_centralWidget->setLayout(hLayout);

    setCentralWidget(m_centralWidget);
}

void MainWindow::createToolBar()
{
    /* create menubar, and add some menus to it */
    QMenuBar* menuBar = new QMenuBar;
    QMenu* fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(QIcon(":/images/open.svg"), tr("Open Source Code Directory..."), this, &MainWindow::openSlot);
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Exit"));
    QMenu* languagesMenu = menuBar->addMenu(tr("Languages"));
    connect(languagesMenu, &QMenu::triggered, this, &MainWindow::changeLanguageSlot);
    QAction* action = languagesMenu->addAction(QIcon(":/images/dot.svg"), tr("(System Language)"));
    action->setCheckable(true);
    action->setChecked(true);
    m_lastLanguageAction = action;
    languagesMenu->addSeparator();
    action = languagesMenu->addAction(QIcon(":/images/dot.svg"), tr("English"));
    action->setCheckable(true);
    action->setIconVisibleInMenu(false);
    action = languagesMenu->addAction(QIcon(":/images/dot.svg"), tr("Simplified Chinese"));
    action->setCheckable(true);
    action->setIconVisibleInMenu(false);
    QMenu* tabsMenu = menuBar->addMenu(tr("Tabs"));
    tabsMenu->addAction(QIcon(":/images/home.svg"), tr("Go to Home Tab"), this, &MainWindow::homeTabSlot);
    tabsMenu->addSeparator();
    tabsMenu->addAction(tr("Next Tab"), this, &MainWindow::nextTabSlot);
    tabsMenu->addAction(tr("Previous Tab"), this, &MainWindow::previousTabSlot);
    QMenu* donateMenu = menuBar->addMenu(tr("Donate"));
    donateMenu->addAction(QIcon(":/images/donate.png"), tr("Donate to Me"), this, &MainWindow::donateSlot);
    QMenu* helpMenu = menuBar->addMenu(tr("Help"));
    helpMenu->addAction(tr("Feedbacks"), this, &MainWindow::feedbackSlot);
    helpMenu->addAction(QIcon(":/images/update.svg"), tr("Software Updates"), this, &MainWindow::updateSlot);
    helpMenu->addSeparator();
    helpMenu->addAction(QIcon(":/images/app.ico"), tr("About Visual Algorithms"), this, &MainWindow::aboutSlot);
    menuBar->setFixedHeight(menuBar->minimumSizeHint().height());

    /* add the menubar above to the toolbar */
    QToolBar* menuToolBar = addToolBar(tr("Menu"));
    menuToolBar->addWidget(menuBar);
    menuToolBar->setMovable(false);

    /* add some toolbuttons to the toolbar */
    QToolBar* toolBar = addToolBar(tr("Tool"));
    toolBar->addSeparator();
    m_playToolButton = new ToolButton;
    m_playToolButton->setIcon(QIcon(":/images/play.svg"));
    connect(m_playToolButton, &ToolButton::clicked, this, &MainWindow::playSlot);
    toolBar->addWidget(m_playToolButton);
    toolBar->addSeparator();
    ToolButton* replayToolButton = new ToolButton;
    replayToolButton->setIcon(QIcon(":/images/replay.svg"));
    replayToolButton->setToolTip(tr("Replay the animation"));
    toolBar->addWidget(replayToolButton);
    ToolButton* restoreToolButton = new ToolButton;
    restoreToolButton->setIcon(QIcon(":/images/restore.svg"));
    restoreToolButton->setToolTip(tr("Restore to the initial state"));
    toolBar->addWidget(restoreToolButton);
    toolBar->addSeparator();
    ToolButton* snapshotToolButton = new ToolButton;
    snapshotToolButton->setIcon(QIcon(":/images/snapshot.svg"));
    snapshotToolButton->setToolTip(tr("Take a snapshot of the animation"));
    toolBar->addWidget(snapshotToolButton);
    ToolButton* recordToolButton = new ToolButton;
    recordToolButton->setIcon(QIcon(":/images/record.svg"));
    recordToolButton->setToolTip(tr("Take record to a GIF file"));
    toolBar->addWidget(recordToolButton);
    toolBar->addSeparator();
    toolBar->setMovable(false);

    /* add a slider to the toolbar */
    QToolBar* sliderToolBar = addToolBar(tr("Speed Slider"));
    m_speedSlider = new QSlider(Qt::Horizontal);
    m_speedSlider->setRange(0, 100);
    m_speedSlider->setValue(m_speedSlider->maximum() >> 1);
    connect(m_speedSlider, &QSlider::valueChanged, this, &MainWindow::speedChangedSlot);
    sliderToolBar->setFixedWidth(240);
    sliderToolBar->addWidget(m_speedSlider);
    sliderToolBar->setMovable(false);
    QToolBar* emptyToolBar = addToolBar(tr("Empty"));
    emptyToolBar->setMovable(false);
}

void MainWindow::createNavWidget()
{
    m_searchLineEdit = new QLineEdit;
    m_searchLineEdit->setFixedHeight(26);
    m_searchLineEdit->setPlaceholderText(tr("Type here to search"));
    m_searchLineEdit->addAction(QIcon(":/images/search.svg"), QLineEdit::LeadingPosition);

    m_treeWidget = new TreeWidget;

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(m_searchLineEdit);
    vLayout->addWidget(m_treeWidget);
    vLayout->setSpacing(8);
    vLayout->setMargin(0);

    m_navWidget = new QWidget;
    m_navWidget->setFixedWidth(330);
    m_navWidget->setLayout(vLayout);
}

void MainWindow::createTabWidget()
{
    m_tabWidget = new QTabWidget;
    m_tabWidget->setTabsClosable(true);
    m_tabWidget->addTab(new BfsPane, QIcon(":/images/tab.svg"), "Ubuntu 02.00 x64 Dev");
    m_tabWidget->addTab(new QWidget, QIcon(":/images/tab.svg"), "Ubuntu 02.00 x64 Dev");
    m_tabWidget->addTab(new QWidget, QIcon(":/images/tab.svg"), "Ubuntu 03.00 x64 Origin");
    m_tabWidget->addTab(new QWidget, QIcon(":/images/tab.svg"), "Ubuntu 04.00 x64 Origin");

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(m_tabWidget);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0, 10, 0, 0);

    m_frame = new QFrame;
    m_frame->setFrameShape(QFrame::StyledPanel);
    m_frame->setLayout(vLayout);

    //tabCloseRequested
}

void MainWindow::play()
{

}

void MainWindow::pause()
{

}

void MainWindow::openSlot()
{

}

void MainWindow::exitSlot()
{

}

void MainWindow::homeTabSlot()
{

}

void MainWindow::nextTabSlot()
{

}

void MainWindow::previousTabSlot()
{

}

void MainWindow::changeLanguageSlot(QAction* action)
{
    m_lastLanguageAction->setIconVisibleInMenu(false);
    m_lastLanguageAction->setChecked(false);
    m_lastLanguageAction = action;
    action->setIconVisibleInMenu(true);
    action->setChecked(true);
}

void MainWindow::donateSlot()
{

}

void MainWindow::feedbackSlot()
{

}

void MainWindow::updateSlot()
{

}

void MainWindow::aboutSlot()
{

}

void MainWindow::playSlot()
{
    static bool isPlaySvg = true;

    if (isPlaySvg)
    {
        m_playToolButton->setIcon(QIcon(":/images/pause.svg"));
        play();
    }
    else
    {
        m_playToolButton->setIcon(QIcon(":/images/play.svg"));
        pause();
    }

    isPlaySvg = !isPlaySvg;
}

void MainWindow::replaySlot()
{

}

void MainWindow::restoreSlot()
{

}

void MainWindow::snapshotSlot()
{

}

void MainWindow::recordslot()
{

}

void MainWindow::speedChangedSlot(int value)
{
    /* avoid the handle to exceed the slider border */
    if (value < 2)
    {
        m_speedSlider->setValue(2);
    }
    else if (value > 98)
    {
        m_speedSlider->setValue(98);
    }

    //////
}
