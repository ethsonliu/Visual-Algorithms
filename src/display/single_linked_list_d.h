#ifndef DISPLAY_SINGLE_LINKED_LIST_H
#define DISPLAY_SINGLE_LINKED_LIST_H

#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QTest>
#include "rect_item.h"
#include "display_base.h"

DISPLAY_NAMESPACE_START

class SingleLinkedList : public DisplayScene
{
    Q_OBJECT

public:
    explicit SingleLinkedList(DisplayScene *parent = 0) : DisplayScene(parent)
    {
        speed     = 1500;
        n         = 0; // we let n <= 10
        itemWidth = 50;

        for (int i = 0; i < 11; i++)
        {
            listPos[i] = QPoint(-sceneWidth / 2 + 20 + i * 130, -160);
            list[i] = nullptr;
            if (i < 10)
                line[i] = nullptr;
        }

        list[0] = new RectItem(listPos[0].x(), listPos[0].y(), itemWidth, itemWidth);
        list[0]->setItemColor(RectItem::DARKGRAY);

        QFont font("Consolas", 16);
        QGraphicsTextItem *textItem = new QGraphicsTextItem("Header");
        textItem->setPos(listPos[0].x() - 12, listPos[0].y() + 55);
        textItem->setFont(font);

        tip = new QGraphicsTextItem("");
        tip->setPos(-120, 0);
        tip->setFont(font);

        this->addItem(list[0]);
        this->addItem(textItem);
        this->addItem(tip);
    }

    RectItem* addRectItem(QPoint pos, QString text)
    {
        RectItem *p = new RectItem(pos.x(), pos.y(), itemWidth, itemWidth);
        this->addItem(p);

        QFont font("Consolas", 14);
        QGraphicsTextItem *textItem = new QGraphicsTextItem(text, p);
        textItem->setFont(font);

        if (text.length() == 1) // for better text-center
            textItem->setPos(pos.x() + 16, pos.y() + 11);
        else
            textItem->setPos(pos.x() + 11, pos.y() + 11);

        return p;
    }

    void setLineColor(QGraphicsLineItem *lineItem, QColor color)
    {
        QPen pen(color);
        pen.setWidth(1);
        lineItem->setPen(pen);
    }

    QGraphicsLineItem* addLine(qreal x1, qreal y1, qreal x2, qreal y2)
    {
        QGraphicsLineItem *p = new QGraphicsLineItem(x1, y1, x2, y2);
        this->addItem(p);
        setLineColor(p, QColor(Qt::black));
        return p;
    }

    void changeTip(QString tipText)
    {
        tip->setPlainText(tipText);
        tip->setDefaultTextColor(QColor(Qt::red));
        QTest::qWait(1500);
        tip->setDefaultTextColor(QColor(Qt::white));
    }

    void animation(int k)
    {
        for (int i = 1; i <= k; i++)
        {
            WAIT_A_MINUTE_2
            setLineColor(line[i - 1], QColor(Qt::green));
            if (i < k)
            {
                WAIT_A_MINUTE_2
                list[i]->setItemColor(RectItem::GREEN);
            }
        }
        WAIT_A_MINUTE_2
        list[k]->setItemColor(RectItem::CYAN);

        WAIT_A_MINUTE_2
        for (int i = 1; i <= k; i++)
        {
            setLineColor(line[i - 1], QColor(Qt::black));
            list[i]->setItemColor(RectItem::WHITE);
        }
    }

    void animationToEnd()
    {
        for (int i = 1; i <= n; i++)
        {
            setLineColor(line[i - 1], QColor(Qt::green));
            QTest::qWait(300);
            list[i]->setItemColor(RectItem::GREEN);
            QTest::qWait(300);
        }
        for (int i = 1; i <= n; i++)
        {
            setLineColor(line[i - 1], QColor(Qt::black));
            list[i]->setItemColor(RectItem::WHITE);
        }
    }

public slots:
    void reset()
    {
        isReset = true;

        for (int i = 1; i <= n; i++)
            delete list[i];
        for (int i = 0; i <= n - 1; i++)
            delete line[i];

        n = 0;
    }

