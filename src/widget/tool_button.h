#ifndef VISUAL_ALGORITHMS_WIDGET_TOOL_BUTTON_H
#define VISUAL_ALGORITHMS_WIDGET_TOOL_BUTTON_H

#include "src/config.h"

#include <QToolButton>
#include <QEvent>

class ToolButton : public QToolButton
{

public:

    ToolButton(QToolButton* parent = nullptr);

    virtual bool event(QEvent* event);

};

#endif // VISUAL_ALGORITHMS_WIDGET_TOOL_BUTTON_H
