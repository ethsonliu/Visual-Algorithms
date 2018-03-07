#ifndef D_INSERT_SORT_H
#define D_INSERT_SORT_H

#include "rect_item.h"
#include "display_base.h"

DISPLAY_NAMESPACE_START

class InsertSort : public DisplayScene
{
    Q_OBJECT

public:
    explicit InsertSort(DisplayScene *parent = 0);

private:
    void init(int num);
    RectItem* addRect(QPointF pos, int number);

public slots:
    void start();
    void reset();
    void replay();
    void changeSpeed(int value);
    void generate(int num);
    void generate(QString text);

private:
    int   n;
    qreal dropDistance;
    qreal unitDistance;

    int number[15];
    int _number[15]; // for the use of reset and replay
    int check[300];
    RectItem *rect[15];
    QPointF rectPos[15];
};

DISPLAY_NAMESPACE_END

#endif // D_INSERT_SORT_H
