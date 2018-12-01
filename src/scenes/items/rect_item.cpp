#include "rect_item.h"

RectItem::RectItem(qreal x, qreal y, qreal width, qreal height) : QGraphicsRectItem(x, y, width, height)
{
    setColor(Qt::white);
}

void RectItem::setColor(const QColor & color)
{
    setBrush(QBrush(color));
}
