#include "searching_scene.h"
#include <QGraphicsSceneMouseEvent>

const QColor SearchingBaseScene::color_start    = QColor(  0, 221,   0);
const QColor SearchingBaseScene::color_end      = QColor(238,  68,   0);
const QColor SearchingBaseScene::color_blank    = QColor(255, 255, 255);
const QColor SearchingBaseScene::color_obstacle = QColor(128, 128, 128);
const QColor SearchingBaseScene::color_pass     = QColor(152, 251, 152);
const QColor SearchingBaseScene::border_gray    = QColor(207, 207, 207);
const QColor SearchingBaseScene::border_dark    = QColor(104, 104, 104);

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

    m_ma = new int[size_t(m_itemsNum)];
    m_rectItemVector.reserve(m_itemsNum);

    RectItem* item;
    for (int i = 0; i < m_rowNum; i++)
    {
        for (int j = 0; j < m_columnNum; j++)
        {
            item = new RectItem(j * m_itemWidth - m_sceneWidth / 2, i * m_itemWidth - m_sceneHeight / 2, m_itemWidth, m_itemWidth);
            item->setBorder(border_gray);
            addItem(item);
            m_rectItemVector << item;
        }
    }

    m_rectItemVector[m_startIndex]->setBrush(color_start);
    m_rectItemVector[m_endIndex]->setBrush(color_end);
}

SearchingBaseScene::~SearchingBaseScene()
{
    delete[] m_ma;
}

void SearchingBaseScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (mouseIsEnabled() == false)
        return;

    int index = indexInBound(event->scenePos());

    if (-1 == index)
        return;

    QColor curColor = m_rectItemVector[index]->brushColor();

    if (color_blank == curColor)
    {  
        setRectItemColor(index, color_obstacle);
    }
    else if (color_obstacle == curColor)
    {
        setRectItemColor(index, color_blank);
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

    if ((color_obstacle == preColor && color_blank    == curColor) ||
        (color_blank    == preColor && color_obstacle == curColor))
    {
        setRectItemColor(index, preColor);
        m_preMouseIndex = index;
    }
    else if ((color_start == preColor && color_blank == curColor) ||
             (color_end   == preColor && color_blank == curColor))
    {
        setRectItemColor(index, preColor);
        setRectItemColor(m_preMouseIndex, color_blank);
        m_preMouseIndex = index;
    }
}

void SearchingBaseScene::setRectItemColor(int index, const QColor & color)
{
    if (index < 0 || index >= m_itemsNum)
        return;

    m_rectItemVector[index]->setBrush(color);

    if (color_blank == color)
    {
        m_rectItemVector[index]->setBorder(border_gray);
        m_rectItemVector[index]->setZValue(0);
    }
    else if (color_obstacle == color)
    {
        m_rectItemVector[index]->setBorder(border_dark);
        m_rectItemVector[index]->setZValue(1);
    }
    else if (color_start == color || color_end == color)
    {
        m_rectItemVector[index]->setBorder(border_gray);
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
