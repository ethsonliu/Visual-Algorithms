#ifndef RECT_ITEM_H
#define RECT_ITEM_H

#include "config.h"
#include <QBrush>
#include <QGraphicsRectItem>

class RectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:

    RectItem(qreal x, qreal y, qreal width, qreal height);
    inline QColor brushColor() const { return brush().color(); }
    void setBorder(const QColor & color, int width = 1);

};

#endif /* RECT_ITEM_H */
