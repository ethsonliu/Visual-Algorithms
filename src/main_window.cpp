#include "main_window.h"

#include <QMenuBar>
#include <QSizePolicy>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("Visual Algorithms"));
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
    bfsDisplay              = new Display::Bfs;
    dfsDisplay              = new Display::Dfs;
    insertSortDisplay       = new Display::InsertSort;
    singleLinkedListDisplay = new Display::SingleLinkedList;

    displayWidget->setScene(bfsDisplay);

    sceneList << bfsDisplay;
    sceneList << dfsDisplay;
    sceneList << insertSortDisplay;
    sceneList << singleLinkedListDisplay;
}

void MainWindow::configInit()
{
    configComboBox = new QComboBox;
    configComboBox->setEditable(true);
    configComboBox->insertItem(0, tr("Breadth-First Search"));
    configComboBox->insertItem(1, tr("Depth-First Search"));
    configComboBox->insertItem(2, tr("Insert Sort"));
    configComboBox->insertItem(3, tr("Single Linked List"));

    bfsConfig              = new Config::Bfs;
    dfsConfig              = new Config::Dfs;
    insertSortConfig       = new Config::InsertSort;
    singleLinkedListConfig = new Config::SingleLinkedList;

    configStackWidget = new QStackedWidget;
    configStackWidget->addWidget(bfsConfig);
    configStackWidget->addWidget(dfsConfig);
    configStackWidget->addWidget(insertSortConfig);
    configStackWidget->addWidget(singleLinkedListConfig);

    QVBoxLayout *vLayout = new QVBoxLayout(configWidget);
    vLayout->addWidget(configComboBox);
    vLayout->addWidget(configStackWidget);
}

void MainWindow::setConnection()
{
    connect(configComboBox, SIGNAL(currentIndexChanged(int)), configStackWidget, SLOT(setCurrentIndex(int)));
    connect(configComboBox, SIGNAL(currentIndexChanged(int)), SLOT(changeScene(int)));
    connect(configComboBox, SIGNAL(currentIndexChanged(int)), SLOT(reset(int)));

    connect(bfsConfig, SIGNAL(startSignal()), bfsDisplay, SLOT(start()));
    connect(bfsConfig, SIGNAL(pauseSignal()), bfsDisplay, SLOT(pause()));
    connect(bfsConfig, SIGNAL(resetSignal()), bfsDisplay, SLOT(reset()));
    connect(bfsConfig, SIGNAL(replaySignal()), bfsDisplay, SLOT(replay()));
    connect(bfsConfig, SIGNAL(sliderChanged(int)), bfsDisplay, SLOT(changeSpeed(int)));
    connect(bfsDisplay, SIGNAL(finished()), bfsConfig, SLOT(finishedReset()));
    connect(bfsConfig, SIGNAL(comboBoxEnabled(bool)), SLOT(setComboBoxEnabled(bool)));

    connect(dfsConfig, SIGNAL(startSignal()), dfsDisplay, SLOT(start()));
    connect(dfsConfig, SIGNAL(pauseSignal()), dfsDisplay, SLOT(pause()));
    connect(dfsConfig, SIGNAL(resetSignal()), dfsDisplay, SLOT(reset()));
    connect(dfsConfig, SIGNAL(replaySignal()), dfsDisplay, SLOT(replay()));
    connect(dfsConfig, SIGNAL(sliderChanged(int)), dfsDisplay, SLOT(changeSpeed(int)));
    connect(dfsDisplay, SIGNAL(finished()), dfsConfig, SLOT(finishedReset()));
    connect(dfsConfig, SIGNAL(comboBoxEnabled(bool)), SLOT(setComboBoxEnabled(bool)));

    connect(insertSortConfig, SIGNAL(startSignal()), insertSortDisplay, SLOT(start()));
    connect(insertSortConfig, SIGNAL(pauseSignal()), insertSortDisplay, SLOT(pause()));
    connect(insertSortConfig, SIGNAL(resetSignal()), insertSortDisplay, SLOT(reset()));
    connect(insertSortConfig, SIGNAL(replaySignal()), insertSortDisplay, SLOT(replay()));
    connect(insertSortConfig, SIGNAL(sliderChanged(int)), insertSortDisplay, SLOT(changeSpeed(int)));
    connect(insertSortDisplay, SIGNAL(finished()), insertSortConfig, SLOT(finishedReset()));
    connect(insertSortConfig, SIGNAL(comboBoxEnabled(bool)), SLOT(setComboBoxEnabled(bool)));
    connect(insertSortConfig, SIGNAL(generateByNumber(int)), insertSortDisplay, SLOT(generate(int)));
    connect(insertSortConfig, SIGNAL(generateByString(QString)), insertSortDisplay, SLOT(generate(QString)));

    connect(singleLinkedListConfig, SIGNAL(insertSignal(int, QString)), singleLinkedListDisplay, SLOT(insert(int, QString)));
    connect(singleLinkedListConfig, SIGNAL(findSignal(QString)), singleLinkedListDisplay, SLOT(find(QString)));
    connect(singleLinkedListConfig, SIGNAL(removeSignal(int)), singleLinkedListDisplay, SLOT(remove(int)));
    connect(singleLinkedListConfig, SIGNAL(removeSignal(QString)), singleLinkedListDisplay, SLOT(remove(QString)));
    connect(singleLinkedListConfig, SIGNAL(pauseSignal()), singleLinkedListDisplay, SLOT(pause()));
    connect(singleLinkedListConfig, SIGNAL(resetSignal()), singleLinkedListDisplay, SLOT(reset()));
    connect(singleLinkedListConfig, SIGNAL(replaySignal()), singleLinkedListDisplay, SLOT(replay()));
    connect(singleLinkedListConfig, SIGNAL(sliderChanged(int)), singleLinkedListDisplay, SLOT(changeSpeed(int)));
    connect(singleLinkedListDisplay, SIGNAL(finished()), singleLinkedListConfig, SLOT(finishedReset()));
    connect(singleLinkedListConfig, SIGNAL(comboBoxEnabled(bool)), SLOT(setComboBoxEnabled(bool)));
    connect(singleLinkedListDisplay, SIGNAL(runFailed()), singleLinkedListConfig, SLOT(runFailedReset()));
}

void MainWindow::changeScene(int i)
{
    displayWidget->setScene(sceneList[i]);
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
        bfsConfig->reset();
        bfsDisplay->reset();
        break;
    case 1:
        dfsConfig->reset();
        dfsDisplay->reset();
        break;
    case 2:
        insertSortConfig->reset();
        insertSortDisplay->reset();
        break;
    }
}
