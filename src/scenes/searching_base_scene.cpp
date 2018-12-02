#include "searching_base_scene.h"

SearchingBaseScene::SearchingBaseScene(QGraphicsScene* parent) : BaseScene(parent)
{
    m_mouseEventEnabled = true;
    m_mousePressed      = false;
    m_itemWidth         = 30;
    m_rowNum            = m_sceneHeight / m_itemWidth;
    m_columnNum         = m_sceneWidth / m_itemWidth;
    m_itemsNum          = m_rowNum * m_columnNum;
    m_startIndex        = (m_rowNum / 2) * m_columnNum + m_columnNum / 2 - 10;
    m_endIndex          = m_startIndex + 20;

    /* 注意，如果鼠标从外部直接滑入，此时是没有点击事件的，直接进入move事件 */
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

}

void SearchingBaseScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{

}

void SearchingBaseScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{

}
