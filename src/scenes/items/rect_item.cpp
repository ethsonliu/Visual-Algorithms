#include "rect_item.h"
#include <QPen>

RectItem::RectItem(qreal x, qreal y, qreal width, qreal height) : QGraphicsRectItem(x, y, width, height)
{
}

void RectItem::setBorder(const QColor & borderColor, int borderWidth)
{
    QPen pen;
    pen.setColor(borderColor);
    pen.setWidth(borderWidth);
    setPen(pen);
}
