#include "rect_item.h"
#include <QPen>

RectItem::RectItem(qreal x, qreal y, qreal width, qreal height) : QGraphicsRectItem(x, y, width, height)
{
}

void RectItem::setBorder(const QColor & color, int width)
{
    QPen pen;
    pen.setColor(color);
    pen.setWidth(width);
    setPen(pen);
}
