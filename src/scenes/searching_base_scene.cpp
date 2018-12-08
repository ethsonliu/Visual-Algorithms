#include "searching_base_scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QColor>
SearchingBaseScene::SearchingBaseScene(BaseScene* parent) : BaseScene(parent)
{
    m_mouseEventEnabled = true;
    m_itemWidth         = 30;
    m_rowNum            = m_sceneHeight / m_itemWidth;
    m_columnNum         = m_sceneWidth / m_itemWidth;
    m_itemsNum          = m_rowNum * m_columnNum;
    m_startIndex        = (m_rowNum / 2) * m_columnNum + m_columnNum / 2 - 10;
    m_endIndex          = m_startIndex + 20;
    m_preMouseIndex      = 0;

    m_rectItemVector.reserve(m_itemsNum);

    RectItem* item;
    for (int i = 0; i < m_rowNum; i++)
    {
        for (int j = 0; j < m_columnNum; j++)
        {
            item = new RectItem(j * m_itemWidth - m_sceneWidth / 2, i * m_itemWidth - m_sceneHeight / 2, m_itemWidth, m_itemWidth);
            item->setBorder(Qt::lightGray);
            addItem(item);
            m_rectItemVector << item;
        }
    }

    m_rectItemVector[m_startIndex]->setBrush(Qt::green);
    m_rectItemVector[m_endIndex]->setBrush(Qt::red);
}

void SearchingBaseScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (mouseIsEnabled() == false)
        return;

    int index = isInBound(event->scenePos());

    if (index == -1)
        return;

    QColor curColor = m_rectItemVector[index]->brushColor();

    if (curColor == Qt::white)
    {
        m_rectItemVector[index]->setBrush(Qt::darkGray);
    }
    else if (Qt::darkGray == curColor)
    {
        m_rectItemVector[index]->setBrush(Qt::white);
    }

    m_preMouseIndex = index;
}

void SearchingBaseScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (mouseIsEnabled() == false)
        return;

    int index = isInBound(event->scenePos());

    if (index == -1 || index == m_preMouseIndex)
        return;

    QColor preColor = m_rectItemVector[m_preMouseIndex]->brushColor();
    QColor curColor = m_rectItemVector[index]->brushColor();

    if ((Qt::darkGray == preColor && Qt::white == curColor) ||
        (Qt::white == preColor && Qt::darkGray == curColor))
    {

    }

    m_preMouseIndex = index;
}

int SearchingBaseScene::isInBound(const QPointF & point) const
{
    int x = int(point.x());
    int y = int(point.y());

    int index = (x + m_sceneWidth / 2) / m_itemWidth + (y + m_sceneHeight / 2) / m_itemWidth * m_columnNum;

    if (index < 0 || index >= m_itemsNum)
        return -1;

    return index;
}
