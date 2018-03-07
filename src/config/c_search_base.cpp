#include "c_search_base.h"
#include <QVBoxLayout>

CONFIG_NAMESPACE_START

SearchBase::SearchBase(ConfigBase *parent) : ConfigBase(parent)
{
    startPushButton->setEnabled(true);
    pausePushButton->setEnabled(false);
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);

    illustrationTextEdit = new QTextEdit;
    illustrationTextEdit->setReadOnly(true);

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(illustrationTextEdit);
    vLayout->addWidget(groupBox1);
    vLayout->addWidget(groupBox2);
    vLayout->setSpacing(30);

    connect(startPushButton, SIGNAL(clicked(bool)), SLOT(start()));
    connect(pausePushButton, SIGNAL(clicked(bool)), SLOT(pause()));
    connect(resetPushButton, SIGNAL(clicked(bool)), SLOT(reset()));
    connect(replayPushButton, SIGNAL(clicked(bool)), SLOT(replay()));
}

void SearchBase::start()
{
    startPushButton->setEnabled(false);
    pausePushButton->setEnabled(true);

    emit comboBoxEnabled(false);
    emit startSignal();
}

void SearchBase::pause()
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

void SearchBase::reset()
{
    startPushButton->setEnabled(true);
    pausePushButton->setEnabled(false);
    pausePushButton->setText(tr("Pause"));
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);
    speedSlider->setValue(50);

    emit comboBoxEnabled(true);
    emit resetSignal();
}

void SearchBase::replay()
{
    pausePushButton->setEnabled(true);
    pausePushButton->setText(tr("Pause"));
    resetPushButton->setEnabled(false);
    replayPushButton->setEnabled(false);

    emit comboBoxEnabled(false);
    emit replaySignal();
}


void SearchBase::finishedReset()
{
    pausePushButton->setEnabled(false);
    resetPushButton->setEnabled(true);
    replayPushButton->setEnabled(true);

    emit comboBoxEnabled(true);
}

CONFIG_NAMESPACE_END
