#ifndef RECT_ITEM_H
#define RECT_ITEM_H

#include <QBrush>
#include <QGraphicsRectItem>

class RectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    RectItem(qreal x, qreal y, qreal width, qreal height);
    QColor color();
    void setColor(QColor color);
};

#endif // RECT_ITEM_H
