#ifndef CONFIG_BASE_H
#define CONFIG_BASE_H

#include <QPushButton>
#include <QSlider>
#include <QGridLayout>
#include <QGroupBox>

#define CONFIG_NAMESPACE_START namespace Config {
#define CONFIG_NAMESPACE_END   }

class ConfigBase : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigBase(QWidget *parent = 0) : QWidget(parent)
    {
        groupBox1        = new QGroupBox(tr("Speed Control"));
        groupBox2        = new QGroupBox(tr("Start && Pause"));
        speedSlider      = new QSlider(Qt::Horizontal);
        startPushButton  = new QPushButton(tr("Start"));
        pausePushButton  = new QPushButton(tr("Pause"));
        resetPushButton  = new QPushButton(tr("Reset"));
        sliderLayout     = new QVBoxLayout(groupBox1);
        sliderLayout->addWidget(speedSlider);
        pushButtonLayout = new QGridLayout(groupBox2);
        pushButtonLayout->addWidget(startPushButton, 0, 0, 1, 1);
        pushButtonLayout->addWidget(pausePushButton, 0, 1, 1, 1);
        pushButtonLayout->addWidget(resetPushButton, 1, 0, 1, 1);

        connect(startPushButton, SIGNAL(clicked(bool)), SLOT(start()));
        connect(pausePushButton, SIGNAL(clicked(bool)), SLOT(pause()));
        connect(resetPushButton, SIGNAL(clicked(bool)), SLOT(reset()));
    }

public slots:
    void start()
    {
        startPushButton->setEnabled(false);
        pausePushButton->setEnabled(true);
        emit comboBoxEnabled(false);
    }

    void pause()
    {
        if (pausePushButton->text() == QString(QObject::tr("Pause")))
        {
            pausePushButton->setText(QObject::tr("Continue"));
            resetPushButton->setEnabled(true);
            emit comboBoxEnabled(true);
        }
        else
        {
            pausePushButton->setText(QObject::tr("Pause"));
            resetPushButton->setEnabled(false);
            emit comboBoxEnabled(false);
        }
    }

    void reset()
    {
        pausePushButton->setText(QObject::tr("Pause"));
        startPushButton->setEnabled(true);
        pausePushButton->setEnabled(false);
        resetPushButton->setEnabled(false);
        speedSlider->setValue(speedSlider->maximum() / 2);
        emit comboBoxEnabled(true);
    }

signals:
    void comboBoxEnabled(bool);

public:
    QPushButton *startPushButton;
    QPushButton *pausePushButton;
    QPushButton *resetPushButton;
    QSlider     *speedSlider;

protected:
    QGroupBox   *groupBox1;
    QGroupBox   *groupBox2;

private:
    QVBoxLayout *sliderLayout;
    QGridLayout *pushButtonLayout;
};

#endif // CONFIG_BASE_H
