#ifndef C_SEARCH_BASE_H
#define C_SEARCH_BASE_H

#include "config_base.h"
#include <QTextEdit>

CONFIG_NAMESPACE_START

class SearchBase : public ConfigBase
{
    Q_OBJECT

public:
    SearchBase(ConfigBase *parent = 0);

public slots:
    void start();
    void pause();
    void reset();
    void replay();
    void finishedReset();

protected:
    QTextEdit *illustrationTextEdit;
};

CONFIG_NAMESPACE_END

#endif // C_SEARCH_BASE_H
