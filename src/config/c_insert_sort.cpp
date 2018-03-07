#include "c_insert_sort.h"
#include <QHBoxLayout>

CONFIG_NAMESPACE_START

InsertSort::InsertSort(ConfigBase *parent) : ConfigBase(parent)
{
    startPushButton->setEnabled(true);
    pausePushButton->setEnabled(false);
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);

    randomGroupBox = new QGroupBox(tr("Random Generate"));
    spinBox        = new QSpinBox;
    pushButton1    = new QPushButton(tr("Generate"));
    spinBox->setRange(2, 15);
    spinBox->setValue(10);
    QHBoxLayout *hLayout1 = new QHBoxLayout(randomGroupBox);
    hLayout1->addWidget(spinBox);
    hLayout1->addWidget(pushButton1);
    hLayout1->setSpacing(40);

    customGroupBox = new QGroupBox(tr("or Custom Generate"));
    textEdit       = new QTextEdit;
    pushButton2    = new QPushButton(tr("      Generate      "));
    pushButton2->setEnabled(false);
    QHBoxLayout *hLayout2 = new QHBoxLayout;
    hLayout2->addStretch();
    hLayout2->addWidget(pushButton2);
    QVBoxLayout *vLayout1 = new QVBoxLayout(customGroupBox);
    vLayout1->addWidget(textEdit);
    vLayout1->addLayout(hLayout2);
    vLayout1->setSpacing(10);

    QVBoxLayout *vLayout2 = new QVBoxLayout(this);
    vLayout2->addWidget(randomGroupBox);
    vLayout2->addWidget(customGroupBox);
    vLayout2->addStretch();
    vLayout2->addWidget(groupBox1);
    vLayout2->addWidget(groupBox2);
    vLayout2->setSpacing(30);

    connect(startPushButton, SIGNAL(clicked(bool)), SLOT(start()));
    connect(pausePushButton, SIGNAL(clicked(bool)), SLOT(pause()));
    connect(resetPushButton, SIGNAL(clicked(bool)), SLOT(reset()));
    connect(replayPushButton, SIGNAL(clicked(bool)), SLOT(replay()));
    connect(pushButton1, SIGNAL(clicked(bool)), SLOT(emitNumber()));
    connect(pushButton2, SIGNAL(clicked(bool)), SLOT(emitString()));
    connect(pushButton1, SIGNAL(clicked(bool)), SLOT(pushButtonReset()));
    connect(pushButton2, SIGNAL(clicked(bool)), SLOT(pushButtonReset()));
    connect(textEdit, SIGNAL(textChanged()), SLOT(textValid()));
}

void InsertSort::start()
{
    randomGroupBox->setEnabled(false);
    customGroupBox->setEnabled(false);
    startPushButton->setEnabled(false);
    pausePushButton->setEnabled(true);

    emit comboBoxEnabled(false);
    emit startSignal();
}

void InsertSort::pause()
{
    if (pausePushButton->text() == QString("Pause"))
    {
        randomGroupBox->setEnabled(true);
        customGroupBox->setEnabled(true);
        pausePushButton->setText(tr("Continue"));
        resetPushButton->setEnabled(true);
        replayPushButton->setEnabled(true);

        emit comboBoxEnabled(true);
    }
    else
    {
        randomGroupBox->setEnabled(false);
        customGroupBox->setEnabled(false);
        pausePushButton->setText(tr("Pause"));
        resetPushButton->setEnabled(false);
        replayPushButton->setEnabled(false);

        emit comboBoxEnabled(false);
    }

    emit pauseSignal();
}

void InsertSort::reset()
{
    spinBox->setValue(10);
    textEdit->clear();
    pushButton2->setEnabled(false);

    startPushButton->setEnabled(true);
    pausePushButton->setEnabled(false);
    pausePushButton->setText(tr("Pause"));
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);
    speedSlider->setValue(50);

    emit comboBoxEnabled(true);
    emit resetSignal();
}

void InsertSort::replay()
{
    randomGroupBox->setEnabled(false);
    customGroupBox->setEnabled(false);
    pausePushButton->setEnabled(true);
    pausePushButton->setText(tr("Pause"));
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);

    emit comboBoxEnabled(false);
    emit replaySignal();
}

void InsertSort::finishedReset()
{
    randomGroupBox->setEnabled(true);
    customGroupBox->setEnabled(true);
    pausePushButton->setEnabled(false);
    resetPushButton->setEnabled(true);
    replayPushButton->setEnabled(true);

    emit comboBoxEnabled(true);
}

void InsertSort::pushButtonReset()
{
    startPushButton->setEnabled(true);
    pausePushButton->setEnabled(false);
    pausePushButton->setText(tr("Pause"));
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);
}

void InsertSort::emitNumber()
{
    emit generateByNumber(spinBox->value());
}

void InsertSort::emitString()
{
    emit generateByString(textEdit->toPlainText());
}

void InsertSort::textValid()
{
    QString text = textEdit->toPlainText();
    QRegExp re("(\\s)*\\d{1,2}((\\s)+\\d{1,2})*(\\s)+\\d{1,2}(\\s)*");

    if (re.exactMatch(text))
        pushButton2->setEnabled(true);
    else
        pushButton2->setEnabled(false);
}

CONFIG_NAMESPACE_END
