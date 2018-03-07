#include "d_single_linked_list.h"
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>

DISPLAY_NAMESPACE_START

SingleLinkedList::SingleLinkedList(DisplayScene *parent) : DisplayScene(parent)
{
    n            = 0; // we let n <= 10
    itemWidth    = 50;
    runningTime  = 500;
    intervalTime = 1000;

    for (int i = 0; i < 11; i++)
    {
        listPos[i] = QPoint(-sceneWidth / 2 + 20 + i * 130, -160);
        list[i] = Q_NULLPTR;
    }
    for (int i = 0; i < 10; i++)
        line[i] = Q_NULLPTR;

    list[0] = new RectItem(listPos[0].x(), listPos[0].y(), itemWidth, itemWidth);
    list[0]->setColor(Qt::darkGray);

    QGraphicsTextItem *textItem = new QGraphicsTextItem("Header");
    textItem->setPos(listPos[0].x() - 12, listPos[0].y() + 55);
    textItem->setFont(QFont("Consolas", 16));

    tip = new QGraphicsTextItem("");
    tip->setPos(-120, 0);
    tip->setFont(QFont("Consolas", 16));

    addItem(list[0]);
    addItem(textItem);
    addItem(tip);
}

RectItem *SingleLinkedList::addRect(QPointF pos, QString text)
{
    RectItem *p = new RectItem(pos.x(), pos.y(), itemWidth, itemWidth);
    addItem(p);

    QGraphicsTextItem *textItem = new QGraphicsTextItem(text, p);
    textItem->setFont(QFont("Consolas", 14));

    if (text.length() == 1) // for better text-center
        textItem->setPos(pos.x() + 16, pos.y() + 11);
    else
        textItem->setPos(pos.x() + 11, pos.y() + 11);

    return p;
}

LineItem *SingleLinkedList::addLine(QPointF pos)
{
    LineItem *p = new LineItem(pos.x() + 50, pos.y() + 25, pos.x() + 130, pos.y() + 25);
    addItem(p);

    return p;
}

void SingleLinkedList::changeTipText(QString text)
{
    tip->setPlainText(text);
    tip->setDefaultTextColor(Qt::red);
    QTest::qWait(1500);
    tip->setDefaultTextColor(Qt::white);
}

void SingleLinkedList::findProcess(int k)
{
    if (k == 0)
        return;

    PAUSE_AND_RESET;
    line[0]->setColor(Qt::cyan);

    for (int i = 1; i <= k - 1; i++)
    {
        PAUSE_AND_RESET;
        list[i]->setColor(Qt::cyan);
        PAUSE_AND_RESET;
        line[i]->setColor(Qt::cyan);
    }

    PAUSE_AND_RESET;
    list[k]->setColor(Qt::red);/////////////////////////加一个抖动效果

    PAUSE_AND_RESET;
    line[0]->setColor(Qt::black);
    list[k]->setColor(Qt::white);
    for (int i = 1; i <= k - 1; i++)
    {
        list[i]->setColor(Qt::white);
        line[i]->setColor(Qt::black);
    }
}

void SingleLinkedList::moveToRightProcess(int k)
{
    QParallelAnimationGroup *group  = new QParallelAnimationGroup;
    QPropertyAnimation *pAnimation;

    for (int i = n; i >= k; i--)
    {
        pAnimation = new QPropertyAnimation(list[i], "pos");
        pAnimation->setDuration(runningTime);
        pAnimation->setStartValue(list[i]->pos());
        pAnimation->setEndValue(list[i]->pos() + QPointF(130, 0));
        group->addAnimation(pAnimation);
        list[i + 1] = list[i];
        t[i + 1] = t[i];
    }
    for (int i = n - 1; i >= k; i--)
    {
        pAnimation = new QPropertyAnimation(line[i], "pos");
        pAnimation->setDuration(runningTime);
        pAnimation->setStartValue(line[i]->pos());
        pAnimation->setEndValue(line[i]->pos() + QPointF(130, 0));
        group->addAnimation(pAnimation);
        line[i + 1] = line[i];
    }

    group->start(QAbstractAnimation::DeleteWhenStopped);
    list[k] = Q_NULLPTR;
    line[k] = Q_NULLPTR;
    n++;
    QTest::qWait(runningTime);
}

void SingleLinkedList::moveToLeftProcess(int k)
{
    QParallelAnimationGroup *group  = new QParallelAnimationGroup;
    QPropertyAnimation *pAnimation;

    for (int i = k; i <= n; i++)
    {
        pAnimation = new QPropertyAnimation(list[i], "pos");
        pAnimation->setDuration(runningTime);
        pAnimation->setStartValue(list[i]->pos());
        pAnimation->setEndValue(list[i]->pos() + QPointF(-130, 0));
        group->addAnimation(pAnimation);
        list[i - 1] = list[i];
        t[i - 1] = t[i];
    }
    for (int i = k; i <= n - 1; i++)
    {
        pAnimation = new QPropertyAnimation(line[i], "pos");
        pAnimation->setDuration(runningTime);
        pAnimation->setStartValue(line[i]->pos());
        pAnimation->setEndValue(line[i]->pos() + QPointF(-130, 0));
        group->addAnimation(pAnimation);
        line[i - 1] = line[i];
    }

    group->start(QAbstractAnimation::DeleteWhenStopped);
    list[n] = Q_NULLPTR;
    line[n - 1] = Q_NULLPTR;
    n--;
    QTest::qWait(runningTime);
}

