#include "c_single_linked_list.h"
#include <QHBoxLayout>

CONFIG_NAMESPACE_START

SingleLinkedList::SingleLinkedList(ConfigBase *parent) : ConfigBase(parent)
{
    startPushButton->setEnabled(false);
    pausePushButton->setEnabled(false);
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);

    insertWidget      = new QWidget;
    insertPosGroupBox = new QGroupBox(tr("Position"));
    insertKeyGroupBox = new QGroupBox(tr("Key"));
    headCheckBox1     = new QCheckBox(tr("head"));
    tailCheckBox1     = new QCheckBox(tr("tail"));
    keyLineEdit1      = new QLineEdit;
    customSpinBox1    = new QSpinBox;
    keyLineEdit1->setValidator(new QIntValidator(0, 99));
    customSpinBox1->setRange(2, 9);
    QHBoxLayout *hLayout1 = new QHBoxLayout(insertPosGroupBox);
    hLayout1->addWidget(headCheckBox1);
    hLayout1->addWidget(tailCheckBox1);
    hLayout1->addWidget(customSpinBox1);
    QHBoxLayout *hLayout2 = new QHBoxLayout(insertKeyGroupBox);
    hLayout2->addWidget(keyLineEdit1);
    QVBoxLayout *vLayout1 = new QVBoxLayout(insertWidget);
    vLayout1->addWidget(insertPosGroupBox);
    vLayout1->addWidget(insertKeyGroupBox);
    vLayout1->addStretch();
    vLayout1->setSpacing(20);

    findWidget       = new QWidget;
    findKeyGroupBox  = new QGroupBox(tr("Key"));
    keyLineEdit2     = new QLineEdit;
    keyLineEdit2->setValidator(new QIntValidator(0, 99));
    QHBoxLayout *hLayout3 = new QHBoxLayout(findKeyGroupBox);
    hLayout3->addWidget(keyLineEdit2);
    QVBoxLayout *vLayout2 = new QVBoxLayout(findWidget);
    vLayout2->addWidget(findKeyGroupBox);
    vLayout2->addStretch();

    removeWidget      = new QWidget;
    removePosGroupBox = new QGroupBox(tr("By Position"));
    removekeyGroupBox = new QGroupBox(tr("or By Key"));
    headCheckBox3     = new QCheckBox(tr("head"));
    tailCheckBox3     = new QCheckBox(tr("tail"));
    customSpinBox3    = new QSpinBox;
    keyLineEdit3      = new QLineEdit;
    keyLineEdit3->setValidator(new QIntValidator(0, 99));
    customSpinBox3->setRange(2, 9);
    QHBoxLayout *hLayout4 = new QHBoxLayout(removePosGroupBox);
    hLayout4->addWidget(headCheckBox3);
    hLayout4->addWidget(tailCheckBox3);
    hLayout4->addWidget(customSpinBox3);
    QHBoxLayout *hLayout5 = new QHBoxLayout(removekeyGroupBox);
    hLayout5->addWidget(keyLineEdit3);
    QVBoxLayout *vLayout3 = new QVBoxLayout(removeWidget);
    vLayout3->addWidget(removePosGroupBox);
    vLayout3->addWidget(removekeyGroupBox);
    vLayout3->addStretch();
    vLayout3->setSpacing(20);

    tabWidget = new QTabWidget;
    tabWidget->addTab(insertWidget, tr("Insert"));
    tabWidget->addTab(findWidget, tr("Find"));
    tabWidget->addTab(removeWidget, tr("Remove"));

    QVBoxLayout *mainVBoxLayout = new QVBoxLayout(this);
    mainVBoxLayout->addWidget(tabWidget);
    mainVBoxLayout->addWidget(groupBox1);
    mainVBoxLayout->addWidget(groupBox2);
    mainVBoxLayout->setSpacing(30);

    connect(startPushButton, SIGNAL(clicked(bool)), SLOT(start()));
    connect(pausePushButton, SIGNAL(clicked(bool)), SLOT(pause()));
    connect(resetPushButton, SIGNAL(clicked(bool)), SLOT(reset()));
    connect(replayPushButton, SIGNAL(clicked(bool)), SLOT(replay()));
    connect(headCheckBox1, SIGNAL(stateChanged(int)), SLOT(slot1(int)));
    connect(tailCheckBox1, SIGNAL(stateChanged(int)), SLOT(slot2(int)));
    connect(headCheckBox3, SIGNAL(stateChanged(int)), SLOT(slot3(int)));
    connect(tailCheckBox3, SIGNAL(stateChanged(int)), SLOT(slot4(int)));
    connect(keyLineEdit1, SIGNAL(textChanged(QString)), SLOT(slot5()));
    connect(keyLineEdit2, SIGNAL(textChanged(QString)), SLOT(slot6()));
    connect(keyLineEdit3, SIGNAL(textChanged(QString)), SLOT(slot7()));
    connect(tabWidget, SIGNAL(currentChanged(int)), SLOT(tabChangedReset(int)));
}

void SingleLinkedList::start()
{
    tabWidget->setEnabled(false);
    startPushButton->setEnabled(false);
    pausePushButton->setEnabled(true);

    emit comboBoxEnabled(false);

    int index = tabWidget->currentIndex();
    int k;
    switch (index)
    {
    case 0:
        if (headCheckBox1->checkState() == Qt::Checked)
            k = 1;
        else if (tailCheckBox1->checkState() == Qt::Checked)
            k = 0;
        else
            k = customSpinBox1->value();

        emit insertSignal(k, keyLineEdit1->text());
        break;
    case 1:
        emit findSignal(keyLineEdit2->text());
        break;
    case 2:
        if (keyLineEdit3->text().length() == 0)
        {
            if (headCheckBox3->checkState() == Qt::Checked)
                k = 1;
            else if (tailCheckBox3->checkState() == Qt::Checked)
                k = -1;
            else
                k = customSpinBox3->value();

            emit removeSignal(k);
        }
        else
            emit removeSignal(keyLineEdit3->text());
        break;
    }
}

