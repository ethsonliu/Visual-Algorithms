#ifndef C_INSERT_SORT_H
#define C_INSERT_SORT_H

#include "config_base.h"
#include <QSpinBox>
#include <QTextEdit>

CONFIG_NAMESPACE_START

class InsertSort : public ConfigBase
{
    Q_OBJECT

public:
    InsertSort(ConfigBase *parent = 0);

public slots:
    void start();
    void pause();
    void reset();
    void replay();
    void finishedReset();
    void pushButtonReset();
    void emitNumber();
    void emitString();
    void textValid();

signals:
    void generateByNumber(int num);
    void generateByString(QString text);

private:
    QGroupBox   *randomGroupBox;
    QGroupBox   *customGroupBox;

    QSpinBox    *spinBox;
    QTextEdit   *textEdit;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
};

CONFIG_NAMESPACE_END

#endif // C_INSERT_SORT_H