void SingleLinkedList::reset()
{
    reseted = true;
    runningTime = 500;
    intervalTime = 1000;

    for (int i = 1; i <= n; i++)
    {
        if (list[i])
        {
            removeItem(list[i]);
            delete list[i];
            list[i] = Q_NULLPTR;
        }
    }
    for (int i = 0; i <= n - 1; i++)
    {
        if (line[i])
        {
            removeItem(line[i]);
            delete line[i];
            line[i] = Q_NULLPTR;
        }
    }

    n = 0;
}

void SingleLinkedList::replay()
{
    reseted = true;

    for (int i = 1; i <= n; i++)
    {
        if (list[i])
        {
            removeItem(list[i]);
            delete list[i];
            list[i] = Q_NULLPTR;
        }
    }
    for (int i = 0; i <= n - 1; i++)
    {
        if (line[i])
        {
            removeItem(line[i]);
            delete line[i];
            line[i] = Q_NULLPTR;
        }
    }

    n = _n;
    for (int i = 1; i <= n; i++)
    {
        list[i] = addRect(listPos[i], _t[i]);
        t[i] = _t[i];
    }
    for (int i = 0; i < n; i++)
        line[i] = addLine(listPos[i]);

    switch (__index)
    {
    case 0:
        insert(__k, __text);
        break;
    case 1:
        find(__text);
        break;
    case 2:
        remove(__k);
        break;
    }
}

void SingleLinkedList::changeSpeed(int value)
{
    qreal percent = -((value - 50.0) / 50.0);
    runningTime = 500 + 500 * percent;
    intervalTime = 1000 + 1000 * percent;
}

void SingleLinkedList::insert(int k, QString text)
{
    if (k > n)
    {
        changeTipText(QString::number(k, 10) + " is out of the range!");
        emit runFailed();
        return;
    }

    if (n == 10)
    {
        changeTipText("no space to insert!");
        emit runFailed();
        return;
    }

    paused = false;
    reseted = false;
    _n = n;
    __index = 0;
    __k = k;
    __text = text;
    for (int i = 1; i <= n; i++)
        _t[i] = t[i];

    if (k == 0) // insert behind the last element
    {
        findProcess(n);
        PAUSE_AND_RESET;
        list[n + 1] = addRect(listPos[n + 1], text);
        t[n + 1] = text;
        n++;
        PAUSE_AND_RESET;
        line[n - 1] = addLine(listPos[n - 1]);
    }
    else
    {
        findProcess(k);
        PAUSE_AND_RESET;
        line[k - 1]->setColor(Qt::white);
        PAUSE_AND_RESET;
        moveToRightProcess(k);
        PAUSE_AND_RESET;
        list[k] = addRect(listPos[k], text);
        t[k] = text;
        PAUSE_AND_RESET;
        line[k - 1]->setColor(Qt::black);
        PAUSE_AND_RESET;
        line[k] = addLine(listPos[k]);
    }

    emit finished();
}

void SingleLinkedList::find(QString text)
{
    paused = false;
    reseted = false;
    __index = 1;
    __text = text;

    int i;
    for (i = 1; i <= n; i++)
    {
        PAUSE_AND_RESET;
        line[i - 1]->setColor(Qt::cyan);
        PAUSE_AND_RESET;
        if (t[i] == text)
        {
            list[i]->setColor(Qt::red);/////////////////////////////抖动效果
            break;
        }
        else
            list[i]->setColor(Qt::cyan);
    }

    PAUSE_AND_RESET;
    if (i == n + 1)
    {
        changeTipText(text + " is not existed!");
        i = n;
    }

    for (int ii = 1; ii <= i; ii++)
    {
        line[ii - 1]->setColor(Qt::black);
        list[ii]->setColor(Qt::white);
    }

    emit finished();
}

void SingleLinkedList::remove(int k)
{
    if (k > n)
    {
        changeTipText(QString::number(k, 10) + " is out of the range!");
        emit runFailed();
        return;
    }

    paused = false;
    reseted = false;
    _n = n;
    __index = 2;
    __k = k;
    for (int i = 1; i <= n; i++)
        _t[i] = t[i];

    if (k == -1) // delete the last element
    {
        findProcess(n);
        PAUSE_AND_RESET;
        removeItem(line[n - 1]);
        delete line[n - 1];
        line[n - 1] = Q_NULLPTR;
        PAUSE_AND_RESET;
        removeItem(list[n]);
        delete list[n];
        list[n] = Q_NULLPTR;
        n--;
    }
    else
    {
        findProcess(k);
        PAUSE_AND_RESET;
        removeItem(list[k]);
        delete list[k];
        list[k] = Q_NULLPTR;
        PAUSE_AND_RESET;
        removeItem(line[k]);
        delete line[k];
        line[k] = Q_NULLPTR;
        PAUSE_AND_RESET;
        moveToLeftProcess(k + 1);
    }

    emit finished();
}

void SingleLinkedList::remove(QString text)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (t[i] == text)
            break;
    }

    if (i == n + 1)
    {
        changeTipText(text + " is not existed!");
        emit runFailed();
        return;
    }

    if (i == n)
        i = -1;

    remove(i);
}

DISPLAY_NAMESPACE_END
