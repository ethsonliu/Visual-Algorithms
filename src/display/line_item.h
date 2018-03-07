#ifndef LINE_ITEM_H
#define LINE_ITEM_H

#include <QGraphicsLineItem>

class LineItem : public QObject, public QGraphicsLineItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    LineItem(qreal x1, qreal y1, qreal x2, qreal y2);
    void setColor(QColor color);
};

#endif // LINE_ITEM_H
