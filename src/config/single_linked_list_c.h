#ifndef CONFIG_SINGLE_LINKED_LIST
#define CONFIG_SINGLE_LINKED_LIST

#include <QCheckBox>
#include <QSpinBox>
#include <QTabWidget>
#include <QTextEdit>
#include "config_base.h"

CONFIG_NAMESPACE_START

class SingleLinkedList : public ConfigBase
{
    Q_OBJECT

public:
    explicit SingleLinkedList(ConfigBase *parent = 0) : ConfigBase(parent)
    {
        speedSlider->setRange(0, 3000);
        speedSlider->setValue(1500);
        startPushButton->setEnabled(false);
        pausePushButton->setEnabled(false);
        resetPushButton->setEnabled(false);

        insertWidget      = new QWidget;
        insertPosGroupBox = new QGroupBox(tr("Position"));
        insertKeyGroupBox = new QGroupBox(tr("Key"));
        headCheckBox1     = new QCheckBox(tr("head"));
        tailCheckBox1     = new QCheckBox(tr("tail"));
        keyTextEdit1      = new QTextEdit;
        customSpinBox1    = new QSpinBox;
        keyTextEdit1->setPlaceholderText(tr("key text edit"));
        customSpinBox1->setRange(1, 10);
        QHBoxLayout *hBoxLayout1 = new QHBoxLayout(insertPosGroupBox);
        hBoxLayout1->addWidget(headCheckBox1);
        hBoxLayout1->addWidget(tailCheckBox1);
        hBoxLayout1->addWidget(customSpinBox1);
        QHBoxLayout *hBoxLayout2 = new QHBoxLayout(insertKeyGroupBox);
        hBoxLayout2->addWidget(keyTextEdit1);
        QVBoxLayout *vBoxLayout1 = new QVBoxLayout(insertWidget);
        vBoxLayout1->addWidget(insertPosGroupBox);
        vBoxLayout1->addWidget(insertKeyGroupBox);
        vBoxLayout1->setSpacing(20);

        findWidget       = new QWidget;
        findKeyGroupBox  = new QGroupBox(tr("Key"));
        keyTextEdit2     = new QTextEdit;
        keyTextEdit2->setPlaceholderText(tr("key text edit"));
        QHBoxLayout *hBoxLayout3 = new QHBoxLayout(findKeyGroupBox);
        hBoxLayout3->addWidget(keyTextEdit2);
        QVBoxLayout *vBoxLayout2 = new QVBoxLayout(findWidget);
        vBoxLayout2->addWidget(findKeyGroupBox);

        removeWidget      = new QWidget;
        removePosGroupBox = new QGroupBox(tr("By Position"));
        removekeyGroupBox = new QGroupBox(tr("or By Key"));
        headCheckBox3     = new QCheckBox(tr("head"));
        tailCheckBox3     = new QCheckBox(tr("tail"));
        customSpinBox3    = new QSpinBox;
        keyTextEdit3      = new QTextEdit;
        customSpinBox3->setRange(1, 10);
        keyTextEdit3->setPlaceholderText(tr("text edit"));
        QHBoxLayout *hBoxLayout4 = new QHBoxLayout(removePosGroupBox);
        hBoxLayout4->addWidget(headCheckBox3);
        hBoxLayout4->addWidget(tailCheckBox3);
        hBoxLayout4->addWidget(customSpinBox3);
        QHBoxLayout *hBoxLayout5 = new QHBoxLayout(removekeyGroupBox);
        hBoxLayout5->addWidget(keyTextEdit3);
        QVBoxLayout *vBoxLayout3 = new QVBoxLayout(removeWidget);
        vBoxLayout3->addWidget(removePosGroupBox);
        vBoxLayout3->addWidget(removekeyGroupBox);
        vBoxLayout3->setSpacing(20);

        tabWidget = new QTabWidget;
        tabWidget->addTab(insertWidget, tr("Insert"));
        tabWidget->addTab(findWidget, tr("Find"));
        tabWidget->addTab(removeWidget, tr("Remove"));

        mainVBoxLayout = new QVBoxLayout(this);
        mainVBoxLayout->addWidget(tabWidget);
        mainVBoxLayout->addWidget(groupBox1);
        mainVBoxLayout->addWidget(groupBox2);
        mainVBoxLayout->setSpacing(30);

        connect(headCheckBox1, SIGNAL(stateChanged(int)), SLOT(slot1(int)));
        connect(tailCheckBox1, SIGNAL(stateChanged(int)), SLOT(slot2(int)));
        connect(headCheckBox3, SIGNAL(stateChanged(int)), SLOT(slot3(int)));
        connect(tailCheckBox3, SIGNAL(stateChanged(int)), SLOT(slot4(int)));
        connect(tabWidget, SIGNAL(currentChanged(int)), SLOT(tabChangedReset(int)));
        connect(keyTextEdit1, SIGNAL(textChanged()), SLOT(slot5()));
        connect(keyTextEdit2, SIGNAL(textChanged()), SLOT(slot6()));
        connect(keyTextEdit3, SIGNAL(textChanged()), SLOT(slot7()));
        connect(startPushButton, SIGNAL(clicked(bool)), SLOT(startRun()));
    }

public slots:
    void slot1(int state)
    {
        if (state == Qt::Checked)
        {
            tailCheckBox1->setCheckState(Qt::Unchecked);
            customSpinBox1->setValue(1);
            tailCheckBox1->setEnabled(false);
            customSpinBox1->setEnabled(false);
        }
        else
        {
            tailCheckBox1->setEnabled(true);
            customSpinBox1->setEnabled(true);
        }
    }

