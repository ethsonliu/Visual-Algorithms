#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private slots:
    void rewardMeSlot();
    void feedbackSlot();
    void updateSlot();
    void aboutMeSlot();
    void aboutVASSlot();

private:
    QWidget* m_centralWidget;
    QWidget* m_navWidget;
    QTabWidget* m_tabWidget;
};//qthread内定义gui widget

#endif /* MAIN_WINDOW_H */
