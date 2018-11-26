#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "config.h"
#include "widgets/tree_widget.h"
#include "widgets/tool_button.h"
#include <QMainWindow>
#include <QTreeWidget>
#include <QLineEdit>
#include <QSlider>
#include <QEvent>

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
    void changeLanguageSlot(QAction* action);
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

    TreeWidget*  m_treeWidget;
    QLineEdit*   m_searchLineEdit;
    QSlider*     m_speedSlider;
    ToolButton*  m_playToolButton;
    QAction*     m_lastLanguageAction;
};

#endif /* MAIN_WINDOW_H */