    void slot2(int state)
    {
        if (state == Qt::Checked)
        {
            headCheckBox1->setCheckState(Qt::Unchecked);
            customSpinBox1->setValue(1);
            headCheckBox1->setEnabled(false);
            customSpinBox1->setEnabled(false);
        }
        else
        {
            headCheckBox1->setEnabled(true);
            customSpinBox1->setEnabled(true);
        }
    }

    void slot3(int state)
    {
        if (state == Qt::Checked)
        {
            tailCheckBox3->setCheckState(Qt::Unchecked);
            customSpinBox3->setValue(1);
            tailCheckBox3->setEnabled(false);
            customSpinBox3->setEnabled(false);
            keyTextEdit3->clear();
            keyTextEdit3->setEnabled(false);
        }
        else
        {
            tailCheckBox3->setEnabled(true);
            customSpinBox3->setEnabled(true);
            keyTextEdit3->setEnabled(true);
        }
    }

    void slot4(int state)
    {
        if (state == Qt::Checked)
        {
            headCheckBox3->setCheckState(Qt::Unchecked);
            customSpinBox3->setValue(1);
            headCheckBox3->setEnabled(false);
            customSpinBox3->setEnabled(false);
            keyTextEdit3->clear();
            keyTextEdit3->setEnabled(false);
        }
        else
        {
            headCheckBox3->setEnabled(true);
            customSpinBox3->setEnabled(true);
            keyTextEdit3->setEnabled(true);
        }
    }

    void slot5()
    {
        QString key = keyTextEdit1->toPlainText();
        int len = key.size();

        if (len >= 1 && len <= 2)
        {
            for (int i = 0; i < len; i++)
            {
                if (!(key[i] >= '0' && key[i] <= '9'))
                {
                    startPushButton->setEnabled(false);
                    return;
                }
            }
            startPushButton->setEnabled(true);
        }
        else
            startPushButton->setEnabled(false);
    }

    void slot6()
    {
        QString key = keyTextEdit2->toPlainText();
        int len = key.size();

        if (len >= 1 && len <= 2)
        {
            for (int i = 0; i < len; i++)
            {
                if (!(key[i] >= '0' && key[i] <= '9'))
                {
                    startPushButton->setEnabled(false);
                    return;
                }
            }
            startPushButton->setEnabled(true);
        }
        else
            startPushButton->setEnabled(false);
    }

    void slot7()
    {
        QString key = keyTextEdit3->toPlainText();
        int len = key.size();

        if (len == 0)
        {
            if (headCheckBox3->checkState() == Qt::Unchecked && tailCheckBox3->checkState() == Qt::Unchecked)
            {
                headCheckBox3->setEnabled(true);
                tailCheckBox3->setEnabled(true);
                customSpinBox3->setEnabled(true);
                return;
            }
        }
        else
        {
            headCheckBox3->setEnabled(false);
            headCheckBox3->setCheckState(Qt::Unchecked);
            tailCheckBox3->setEnabled(false);
            tailCheckBox3->setCheckState(Qt::Unchecked);
            customSpinBox3->setValue(1);
            customSpinBox3->setEnabled(false);

            if (len >= 1 && len <= 2)
            {
                for (int i = 0; i < len; i++)
                {
                    if (!(key[i] >= '0' && key[i] <= '9'))
                    {
                        startPushButton->setEnabled(false);
                        return;
                    }
                }

                startPushButton->setEnabled(true);
            }
            else
                startPushButton->setEnabled(false);
        }
    }

