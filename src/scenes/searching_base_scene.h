#ifndef SEARCHING_BASE_SCENE_H
#define SEARCHING_BASE_SCENE_H

#include "items/rect_item.h"
#include "base_scene.h"
#include <QVector>
#include <QGraphicsScene>
#include <atomic>

class SearchingBaseScene : public BaseScene
{
    Q_OBJECT

public:
    SearchingBaseScene(BaseScene* parent = nullptr);
    inline void setMouseEnabled(bool enabled) { m_mouseEventEnabled.store(enabled); }
    inline bool mouseIsEnabled() const { return m_mouseEventEnabled.load(); }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

private:
    int isInBound(const QPointF & point) const;

protected:
    int                m_rowNum;
    int                m_columnNum;
    int                m_itemsNum;
    int                m_itemWidth;
    int                m_startIndex;
    int                m_endIndex;
    QVector<RectItem*> m_rectItemVector;

private:
    std::atomic<bool>  m_mouseEventEnabled;
    int                m_preMouseIndex;
};

#endif /* SEARCHING_BASE_SCENE_H */
