#ifndef CONFIG_BFS_H
#define CONFIG_BFS_H

#include <QTextEdit>
#include "config_base.h"

CONFIG_NAMESPACE_START

class BFS : public ConfigBase
{
    Q_OBJECT

public:
    explicit BFS(ConfigBase *parent = 0) : ConfigBase(parent)
    {
        speedSlider->setRange(0, 500);
        speedSlider->setValue(250);
        startPushButton->setEnabled(true);
        pausePushButton->setEnabled(false);
        resetPushButton->setEnabled(false);

        illustrationTextEdit = new QTextEdit;
        illustrationTextEdit->setPlainText(tr("Red Square      : the beginning\n"
                                              "Green Square    : the end\n"
                                              "DarkGray Square : the block"));
        illustrationTextEdit->setReadOnly(true);

        mainVBoxLayout = new QVBoxLayout(this);
        mainVBoxLayout->addWidget(illustrationTextEdit);
        mainVBoxLayout->addWidget(groupBox1);
        mainVBoxLayout->addWidget(groupBox2);
        mainVBoxLayout->setSpacing(30);
    }

public slots:
    void finishedReset()
    {
        startPushButton->setEnabled(false);
        pausePushButton->setEnabled(false);
        resetPushButton->setEnabled(true);
    }

private:
    QTextEdit   *illustrationTextEdit;
    QVBoxLayout *mainVBoxLayout;
};

CONFIG_NAMESPACE_END

#endif // CONFIG_BFS_H
