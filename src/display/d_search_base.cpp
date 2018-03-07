#include "d_search_base.h"

DISPLAY_NAMESPACE_START

SearchBase::SearchBase(DisplayScene *parent) : DisplayScene(parent)
{
    mouseEventEnabled = true;
    runningTime       = 0;
    intervalTime      = 100;
    itemWidth         = 30;
    rowNum            = sceneHeight / itemWidth;
    columnNum         = sceneWidth / itemWidth;
    startIndex        = (rowNum / 2) * columnNum + columnNum / 2 - 10;
    endIndex          = startIndex + 20;
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

    list[startIndex]->setColor(Qt::green);
    list[endIndex]->setColor(Qt::red);
}

void SearchBase::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (mouseEventEnabled)
    {
        int x = int(event->scenePos().x());
        int y = int(event->scenePos().y());

        if (x >= -sceneWidth / 2 && x <= sceneWidth / 2 - 1 && y >= -sceneHeight / 2 && y <= sceneHeight / 2 - 1)
        {
            pre = (x + sceneWidth / 2) / itemWidth + (y + sceneHeight / 2) / itemWidth * columnNum;

            if (list[pre]->color() == Qt::white)
                list[pre]->setColor(Qt::darkGray);
            else if (list[pre]->color() == Qt::darkGray)
                list[pre]->setColor(Qt::white);
        }
    }
}

void SearchBase::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (mouseEventEnabled)
    {
        int x = int(event->scenePos().x());
        int y = int(event->scenePos().y());

        if (x >= -sceneWidth / 2 && x <= sceneWidth / 2 - 1 && y >= -sceneHeight / 2 && y <= sceneHeight / 2 - 1)
        {
            int cur = (x + sceneWidth / 2) / itemWidth + (y + sceneHeight / 2) / itemWidth * columnNum;

            if (pre != cur)
            {
                if (list[pre]->color() == Qt::red || list[pre]->color() == Qt::green)
                {
                    if (list[cur]->color() == Qt::white)
                    {
                        QColor temp(list[pre]->color());
                        list[pre]->setColor(Qt::white);
                        list[cur]->setColor(temp);
                        pre = cur;
                    }
                }
            }
        }
    }
}

void SearchBase::changeSpeed(int value)
{
    qreal percent = -((value - 50.0) / 50.0);
    intervalTime = 100 + 100 * percent;
}

DISPLAY_NAMESPACE_END
