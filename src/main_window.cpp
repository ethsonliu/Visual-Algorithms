#include "src/main_window.h"
#include "src/pane/bfs_pane.h"

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
    this->setStyleSheet("QMenu{font-size: 12px;}"
                        "QToolBar"
                                  "{"
                                      "background-color: white;"
                                      "border: none;"
                                  "}"
                        "QToolBar QToolButton"
                                              "{"
                                                  "margin: 2px;"
                                                  "padding: 0px 3px;"
                                              "}"
                                              "QToolBar QToolButton::hover"
                                              "{"
                                                  "background-color: rgb(239, 245, 253);"
                                                  "border-radius: 6px;"
                                                  "border: 1px solid rgb(219, 220, 220);"
                                              "}"
                                              "QToolBar QToolButton::pressed"
                                              "{"
                                                 "background-color: rgb(235, 236, 237);"
                                                  "border-radius: 6px;"
                                                  "border: 1px solid rgb(219, 220, 220);"
                                              "}");


    /* create menubar */
    QMenuBar* menuBar = new QMenuBar;
    QMenu* fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addAction(QIcon(":/open.svg"), tr("Open Source Code Directory..."), this, &MainWindow::openSlot);
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Exit"));
    QMenu* languagesMenu = menuBar->addMenu(tr("Languages"));
    connect(languagesMenu, &QMenu::triggered, this, &MainWindow::changeLanguageSlot);
    QAction* action = languagesMenu->addAction(tr("(System Language)"));
    action->setCheckable(true);
    action->setChecked(true);
    m_lastLanguageAction = action;
    languagesMenu->addSeparator();
    action = languagesMenu->addAction(tr("English"));
    action->setCheckable(true);
    action->setIconVisibleInMenu(false);
    action = languagesMenu->addAction(tr("Simplified Chinese"));
    action->setCheckable(true);
    action->setIconVisibleInMenu(false);
    QMenu* tabsMenu = menuBar->addMenu(tr("Tabs"));
    tabsMenu->addAction(QIcon(":/home.svg"), tr("Go to Home Tab"), this, &MainWindow::homeTabSlot);
    tabsMenu->addSeparator();
    tabsMenu->addAction(tr("Next Tab"), this, &MainWindow::nextTabSlot);
    tabsMenu->addAction(tr("Previous Tab"), this, &MainWindow::previousTabSlot);
    QMenu* donateMenu = menuBar->addMenu(tr("Donate"));
    donateMenu->addAction(QIcon(":/donate.png"), tr("Donate to Me"), this, &MainWindow::donateSlot);
    QMenu* helpMenu = menuBar->addMenu(tr("Help"));
    helpMenu->addAction(tr("Feedbacks"), this, &MainWindow::feedbackSlot);
    helpMenu->addAction(QIcon(":/update.svg"), tr("Software Updates"), this, &MainWindow::updateSlot);
    helpMenu->addSeparator();
    helpMenu->addAction(QIcon(":/app.ico"), tr("About Visual Algorithms"), this, &MainWindow::aboutSlot);
    menuBar->setFixedHeight(menuBar->minimumSizeHint().height());

    /* add the menubar to the toolbar */
    QToolBar* menuToolBar = addToolBar(tr("Menu"));
    menuToolBar->addWidget(menuBar);
    menuToolBar->setMovable(false);

    /* add toolbuttons to the toolbar */
    QToolBar* toolBar = addToolBar(tr("Tool"));
    toolBar->addSeparator();
    m_playToolButton = new ToolButton;
    m_playToolButton->setIcon(QIcon(":/play.svg"));
    connect(m_playToolButton, &ToolButton::clicked, this, &MainWindow::playSlot);
    toolBar->addWidget(m_playToolButton);
    toolBar->addSeparator();
    ToolButton* replayToolButton = new ToolButton;
    replayToolButton->setIcon(QIcon(":/replay.svg"));
    replayToolButton->setToolTip(tr("Replay the animation"));
    toolBar->addWidget(replayToolButton);
    ToolButton* restoreToolButton = new ToolButton;
    restoreToolButton->setIcon(QIcon(":/restore.svg"));
    restoreToolButton->setToolTip(tr("Restore to the initial state"));
    toolBar->addWidget(restoreToolButton);
    toolBar->addSeparator();
    ToolButton* snapshotToolButton = new ToolButton;
    snapshotToolButton->setIcon(QIcon(":/snapshot.svg"));
    snapshotToolButton->setToolTip(tr("Take a snapshot of the animation"));
    toolBar->addWidget(snapshotToolButton);
    ToolButton* recordToolButton = new ToolButton;
    recordToolButton->setIcon(QIcon(":/record.svg"));
    recordToolButton->setToolTip(tr("Take record to a GIF file"));
    toolBar->addWidget(recordToolButton);
    toolBar->addSeparator();
    toolBar->setMovable(false);

    /* add a slider to the toolbar */
    QToolBar* sliderToolBar = addToolBar(tr("Speed Slider"));
    m_speedSlider = new QSlider(Qt::Horizontal);
    m_speedSlider->setRange(0, 100);
    m_speedSlider->setValue(m_speedSlider->maximum() >> 1);
    m_speedSlider->setStyleSheet("QSlider"
    "{"
        "margin: 0px 4px;"
    "}"
    "QSlider::sub-page:horizontal"
    "{"
        "background-color: rgb(37, 168, 198);"
    "}"
    "QSlider::add-page:horizontal"
    "{"
        "background-color: rgb(78, 78, 78);"
    "}"
    "QSlider::groove:horizontal"
    "{"
        "background: transparent;"
        "height: 10px;"
    "}"
    "QSlider::handle:horizontal"
    "{"
        "border-image: url(:/slider_handle.png);"
        "margin: 0px -5px;"
    "}");
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
    m_searchLineEdit->addAction(QIcon(":/search.svg"), QLineEdit::LeadingPosition);
    m_searchLineEdit->setStyleSheet("font-size: 13px;");

    m_treeWidget = new TreeWidget;
    m_treeWidget->setStyleSheet("QTreeWidget"
    "{"
        "font-size: 13px;"
        "show-decoration-selected: 1;"
    "}");
    connect(m_treeWidget, &TreeWidget::itemDoubleClicked, this, &MainWindow::setCurrentPane);

    m_paneVec.reserve(m_treeWidget->itemCount());
    m_paneVec.fill(nullptr);

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
    m_tabWidget->setStyleSheet("QTabBar"
    "{"
        "border-bottom: none;"
        "font-size: 12px;"
        "font-weight: bold;"
    "}"

    "QTabBar::tab"
    "{"
        "font-weight: normal;"
       " background-color: rgb(235, 236, 237);"
       " border: 1px solid rgb(179, 179, 179);"
       " border-bottom: none;"
      "  border-top-left-radius: 4px;"
       " border-top-right-radius: 4px;"
       " padding: 6px;"
       " margin-left: 3px;"
    "}"

   " QTabBar::tab:first"
   " {"
       " margin-left: 5px;"
   " }"

    "QTabBar::tab:selected"
   " {"
        "font-weight: bold;"
        "background-color: white;"
    "}"

    "QTabBar::close-button"
   " {"
        "image: url(:/tab_close_normal.svg);"
    "}"

    "QTabBar::close-button:hover"
    "{"
        "image: url(:/tab_close_hover.svg);"
    "}"

    "QTabBar::scroller"
    "{"
        "border-left: 1px solid rgb(179, 179, 179);"
   " }"

    "QTabBar QToolButton"
    "{"
        "border: none;"
        "background-color: rgb(228, 229, 231);"
    "}"

   " QTabBar QToolButton::left-arrow"
  " {"
       " image: url(:/left_arrow_normal.svg);"
       " border-left: 1px solid rgb(179, 179, 179);"
    "}"

    "QTabBar QToolButton::left-arrow:disabled"
    "{"
       " image: url(:/left_arrow_disabled.svg);"
   " }"

    "QTabBar QToolButton::right-arrow"
    "{"
       " image: url(:/right_arrow_normal.svg);"
    "}"

    "QTabBar QToolButton::right-arrow:disabled"
    "{"
        "image: url(:/right_arrow_disabled.svg);"
   " }"

    "QTabWidget::pane"
   " {"
        "background-color: white;"
        "border-top: none;"
    "}");
    m_tabWidget->setTabsClosable(true);
    m_tabWidget->addTab(new BfsPane, QIcon(":/tab.svg"), "Ubuntu 02.00 x64 Dev");

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(m_tabWidget);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0, 10, 0, 0);

    m_frame = new QFrame;
    m_frame->setFrameShape(QFrame::StyledPanel);
    m_frame->setLayout(vLayout);

    //tabCloseRequested
}

BasePane* MainWindow::createPaneByFlag(AlgoFlag flag)
{
    BasePane* pane = nullptr;

    switch (flag)
    {
        case AlgoFlag::aStar:
        {
            break;
        }
        case AlgoFlag::breadthFirstSearch:
        {
            pane = new BfsPane;
            break;
        }
        case AlgoFlag::depthFirstSearch:
        {
            break;
        }
        default:
            break;
    }

    return pane;
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
        m_playToolButton->setIcon(QIcon(":/pause.svg"));
    }
    else
    {
        m_playToolButton->setIcon(QIcon(":/play.svg"));
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

void MainWindow::recordSlot()
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

void MainWindow::setCurrentPane(QTreeWidgetItem* item)
{
    AlgoFlag flag = m_treeWidget->indexByItem(item);

    if (nullptr == m_paneVec[flag])
        m_paneVec[flag] = createPaneByFlag(flag);

    m_tabWidget->setCurrentWidget(m_paneVec[flag]);
}
