#include "d_insert_sort.h"
#include <QtAlgorithms>
#include <QtGlobal>
#include <QTime>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

DISPLAY_NAMESPACE_START

InsertSort::InsertSort(DisplayScene *parent) : DisplayScene(parent)
{
    runningTime  = 300;
    intervalTime = 600;
    dropDistance = 430;

    for (int i = 0; i < 15; i++)
        rectPos[i] = QPointF(-sceneWidth / 2 + 150 + 75 * i, -100);

    init(10);
}

void InsertSort::init(int num)
{
    n = num;
    QTime t = QTime::currentTime();
    qsrand(t.msec() + t.second() * 1000);

    int maxNumber = -1;
    for (int i = 0; i < n; i++)
    {
        _number[i] = number[i] = qrand() % 99 + 1;
        maxNumber = qMax(maxNumber, number[i]);
    }

    unitDistance = 350.0 / maxNumber;

    for (int i = 0; i < n; i++)
        rect[i] = addRect(rectPos[(7 - n / 2) + i], number[i]);
}

RectItem* InsertSort::addRect(QPointF pos, int number)
{
    RectItem *p = new RectItem(pos.x(), pos.y() - number * unitDistance, 45, number * unitDistance);
    addItem(p);

    QFont font("Consolas", 14);
    QGraphicsTextItem *textItem = new QGraphicsTextItem(QString::number(number, 10), p);
    textItem->setFont(font);

    if (number >= 1 && number <= 9) // for better text-center
        textItem->setPos(pos.x() + 14, pos.y());
    else
        textItem->setPos(pos.x() + 9, pos.y());

    return p;
}

void InsertSort::start()
{
    paused = false;
    reseted = false;

    RectItem *item;
    int temp;
    int j;

    PAUSE_AND_RESET;
    rect[0]->setColor(Qt::cyan);

    for (int i = 1; i < n; i++)
    {
        PAUSE_AND_RESET;
        rect[i]->setColor(Qt::red);
        QPropertyAnimation *pAnimation = new QPropertyAnimation(rect[i], "pos");
        pAnimation->setDuration(runningTime);
        pAnimation->setStartValue(rect[i]->pos());
        pAnimation->setEndValue(rect[i]->pos() + QPointF(0, dropDistance));
        pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
        QTest::qWait(runningTime);

        item = rect[i];
        temp = number[i];
        j = i - 1;

        while (j >= 0 && number[j] > temp)
        {
            PAUSE_AND_RESET;
            QPropertyAnimation *pAnimation1 = new QPropertyAnimation(item, "pos");
            pAnimation1->setDuration(runningTime);
            pAnimation1->setStartValue(item->pos());
            pAnimation1->setEndValue(item->pos() + QPointF(-75, 0));
            QPropertyAnimation *pAnimation2 = new QPropertyAnimation(rect[j], "pos");
            pAnimation2->setDuration(runningTime);
            pAnimation2->setStartValue(rect[j]->pos());
            pAnimation2->setEndValue(rect[j]->pos() + QPointF(75, 0));
            QParallelAnimationGroup *group = new QParallelAnimationGroup;
            group->addAnimation(pAnimation1);
            group->addAnimation(pAnimation2);
            group->start(QAbstractAnimation::DeleteWhenStopped);
            QTest::qWait(runningTime);

            number[j + 1] = number[j];
            rect[j + 1] = rect[j];
            rect[j] = item; // in case of deleting more than once
            j--;        
        }

        PAUSE_AND_RESET;
        pAnimation = new QPropertyAnimation(item, "pos");
        pAnimation->setDuration(runningTime);
        pAnimation->setStartValue(item->pos());
        pAnimation->setEndValue(item->pos() + QPointF(0, -dropDistance));
        pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
        QTest::qWait(runningTime);
        PAUSE_AND_RESET;
        item->setColor(Qt::cyan);

        number[j + 1] = temp;
        rect[j + 1] = item;
    }

    emit finished();
}

void InsertSort::reset()
{
    reseted = true;
    runningTime = 300;
    intervalTime = 600;

    for (int i = 0; i < n; i++)
    {
        removeItem(rect[i]);
        delete rect[i];
    }

    for (int i = 0; i < n; i++)
    {
        number[i] = _number[i];
        rect[i] = addRect(rectPos[(7 - n / 2) + i], number[i]);;
    }
}

void InsertSort::replay()
{
    reseted = true;

    for (int i = 0; i < n; i++)
    {
        removeItem(rect[i]);
        delete rect[i];
    }

    for (int i = 0; i < n; i++)
    {
        number[i] = _number[i];
        rect[i] = addRect(rectPos[(7 - n / 2) + i], number[i]);;
    }

    start();
}

void InsertSort::changeSpeed(int value)
{
    qreal percent = -((value - 50.0) / 50.0);
    runningTime = 300 + 300 * percent;
    intervalTime = 600 + 600 * percent;
}

void InsertSort::generate(int num)
{
    reseted = true;

    for (int i = 0; i < n; i++)
    {
        removeItem(rect[i]);
        delete rect[i];
    }

    init(num);
}

void InsertSort::generate(QString text)
{
    reseted = true;

    for (int i = 0; i < n; i++)
    {
        removeItem(rect[i]);
        delete rect[i];
    }

    text.replace("\n", " ");

    QStringList list = text.split(' ', QString::SkipEmptyParts);

    n = list.size();

    if (n > 15)
        n = 15;

    int maxNumber = -1;
    for (int i = 0; i < n; i++)
    {
        _number[i] = number[i] = list[i].toInt();
        maxNumber = qMax(maxNumber, number[i]);
    }

    unitDistance = 350.0 / maxNumber;

    for (int i = 0; i < n; i++)
        rect[i] = addRect(rectPos[(7 - n / 2) + i], number[i]);
}

DISPLAY_NAMESPACE_END
