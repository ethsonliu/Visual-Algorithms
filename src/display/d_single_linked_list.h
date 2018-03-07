#ifndef D_SINGLE_LINKED_LIST_H
#define D_SINGLE_LINKED_LIST_H

#include "display_base.h"
#include "line_item.h"
#include "rect_item.h"

DISPLAY_NAMESPACE_START

class SingleLinkedList : public DisplayScene
{
    Q_OBJECT

public:
    SingleLinkedList(DisplayScene *parent = 0);

private:
    RectItem* addRect(QPointF pos, QString text);
    LineItem* addLine(QPointF pos);
    void changeTipText(QString text);
    void findProcess(int k);
    void moveToRightProcess(int k);
    void moveToLeftProcess(int k);

public slots:
    void reset();
    void replay();
    void changeSpeed(int value);
    void insert(int k, QString text);
    void find(QString text);
    void remove(int k);
    void remove(QString text);

signals:
    void runFailed();

private:
    int n;
    int itemWidth;
    RectItem *list[11];
    LineItem *line[10];
    QString t[11];
    QPointF listPos[11];
    QGraphicsTextItem *tip;

    // for the use of replay
    int __index;
    int __k;
    QString __text;
    int _n;
    QString _t[11];
};

DISPLAY_NAMESPACE_END

#endif // D_SINGLE_LINKED_LIST_H
