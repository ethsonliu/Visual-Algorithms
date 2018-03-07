#ifndef CONFIG_BASE_H
#define CONFIG_BASE_H

#include <QPushButton>
#include <QSlider>
#include <QGroupBox>

#define CONFIG_NAMESPACE_START namespace Config {
#define CONFIG_NAMESPACE_END }

class ConfigBase : public QWidget
{
    Q_OBJECT

public:
    ConfigBase(QWidget *parent = 0);

signals:
    void comboBoxEnabled(bool);
    void startSignal();
    void pauseSignal();
    void resetSignal();
    void replaySignal();
    void sliderChanged(int);

protected:
    QGroupBox   *groupBox1;
    QGroupBox   *groupBox2;
    QSlider     *speedSlider;
    QPushButton *startPushButton;
    QPushButton *pausePushButton;
    QPushButton *resetPushButton;
    QPushButton *replayPushButton;
};

#endif // CONFIG_BASE_H