    void insert(int k, QString text)
    {
        isPause = false;
        isReset = false;

        if (k > n)
        {
            changeTip(QString::number(k, 10) + " is too much");
            emit runFailed();
        }
        else if (n == 10)
        {
            changeTip("no space to insert");
            emit runFailed();
        }
        else
        {
            if (k == 0) // insert behind the last element
            {
                WAIT_A_MINUTE_2
                list[n + 1] = addRectItem(listPos[n + 1], text);
                list[n + 1]->setItemColor(RectItem::CYAN);
                WAIT_A_MINUTE_2
                line[n] = addLine(listPos[n].x() + 50, listPos[n].y() + 25, listPos[n].x() + 130, listPos[n].y() + 25);
                setLineColor(line[n], QColor(Qt::cyan));
                WAIT_A_MINUTE_2
                list[n + 1]->setItemColor(RectItem::WHITE);
                setLineColor(line[n], QColor(Qt::black));
            }
            else
            {
                if(k == 1) // insert before the first element
                {
                    WAIT_A_MINUTE_2
                    setLineColor(line[0], QColor(Qt::cyan));
                    WAIT_A_MINUTE_2
                    list[1]->setItemColor(RectItem::GREEN);
                    WAIT_A_MINUTE_2
                    setLineColor(line[0], QColor(Qt::black));
                    list[1]->setItemColor(RectItem::WHITE);
                }
                else
                    animation(k);

                WAIT_A_MINUTE_2
                delete line[k - 1];

                // first, move rectitems and lines
                for (int i = n; i >= k; i--)
                {
                    list[i]->setPos(QPoint(130, 0)); // 130 is the distance of every two adjacent square blocks
                    if (i > k)
                        line[i - 1]->setPos(QPoint(130, 0));
                    list[i + 1] = list[i];
                    if (i > k)
                        line[i] = line[i - 1];
                }
                // second, build rectitem and lines
                WAIT_A_MINUTE_2
                list[k] = addRectItem(listPos[k], text);
                list[k]->setItemColor(RectItem::CYAN);
                WAIT_A_MINUTE_2
                line[k - 1] = addLine(listPos[k - 1].x() + 50, listPos[k - 1].y() + 25, listPos[k - 1].x() + 130, listPos[k - 1].y() + 25);
                setLineColor(line[k - 1], QColor(Qt::cyan));
                WAIT_A_MINUTE_2
                line[k] = addLine(listPos[k].x() + 50, listPos[k].y() + 25, listPos[k].x() + 130, listPos[k].y() + 25);
                setLineColor(line[k], QColor(Qt::cyan));
                WAIT_A_MINUTE_2
                list[k]->setItemColor(RectItem::WHITE);
                setLineColor(line[k - 1], QColor(Qt::black));
                setLineColor(line[k], QColor(Qt::black));
            }

            n++;
            emit finished();
        }
    }

    void find(QString text)
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            auto childList = list[i]->childItems();
            if (((QGraphicsTextItem*)childList[0])->toPlainText() == text)
            {
                animation(i);
                break;
            }
        }

        if (i > n)
        {
            animationToEnd();
            changeTip(text + " is not existed");
        }
    }

    void remove(int k)
    {
        if (k > n)
            changeTip(QString::number(k, 10) + " is too much");
        else
        {
            QTest::qWait(500);

            animation(k);

            if (k == -1) // delete the last one
            {
                setLineColor(line[k - 1], QColor(Qt::green));
                list[k]->setItemColor(RectItem::GREEN);
                delete line[k - 1];
                QTest::qWait(600);
                delete list[k];
            }
            else
            {
                // first, delete
                setLineColor(line[k - 1], QColor(Qt::green));
                setLineColor(line[k], QColor(Qt::green));
                list[k]->setItemColor(RectItem::GREEN);
                delete line[k - 1];
                QTest::qWait(600);
                delete line[k];
                QTest::qWait(600);
                delete list[k];
                QTest::qWait(300);

                // second, move
                for (int i = k + 1; i <= n; i++)
                    list[i]->setItemColor(RectItem::GREEN);
                for (int i = k + 1; i < n; i++)
                    setLineColor(line[i], QColor(Qt::green));
                for (int i = k + 1; k <= n; k++)
                {
                    QTest::qWait(300);
                    list[i]->setPos(QPoint(-130, 0));
                    if (i < n)
                        line[i]->setPos(QPoint(-130, 0));
                    list[i - 1] = list[i];
                    if (i < n)
                        line[i - 1] = line[i];
                }
                QTest::qWait(300);
                for (int i = k + 1; i <= n; i++)
                    list[i - 1]->setItemColor(RectItem::WHITE);
                for (int i = k + 1; i < n; i++)
                    setLineColor(line[i - 1], QColor(Qt::black));

                // third, build a line
                QTest::qWait(600);
                line[k - 1] = addLine(listPos[k - 1].x() + 50, listPos[k - 1].y() + 25, listPos[k - 1].x() + 130, listPos[k - 1].y() + 25);
                setLineColor(line[k - 1], QColor(Qt::green));
                QTest::qWait(300);
                setLineColor(line[k - 1], QColor(Qt::black));
            }

            n--;
        }
    }

    void remove(QString text)
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            auto childList = list[i]->childItems();
            if (((QGraphicsTextItem*)childList[0])->toPlainText() == text)
            {
                remove(i);
                break;
            }
        }

        if (i > n)
        {
            animationToEnd();
            changeTip(text + " is not existed");
        }
    }

signals:
    void runFailed();

private:
    int n;
    int itemWidth;
    RectItem *list[11];
    QPoint listPos[11];
    QGraphicsLineItem *line[10];
    QGraphicsTextItem *tip;
};

DISPLAY_NAMESPACE_END

#endif // DISPLAY_SINGLE_LINKED_LIST_H
