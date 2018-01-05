#include <QMenuBar>
#include <QSizePolicy>
#include <QVBoxLayout>
#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("Dancing Algorithms"));
    setWindowState(Qt::WindowMaximized);
    setMinimumSize(1300, 800);

    updateAction   = new QAction(tr("Check for Updates..."), this);
    feedbackAction = new QAction(tr("Report a Problem"), this);
    aboutAction    = new QAction(tr("About Dancing Algorithms"), this);

    helpMenu = menuBar()->addMenu(tr("Help"));
    helpMenu->addAction(updateAction);
    helpMenu->addSeparator();
    helpMenu->addAction(feedbackAction);
    helpMenu->addSeparator();
    helpMenu->addAction(aboutAction);

    splitter = new QSplitter(Qt::Horizontal);
    splitter->setHandleWidth(1);
    displayWidget = new QGraphicsView(splitter);
    configWidget  = new QWidget(splitter);

    displayInit();
    configInit();
    setConnection();

    splitter->setStretchFactor(0, 4);
    splitter->setStretchFactor(1, 6);

    setCentralWidget(splitter);
}

void MainWindow::displayInit()
{
    dfsDisplay              = new Display::DFS;
    bfsDisplay              = new Display::BFS;
    singleLinkedListDisplay = new Display::SingleLinkedList;
    insertSortDisplay       = new Display::InsertSort;

    displayWidget->setScene(dfsDisplay);

    list << dfsDisplay;
    list << bfsDisplay;
    list << singleLinkedListDisplay;
    list << insertSortDisplay;
}

void MainWindow::configInit()
{
    configComboBox = new QComboBox;
    configComboBox->setEditable(true);
    configComboBox->insertItem(0, tr("DFS"));
    configComboBox->insertItem(1, tr("BFS"));
    configComboBox->insertItem(2, tr("Single Linked List"));
    configComboBox->insertItem(3, tr("Insert Sort"));

    dfsConfig              = new Config::DFS;
    bfsConfig              = new Config::BFS;
    singleLinkedListConfig = new Config::SingleLinkedList;

    configStackWidget = new QStackedWidget;
    configStackWidget->addWidget(dfsConfig);
    configStackWidget->addWidget(bfsConfig);
    configStackWidget->addWidget(singleLinkedListConfig);

    QVBoxLayout *configLayout = new QVBoxLayout(configWidget);
    configLayout->addWidget(configComboBox);
    configLayout->addWidget(configStackWidget);
}

void MainWindow::setConnection()
{
    connect(configComboBox, SIGNAL(currentIndexChanged(int)), configStackWidget, SLOT(setCurrentIndex(int)));
    connect(configComboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeScene(int)));
    connect(configComboBox, SIGNAL(currentIndexChanged(int)), SLOT(reset(int)));

    connect(dfsConfig->startPushButton, SIGNAL(clicked(bool)), dfsDisplay, SLOT(start_dfs()));
    connect(dfsConfig->pausePushButton, SIGNAL(clicked(bool)), dfsDisplay, SLOT(pause()));
    connect(dfsConfig->resetPushButton, SIGNAL(clicked(bool)), dfsDisplay, SLOT(reset()));
    connect(dfsConfig->speedSlider, SIGNAL(valueChanged(int)), dfsDisplay, SLOT(changeSpeed(int)));
    connect(dfsConfig, SIGNAL(comboBoxEnabled(bool)), SLOT(setComboBoxEnabled(bool)));
    connect(dfsDisplay, SIGNAL(finished()), dfsConfig, SLOT(finishedReset()));

    connect(bfsConfig->startPushButton, SIGNAL(clicked(bool)), bfsDisplay, SLOT(start_bfs()));
    connect(bfsConfig->pausePushButton, SIGNAL(clicked(bool)), bfsDisplay, SLOT(pause()));
    connect(bfsConfig->resetPushButton, SIGNAL(clicked(bool)), bfsDisplay, SLOT(reset()));
    connect(bfsConfig->speedSlider, SIGNAL(valueChanged(int)), bfsDisplay, SLOT(changeSpeed(int)));
    connect(bfsConfig, SIGNAL(comboBoxEnabled(bool)), SLOT(setComboBoxEnabled(bool)));
    connect(bfsDisplay, SIGNAL(finished()), bfsConfig, SLOT(finishedReset()));

    connect(singleLinkedListConfig->pausePushButton, SIGNAL(clicked(bool)), singleLinkedListDisplay, SLOT(pause()));
    connect(singleLinkedListConfig->resetPushButton, SIGNAL(clicked(bool)), singleLinkedListDisplay, SLOT(reset()));
    connect(singleLinkedListConfig->speedSlider, SIGNAL(valueChanged(int)), singleLinkedListDisplay, SLOT(changeSpeed(int)));
    connect(singleLinkedListConfig, SIGNAL(insertSignal(int, QString)), singleLinkedListDisplay, SLOT(insert(int, QString)));
    connect(singleLinkedListConfig, SIGNAL(findSignal(QString)), singleLinkedListDisplay, SLOT(find(QString)));
    connect(singleLinkedListConfig, SIGNAL(removeSignal(int)), singleLinkedListDisplay, SLOT(remove(int)));
    connect(singleLinkedListConfig, SIGNAL(removeSignal(QString)), singleLinkedListDisplay, SLOT(remove(QString)));
    connect(singleLinkedListDisplay, SIGNAL(finished()), singleLinkedListConfig, SLOT(finishedReset()));
    connect(singleLinkedListDisplay, SIGNAL(runFailed(bool)), singleLinkedListConfig, SLOT(runFailedReset(bool)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::changeScene(int i)
{
    displayWidget->setScene(list[i]);
}

void MainWindow::setComboBoxEnabled(bool isEnabled)
{
    configComboBox->setEnabled(isEnabled);
}

void MainWindow::reset(int i)
{
    switch (i)
    {
    case 0:
        dfsConfig->reset();
        dfsDisplay->reset();
        break;
    case 1:
        bfsConfig->reset();
        bfsDisplay->reset();
        break;
    case 2:
        singleLinkedListConfig->resetAll();
        singleLinkedListDisplay->reset();
        break;
    }
}