void SingleLinkedList::pause()
{
    if (pausePushButton->text() == QString("Pause"))
    {
        pausePushButton->setText(tr("Continue"));
        resetPushButton->setEnabled(true);
        replayPushButton->setEnabled(true);

        emit comboBoxEnabled(true);
    }
    else
    {
        pausePushButton->setText(tr("Pause"));
        resetPushButton->setEnabled(false);
        replayPushButton->setEnabled(false);

        emit comboBoxEnabled(false);
    }

    emit pauseSignal();
}

void SingleLinkedList::reset()
{
    pausePushButton->setEnabled(false);
    pausePushButton->setText(tr("Pause"));
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);
    speedSlider->setValue(50);
    tabWidget->setEnabled(true);
    tabWidget->setCurrentIndex(0);

    // insertWidget reset
    headCheckBox1->setCheckState(Qt::Unchecked);
    tailCheckBox1->setCheckState(Qt::Unchecked);
    customSpinBox1->setValue(2);
    headCheckBox1->setEnabled(true);
    tailCheckBox1->setEnabled(true);
    customSpinBox1->setEnabled(true);
    keyLineEdit1->clear();

    // findWidget reset
    keyLineEdit2->clear();

    // removeWidget reset
    headCheckBox3->setCheckState(Qt::Unchecked);
    tailCheckBox3->setCheckState(Qt::Unchecked);
    customSpinBox3->setValue(2);
    headCheckBox3->setEnabled(true);
    tailCheckBox3->setEnabled(true);
    customSpinBox3->setEnabled(true);
    keyLineEdit3->clear();

    emit comboBoxEnabled(true);
    emit resetSignal();
}

void SingleLinkedList::replay()
{
    startPushButton->setEnabled(false);
    pausePushButton->setEnabled(true);
    pausePushButton->setText(tr("Pause"));
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);
    tabWidget->setEnabled(false);

    emit comboBoxEnabled(false);
    emit replaySignal();
}

void SingleLinkedList::slot1(int state)
{
    if (state == Qt::Checked)
    {
        tailCheckBox1->setCheckState(Qt::Unchecked);
        tailCheckBox1->setEnabled(false);
        customSpinBox1->setEnabled(false);
    }
    else
    {
        tailCheckBox1->setEnabled(true);
        customSpinBox1->setEnabled(true);
    }
}

void SingleLinkedList::slot2(int state)
{
    if (state == Qt::Checked)
    {
        headCheckBox1->setCheckState(Qt::Unchecked);
        headCheckBox1->setEnabled(false);
        customSpinBox1->setEnabled(false);
    }
    else
    {
        headCheckBox1->setEnabled(true);
        customSpinBox1->setEnabled(true);
    }
}

void SingleLinkedList::slot3(int state)
{
    if (state == Qt::Checked)
    {
        tailCheckBox3->setCheckState(Qt::Unchecked);
        tailCheckBox3->setEnabled(false);
        customSpinBox3->setEnabled(false);
        keyLineEdit3->setEnabled(false);
    }
    else
    {
        tailCheckBox3->setEnabled(true);
        customSpinBox3->setEnabled(true);
        keyLineEdit3->setEnabled(true);
    }
}

void SingleLinkedList::slot4(int state)
{
    if (state == Qt::Checked)
    {
        headCheckBox3->setCheckState(Qt::Unchecked);
        headCheckBox3->setEnabled(false);
        customSpinBox3->setEnabled(false);
        keyLineEdit3->setEnabled(false);
    }
    else
    {
        headCheckBox3->setEnabled(true);
        customSpinBox3->setEnabled(true);
        keyLineEdit3->setEnabled(true);
    }
}

void SingleLinkedList::slot5()
{
    if (keyLineEdit1->text().length())
        startPushButton->setEnabled(true);
    else
        startPushButton->setEnabled(false);
}

void SingleLinkedList::slot6()
{
    if (keyLineEdit2->text().length())
        startPushButton->setEnabled(true);
    else
        startPushButton->setEnabled(false);
}

void SingleLinkedList::slot7()
{
    if (keyLineEdit3->text().length())
        removePosGroupBox->setEnabled(false);
    else
        removePosGroupBox->setEnabled(true);
}

void SingleLinkedList::tabChangedReset(int index)
{
    startPushButton->setEnabled(true);
    pausePushButton->setEnabled(false);
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);

    switch (index)
    {
    case 0:
        if (!keyLineEdit1->text().length())
            startPushButton->setEnabled(false);
        break;
    case 1:
        if (!keyLineEdit2->text().length())
            startPushButton->setEnabled(false);
        break;
    case 2:
        break;
    }
}

void SingleLinkedList::finishedReset()
{
    tabWidget->setEnabled(true);
    startPushButton->setEnabled(true);
    pausePushButton->setEnabled(false);
    resetPushButton->setEnabled(true);
    replayPushButton->setEnabled(true);

    emit comboBoxEnabled(true);
}

void SingleLinkedList::runFailedReset()
{
    tabWidget->setEnabled(true);
    startPushButton->setEnabled(true);
    pausePushButton->setEnabled(false);
    resetPushButton->setEnabled(true);
    replayPushButton->setEnabled(false);

    emit comboBoxEnabled(true);
}

CONFIG_NAMESPACE_END
