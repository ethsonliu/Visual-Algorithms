#ifndef VISUAL_ALGORITHMS_MAIN_WINDOW_H
#define VISUAL_ALGORITHMS_MAIN_WINDOW_H

#include "src/config.h"
#include "src/widget/tree_widget.h"
#include "src/widget/tool_button.h"
#include "src/pane/base_pane.h"

#include <QMainWindow>

class QLineEdit;
class QSlider;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget* parent = nullptr);

private:

    QWidget*           m_centralWidget;
    QWidget*           m_navWidget;
    QFrame*            m_frame;
    QTabWidget*        m_tabWidget;
    TreeWidget*        m_treeWidget;
    QLineEdit*         m_searchLineEdit;
    QSlider*           m_speedSlider;
    ToolButton*        m_playToolButton;
    QAction*           m_lastLanguageAction;
    QVector<BasePane*> m_paneVec;

    void createToolBar();
    void createNavWidget();
    void createTabWidget();
    BasePane* createPaneByFlag(AlgoFlag flag);

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
    void recordSlot();
    void speedChangedSlot(int value);
    void setCurrentPane(QTreeWidgetItem* item);

};

#endif // VISUAL_ALGORITHMS_MAIN_WINDOW_H
