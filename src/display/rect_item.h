#ifndef RECT_ITEM_H
#define RECT_ITEM_H

#include <QColor>
#include <QBrush>
#include <QString>
#include <QPainter>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class RectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    enum Color {WHITE = 1, GREEN = 2, RED = 3, DARKGRAY = 4, CYAN = 5};

    Color color;

    explicit RectItem(QGraphicsRectItem *parent = 0) : QGraphicsRectItem(parent)
    {
        color = WHITE;
    }

    RectItem(qreal x, qreal y, qreal width, qreal height) : QGraphicsRectItem(x, y, width, height)
    {
        color = WHITE;
    }

    void setItemColor(RectItem::Color color)
    {
        switch (color)
        {
        case WHITE:
        {
            this->setBrush(QColor(Qt::white));
            this->color= WHITE;
            break;
        }
        case GREEN:
        {
            this->setBrush(QColor(Qt::green));
            this->color = GREEN;
            break;
        }
        case RED:
        {
            this->setBrush(QColor(Qt::red));
            this->color = RED;
            break;
        }
        case DARKGRAY:
        {
            this->setBrush(QColor(Qt::darkGray));
            this->color = DARKGRAY;
            break;
        }
        case CYAN:
        {
            this->setBrush(QColor(Qt::cyan));
            this->color = CYAN;
            break;
        }
        }
    }
};

#endif // RECT_ITEM_H
