#include "src/widget/tool_button.h"

#include <QHelpEvent>
#include <QToolTip>

ToolButton::ToolButton(QToolButton* parent) : QToolButton(parent)
{
}

bool ToolButton::event(QEvent* event)
{
    if (event->type() == QEvent::ToolTip)
    {
        QHelpEvent* helpEvent = static_cast<QHelpEvent*>(event);

        /* to adjust the the position of tooltip */
        if (helpEvent)
            QToolTip::showText(helpEvent->globalPos() + QPoint(-1 * this->width() / 2, 20), toolTip());

        return true;
    }

    return QWidget::event(event);
}
