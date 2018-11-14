#ifndef TOOL_BUTTON_H
#define TOOL_BUTTON_H

#include <QToolButton>
#include <QEvent>

class ToolButton : public QToolButton
{
public:
    ToolButton(QToolButton* parent = nullptr);
    virtual bool event(QEvent* e);
};

#endif /* TOOL_BUTTON_H */
