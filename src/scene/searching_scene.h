#ifndef VISUAL_ALGORITHMS_SCENE_SEARCHING_BASE_SCENE_H
#define VISUAL_ALGORITHMS_SCENE_SEARCHING_BASE_SCENE_H

#include "src/item/rect_item.h"
#include "src/scene/base_scene.h"

#include <QVector>
#include <QGraphicsScene>
#include <atomic>

class SearchingBaseScene : public BaseScene
{
    Q_OBJECT

public:

    SearchingBaseScene(BaseScene* parent = nullptr);
    virtual ~SearchingBaseScene();

    virtual void start()   = 0;
    virtual void pause()   = 0;
    virtual void replay()  = 0;
    virtual void restore() = 0;

protected:

    int                m_rowNum;
    int                m_columnNum;
    int                m_itemsNum;
    int                m_itemWidth;
    int                m_startIndex;
    int                m_endIndex;
    int*               m_ma;
    QVector<RectItem*> m_rectItemVector;

    static const QColor color_start;
    static const QColor color_end;
    static const QColor color_blank;
    static const QColor color_obstacle;
    static const QColor color_pass;
    static const QColor border_gray;
    static const QColor border_dark;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void setRectItemColor(int index, const QColor & color);

    inline void setMouseEnabled(bool enabled) { m_mouseEventEnabled.store(enabled); }
    inline bool mouseIsEnabled() const { return m_mouseEventEnabled.load(); }

private:

    std::atomic<bool>  m_mouseEventEnabled;
    int                m_preMouseIndex;

    int indexInBound(const QPointF & point) const;

};

#endif // VISUAL_ALGORITHMS_SCENE_SEARCHING_BASE_SCENE_H
