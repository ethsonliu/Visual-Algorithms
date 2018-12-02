#ifndef SEARCHING_BASE_SCENE_H
#define SEARCHING_BASE_SCENE_H

#include "items/rect_item.h"
#include "base_scene.h"
#include <QVector>
#include <QGraphicsScene>

class SearchingBaseScene : public BaseScene
{
    Q_OBJECT

public:
    SearchingBaseScene(QGraphicsScene* parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

protected:
    bool               m_mouseEventEnabled;
    bool               m_mousePressed;
    int                m_rowNum;
    int                m_columnNum;
    int                m_itemsNum;
    int                m_itemWidth;
    int                m_startIndex;
    int                m_endIndex;
    QVector<RectItem*> m_rectItemVector;
};

#endif /* SEARCHING_BASE_SCENE_H */
