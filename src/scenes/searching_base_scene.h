#ifndef SEARCHING_BASE_SCENE_H
#define SEARCHING_BASE_SCENE_H

#include "items/rect_item.h"
#include <QVector>
#include <QGraphicsScene>

class SearchingBaseScene : public QGraphicsScene
{
    Q_OBJECT

public:
    SearchingBaseScene(QGraphicsScene* parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

protected:
    QVector<RectItem*> m_rectItemVector;
};

#endif /* SEARCHING_BASE_SCENE_H */
