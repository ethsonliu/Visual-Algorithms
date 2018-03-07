#include "config_base.h"
#include <QGridLayout>

ConfigBase::ConfigBase(QWidget *parent) : QWidget(parent)
{
    groupBox1   = new QGroupBox(tr("Speed Control"));
    speedSlider = new QSlider(Qt::Horizontal);
    speedSlider->setRange(0, 100);
    speedSlider->setValue(50);
    connect(speedSlider, SIGNAL(valueChanged(int)), SIGNAL(sliderChanged(int)));
    QVBoxLayout *vLayout = new QVBoxLayout(groupBox1);
    vLayout->addWidget(speedSlider);

    groupBox2        = new QGroupBox(tr("Start && Pause"));
    startPushButton  = new QPushButton(tr("Start"));
    pausePushButton  = new QPushButton(tr("Pause"));
    resetPushButton  = new QPushButton(tr("Reset"));
    replayPushButton = new QPushButton(tr("Replay"));
    QGridLayout *gLayout = new QGridLayout(groupBox2);
    gLayout->addWidget(startPushButton, 0, 0, 1, 1);
    gLayout->addWidget(pausePushButton, 0, 1, 1, 1);
    gLayout->addWidget(resetPushButton, 1, 0, 1, 1);
    gLayout->addWidget(replayPushButton, 1, 1, 1, 1);
}
