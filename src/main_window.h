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
    MainWindow(QWidget *parent = 0);

private:
    void createToolBar();
    void createNavWidget();
    void createTabWidget();

private slots:
    void rewardMeSlot();
    void feedbackSlot();
    void updateSlot();
    void aboutMeSlot();
    void aboutVASSlot();

private:
    QWidget*     m_centralWidget;
    QWidget*     m_navWidget;
    QTabWidget*  m_tabWidget;

    QTreeWidget* m_treeWidget;
    QLineEdit*   m_searchLineEdit;

    QSlider*     m_speedSlider;
};

#endif /* MAIN_WINDOW_H */
