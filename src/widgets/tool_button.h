#ifndef TOOL_BUTTON_H
#define TOOL_BUTTON_H

#include "config.h"
#include <QToolButton>
#include <QEvent>

class ToolButton : public QToolButton
{
public:
    ToolButton(QToolButton* parent = nullptr);
    virtual bool event(QEvent* event);
};

#endif /* TOOL_BUTTON_H */
