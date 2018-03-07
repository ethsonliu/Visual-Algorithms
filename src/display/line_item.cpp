#include "line_item.h"
#include <QPen>

LineItem::LineItem(qreal x1, qreal y1, qreal x2, qreal y2) : QGraphicsLineItem(x1, y1, x2, y2)
{
    setColor(Qt::black);
}

void LineItem::setColor(QColor color)
{
    QPen pen(color);
    pen.setWidth(1);
    setPen(pen);
}
