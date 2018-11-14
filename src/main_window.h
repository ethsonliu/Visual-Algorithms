#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "config.h"
#include <QMainWindow>
#include <QTreeWidget>
#include <QLineEdit>
#include <QSlider>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private:
    void createToolBar();
    void createNavWidget();
    void createTabWidget();
    void play();
    void pause();

private slots:
    void openSlot();
    void exitSlot();
    void homeTabSlot();
    void nextTabSlot();
    void previousTabSlot();
    void donateSlot();
    void feedbackSlot();
    void updateSlot();
    void aboutSlot();
    void playSlot();
    void replaySlot();
    void restoreSlot();
    void snapshotSlot();
    void recordslot();
    void speedChangedSlot(int value);

private:
    QWidget*     m_centralWidget;
    QWidget*     m_navWidget;
    QTabWidget*  m_tabWidget;

    QTreeWidget* m_treeWidget;
    QLineEdit*   m_searchLineEdit;

    QSlider*     m_speedSlider;
};

#endif /* MAIN_WINDOW_H */
