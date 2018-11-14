#include "tool_button.h"
#include <QHelpEvent>
#include <QToolTip>

ToolButton::ToolButton(QToolButton* parent) : QToolButton(parent)
{
}

bool ToolButton::event(QEvent* e)
{
    if (e->type() == QEvent::ToolTip)
    {
        QHelpEvent* helpEvent = static_cast<QHelpEvent*>(e);

        /* to adjust the the position of tooltip */
        if (helpEvent)
            QToolTip::showText(helpEvent->globalPos() + QPoint(-1 * this->width() / 2, 20), toolTip());

        return true;
    }

    return QWidget::event(e);
}
