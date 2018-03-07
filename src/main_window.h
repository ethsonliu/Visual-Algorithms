#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "display/d_bfs.h"
#include "display/d_dfs.h"
#include "display/d_insert_sort.h"
#include "display/d_single_linked_list.h"
#include "config/c_bfs.h"
#include "config/c_dfs.h"
#include "config/c_insert_sort.h"
#include "config/c_single_linked_list.h"
#include <QMainWindow>
#include <QAction>
#include <QSplitter>
#include <QList>
#include <QComboBox>
#include <QStackedWidget>
#include <QGraphicsView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void displayInit();
    void configInit();
    void setConnection();

public slots:
    void changeScene(int);
    void setComboBoxEnabled(bool);
    void reset(int);

private:
    QMenu          *helpMenu;

    QAction        *updateAction;
    QAction        *feedbackAction;
    QAction        *aboutAction;

    QSplitter      *splitter;
    QGraphicsView  *displayWidget;
    QWidget        *configWidget;

    Display::Bfs *bfsDisplay;
    Display::Dfs *dfsDisplay;
    Display::InsertSort *insertSortDisplay;
    Display::SingleLinkedList *singleLinkedListDisplay;

    Config::Bfs  *bfsConfig;
    Config::Dfs  *dfsConfig;
    Config::InsertSort *insertSortConfig;
    Config::SingleLinkedList *singleLinkedListConfig;

    QComboBox      *configComboBox;
    QStackedWidget *configStackWidget;

    QList<QGraphicsScene*> sceneList;
};

#endif // MAIN_WINDOW_H