    void startRun()
    {
        int index = tabWidget->currentIndex();

        switch (index)
        {
        case 0:
            int k;
            if (headCheckBox1->checkState() == Qt::Checked)
                k = 1;
            else if (tailCheckBox1->checkState() == Qt::Checked)
                k = 0;
            else
                k = customSpinBox1->value();
            emit insertSignal(k, keyTextEdit1->toPlainText());
            break;
        case 1:
            emit findSignal(keyTextEdit2->toPlainText());
            break;
        case 2:
            if (keyTextEdit3->toPlainText() == "")
            {
                int k;
                if (headCheckBox3->checkState() == Qt::Checked)
                    k = 1;
                else if (tailCheckBox3->checkState() == Qt::Checked)
                    k = -1;
                else
                    k = customSpinBox3->value();
                emit removeSignal(k);
            }
            else
                emit removeSignal(keyTextEdit3->toPlainText());
            break;
        }
    }

    void insertWidgetReset()
    {
        headCheckBox1->setCheckState(Qt::Unchecked);
        tailCheckBox1->setCheckState(Qt::Unchecked);
        customSpinBox1->setValue(1);
        headCheckBox1->setEnabled(true);
        tailCheckBox1->setEnabled(true);
        customSpinBox1->setEnabled(true);
        keyTextEdit1->clear();
    }

    void findWidgetReset()
    {
        keyTextEdit2->clear();
    }

    void removeWidgetReset()
    {
        headCheckBox3->setCheckState(Qt::Unchecked);
        tailCheckBox3->setCheckState(Qt::Unchecked);
        customSpinBox3->setValue(1);
        headCheckBox3->setEnabled(true);
        tailCheckBox3->setEnabled(true);
        customSpinBox3->setEnabled(true);
        keyTextEdit3->clear();
    }

    void tabChangedReset(int index)
    {
        pausePushButton->setEnabled(false);
        resetPushButton->setEnabled(true);
        pausePushButton->setText(QObject::tr("Pause"));

        switch (index)
        {
        case 0:
            insertWidgetReset();
            startPushButton->setEnabled(false);
            break;
        case 1:
            findWidgetReset();
            startPushButton->setEnabled(false);
            break;
        case 2:
            removeWidgetReset();
            startPushButton->setEnabled(true);
            break;
        }
    }

    void resetAll()
    {
        reset();
        startPushButton->setEnabled(false);
        insertWidgetReset();
        findWidgetReset();
        removeWidgetReset();
        tabWidget->setCurrentIndex(0);
    }

    void finishedReset()
    {
        startPushButton->setEnabled(true);
        pausePushButton->setEnabled(false);
        resetPushButton->setEnabled(true);
    }

    void runFailedReset()
    {
        startPushButton->setEnabled(false);
        pausePushButton->setEnabled(false);
        resetPushButton->setEnabled(true);
    }

signals:
    void insertSignal(int k, QString text);
    void findSignal(QString text);
    void removeSignal(int k);
    void removeSignal(QString text);

private:
    QVBoxLayout *mainVBoxLayout;

    QTabWidget  *tabWidget;
    QWidget     *insertWidget;
    QWidget     *findWidget;
    QWidget     *removeWidget;

    QGroupBox   *insertPosGroupBox;
    QGroupBox   *insertKeyGroupBox;
    QCheckBox   *headCheckBox1;
    QCheckBox   *tailCheckBox1;
    QSpinBox    *customSpinBox1;
    QTextEdit   *keyTextEdit1;

    QGroupBox   *findKeyGroupBox;
    QTextEdit   *keyTextEdit2;

    QGroupBox   *removePosGroupBox;
    QGroupBox   *removekeyGroupBox;
    QCheckBox   *headCheckBox3;
    QCheckBox   *tailCheckBox3;
    QSpinBox    *customSpinBox3;
    QTextEdit   *keyTextEdit3;
};

CONFIG_NAMESPACE_END

#endif // CONFIG_SINGLE_LINKED_LIST
