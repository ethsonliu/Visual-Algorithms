#ifndef SEARCH_BASE_H
#define SEARCH_BASE_H

#include <QList>
#include "rect_item.h"
#include "display_base.h"

class SearchBase : public DisplayScene
{
    Q_OBJECT

public:
    explicit SearchBase(DisplayScene *parent = 0) : DisplayScene(parent)
    {
        speed             = 250;
        mouseEventEnabled = true;
        isFinished        = false;
        itemWidth         = 30;
        rowNum            = sceneHeight / itemWidth;
        columnNum         = sceneWidth / itemWidth;
        startPos          = (rowNum / 2) * columnNum + columnNum / 2 - 5;
        endPos            = startPos + 10;
        itemsNum          = rowNum * columnNum;

        RectItem *item;
        for (int i = 0; i < rowNum; i++)
        {
            for (int j = 0; j < columnNum; j++)
            {
                item = new RectItem(j * itemWidth - sceneWidth / 2, i * itemWidth - sceneHeight / 2, itemWidth, itemWidth);
                this->addItem(item);
                list << item;
            }
        }

        list[startPos]->setItemColor(RectItem::GREEN);
        list[endPos]->setItemColor(RectItem::RED);
    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        if (mouseEventEnabled)
        {
            int x = (int)event->scenePos().x();
            int y = (int)event->scenePos().y();

            if (x >= -sceneWidth / 2 && x <= sceneWidth / 2 - 1 && y >= -sceneHeight / 2 && y <= sceneHeight / 2 - 1)
            {
                pre = (x + sceneWidth / 2) / itemWidth + (y + sceneHeight / 2) / itemWidth * columnNum;

                if (list[pre]->color == RectItem::WHITE)
                    list[pre]->setItemColor(RectItem::DARKGRAY);
                else if (list[pre]->color == RectItem::DARKGRAY)
                    list[pre]->setItemColor(RectItem::WHITE);
            }
        }
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        if (mouseEventEnabled)
        {
            int cx = (int)event->scenePos().x();
            int cy = (int)event->scenePos().y();

            if (cx >= -sceneWidth / 2 && cx <= sceneWidth / 2 - 1 && cy >= -sceneHeight / 2 && cy <= sceneHeight / 2 - 1)
            {

                int cur = (cx + sceneWidth / 2) / itemWidth + (cy + sceneHeight / 2) / itemWidth * columnNum;

                if (pre != cur)
                {
                    if (list[pre]->color == RectItem::RED || list[pre]->color == RectItem::GREEN)
                    {
                        if (list[cur]->color == RectItem::WHITE)
                        {
                            RectItem::Color temp = list[pre]->color;
                            list[pre]->setItemColor(RectItem::WHITE);
                            list[cur]->setItemColor(temp);
                            pre = cur;
                        }
                    }
                }
            }
        }
    }

public slots:
    void reset()
    {
        isReset           = true;
        mouseEventEnabled = true;

        for (int i = 0; i < itemsNum; i++)
            list[i]->setItemColor(RectItem::WHITE);

        list[startPos]->setItemColor(RectItem::GREEN);
        list[endPos]->setItemColor(RectItem::RED);
    }

    void changeSpeed(int speed)
    {
        this->speed = 500 - speed;
    }

protected:
    int  rowNum;
    int  columnNum;
    int  itemsNum;
    bool mouseEventEnabled;
    bool isFinished;
    QList<RectItem*> list;

private:
    int startPos;
    int endPos;
    int itemWidth;
    int pre;
};

#endif // SEARCH_BASE_H
