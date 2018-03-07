#include "rect_item.h"

RectItem::RectItem(qreal x, qreal y, qreal width, qreal height) : QGraphicsRectItem(x, y, width, height)
{
    setColor(Qt::white);
}

QColor RectItem::color()
{
    return brush().color();
}

void RectItem::setColor(QColor color)
{
    setBrush(QBrush(color));
}
