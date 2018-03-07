#ifndef C_SINGLE_LINKED_LIST_H
#define C_SINGLE_LINKED_LIST_H

#include "config_base.h"
#include <QCheckBox>
#include <QSpinBox>
#include <QTabWidget>
#include <QLineEdit>

CONFIG_NAMESPACE_START

class SingleLinkedList : public ConfigBase
{
    Q_OBJECT

public:
    SingleLinkedList(ConfigBase *parent = 0);

public slots:
    void start();
    void pause();
    void reset();
    void replay();
    void slot1(int state);
    void slot2(int state);
    void slot3(int state);
    void slot4(int state);
    void slot5();
    void slot6();
    void slot7();
    void tabChangedReset(int index);
    void finishedReset();
    void runFailedReset();

signals:
    void insertSignal(int k, QString text);
    void findSignal(QString text);
    void removeSignal(int k);
    void removeSignal(QString text);

private:
    QTabWidget  *tabWidget;
    QWidget     *insertWidget;
    QWidget     *findWidget;
    QWidget     *removeWidget;

    QGroupBox   *insertPosGroupBox;
    QGroupBox   *insertKeyGroupBox;
    QCheckBox   *headCheckBox1;
    QCheckBox   *tailCheckBox1;
    QSpinBox    *customSpinBox1;
    QLineEdit   *keyLineEdit1;

    QGroupBox   *findKeyGroupBox;
    QLineEdit   *keyLineEdit2;

    QGroupBox   *removePosGroupBox;
    QGroupBox   *removekeyGroupBox;
    QCheckBox   *headCheckBox3;
    QCheckBox   *tailCheckBox3;
    QSpinBox    *customSpinBox3;
    QLineEdit   *keyLineEdit3;
};

CONFIG_NAMESPACE_END

#endif // C_SINGLE_LINKED_LIST_H
