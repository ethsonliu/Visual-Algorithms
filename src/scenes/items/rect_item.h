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
    inline QColor color() const { return brush().color(); }
    void setColor(const QColor & color);
};


#endif /* RECT_ITEM_H */
