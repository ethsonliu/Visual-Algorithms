#ifndef D_SEARCH_BASE_H
#define D_SEARCH_BASE_H

#include "rect_item.h"
#include "display_base.h"
#include <QList>
#include <QGraphicsSceneMouseEvent>

DISPLAY_NAMESPACE_START

class SearchBase : public DisplayScene
{
    Q_OBJECT

public:
    SearchBase(DisplayScene *parent = 0);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void changeSpeed(int value);

protected:
    int  rowNum;
    int  columnNum;
    int  itemsNum;
    int  startIndex;
    int  endIndex;
    bool mouseEventEnabled;
    QList<RectItem*> list;

private:
    int itemWidth;
    int pre;
};

DISPLAY_NAMESPACE_END

#endif // D_SEARCH_BASE_H
