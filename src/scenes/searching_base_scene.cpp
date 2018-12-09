#include "searching_base_scene.h"
#include <QGraphicsSceneMouseEvent>

const QColor SearchingBaseScene::COLOR_START    = QColor(0, 221, 0);
const QColor SearchingBaseScene::COLOR_END      = QColor(238, 68, 0);
const QColor SearchingBaseScene::COLOR_BLANK    = QColor(255, 255, 255);
const QColor SearchingBaseScene::COLOR_OBSTACLE = QColor(128, 128, 128);
const QColor SearchingBaseScene::COLOR_PASS     = QColor(152, 251, 152);
const QColor SearchingBaseScene::BORDER_GRAY    = QColor(207, 207, 207);
const QColor SearchingBaseScene::BORDER_DARK    = QColor(104, 104, 104);

SearchingBaseScene::SearchingBaseScene(BaseScene* parent) : BaseScene(parent)
{
    setMouseEnabled(true);

    m_itemWidth         = 30;
    m_rowNum            = m_sceneHeight / m_itemWidth;
    m_columnNum         = m_sceneWidth / m_itemWidth;
    m_itemsNum          = m_rowNum * m_columnNum;
    m_startIndex        = (m_rowNum / 2) * m_columnNum + m_columnNum / 2 - 10;
    m_endIndex          = m_startIndex + 20;
    m_preMouseIndex     = 0;

    m_rectItemVector.reserve(m_itemsNum);

    RectItem* item;
    for (int i = 0; i < m_rowNum; i++)
    {
        for (int j = 0; j < m_columnNum; j++)
        {
            item = new RectItem(j * m_itemWidth - m_sceneWidth / 2, i * m_itemWidth - m_sceneHeight / 2, m_itemWidth, m_itemWidth);
            item->setBorder(BORDER_GRAY);
            addItem(item);
            m_rectItemVector << item;
        }
    }

    m_rectItemVector[m_startIndex]->setBrush(COLOR_START);
    m_rectItemVector[m_endIndex]->setBrush(COLOR_END);
}

void SearchingBaseScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (mouseIsEnabled() == false)
        return;

    int index = indexInBound(event->scenePos());

    if (-1 == index)
        return;

    QColor curColor = m_rectItemVector[index]->brushColor();

    if (COLOR_BLANK == curColor)
    {  
        setRectItemColor(index, COLOR_OBSTACLE);
    }
    else if (COLOR_OBSTACLE == curColor)
    {
        setRectItemColor(index, COLOR_BLANK);
    }

    m_preMouseIndex = index;
}

void SearchingBaseScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (mouseIsEnabled() == false)
        return;

    int index = indexInBound(event->scenePos());

    if (-1 == index || m_preMouseIndex == index)
        return;

    QColor preColor = m_rectItemVector[m_preMouseIndex]->brushColor();
    QColor curColor = m_rectItemVector[index]->brushColor();

    if ((COLOR_OBSTACLE == preColor && COLOR_BLANK    == curColor) ||
        (COLOR_BLANK    == preColor && COLOR_OBSTACLE == curColor))
    {
        setRectItemColor(index, preColor);
        m_preMouseIndex = index;
    }
    else if ((COLOR_START == preColor && COLOR_BLANK == curColor) ||
             (COLOR_END   == preColor && COLOR_BLANK == curColor))
    {
        setRectItemColor(index, preColor);
        setRectItemColor(m_preMouseIndex, COLOR_BLANK);
        m_preMouseIndex = index;
    }
}

void SearchingBaseScene::setRectItemColor(int index, const QColor & color)
{
    if (index < 0 || index >= m_itemsNum)
        return;

    m_rectItemVector[index]->setBrush(color);

    if (COLOR_BLANK == color)
    {
        m_rectItemVector[index]->setBorder(BORDER_GRAY);
        m_rectItemVector[index]->setZValue(0);
    }
    else if (COLOR_OBSTACLE == color)
    {
        m_rectItemVector[index]->setBorder(BORDER_DARK);
        m_rectItemVector[index]->setZValue(1);
    }
    else if (COLOR_START == color || COLOR_END == color)
    {
        m_rectItemVector[index]->setBorder(BORDER_GRAY);
    }
    else
    {

    }
}

int SearchingBaseScene::indexInBound(const QPointF & point) const
{
    int x = int(point.x());
    int y = int(point.y());

     if (x < -m_sceneWidth  / 2 + 1  || x > m_sceneWidth  / 2 - 1 ||
         y < -m_sceneHeight / 2 + 1  || y > m_sceneHeight / 2 - 1)
     {
         return -1;
     }

    int index = (x + m_sceneWidth / 2) / m_itemWidth + (y + m_sceneHeight / 2) / m_itemWidth * m_columnNum;

    return index;
}
