#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QSplitter>
#include <QList>
#include <QComboBox>
#include <QStackedWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "display/dfs_d.h"
#include "display/bfs_d.h"
#include "display/single_linked_list_d.h"
#include "config/dfs_c.h"
#include "config/bfs_c.h"
#include "config/single_linked_list_c.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void displayInit();
    void configInit();
    void setConnection();
    ~MainWindow();

public slots:
    void changeScene(int);
    void setComboBoxEnabled(bool);
    void reset(int);

private:
    QAction        *updateAction;
    QAction        *feedbackAction;
    QAction        *aboutAction;

    QMenu          *helpMenu;

    QSplitter      *splitter;
    QGraphicsView  *displayWidget;
    QWidget        *configWidget;

    Display::DFS              *dfsDisplay;
    Display::BFS              *bfsDisplay;
    Display::SingleLinkedList *singleLinkedListDisplay;

    Config::DFS              *dfsConfig;
    Config::BFS              *bfsConfig;
    Config::SingleLinkedList *singleLinkedListConfig;

    QComboBox      *configComboBox;
    QStackedWidget *configStackWidget;

    QList<QGraphicsScene*> list;
};

#endif // MAIN_WINDOW_H
