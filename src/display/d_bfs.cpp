#include "d_bfs.h"
#include <QQueue>

DISPLAY_NAMESPACE_START

Bfs::Bfs(SearchBase *parent) : SearchBase(parent)
{}

void Bfs::start()
{
    paused = false;
    reseted = false;
    mouseEventEnabled = false;

    int m[50][50];
    int startPoint;
    for (int i = 0; i < itemsNum; i++)
    {
        if (list[i]->color() == Qt::white)
            m[int(i / columnNum)][int(i % columnNum)] = 0;
        else if (list[i]->color() == Qt::darkGray)
            m[int(i / columnNum)][int(i % columnNum)] = -1;
        else if (list[i]->color() == Qt::green)
        {
            m[int(i / columnNum)][int(i % columnNum)] = 1;
            startPoint = i;
        }
        else if (list[i]->color() == Qt::red)
            m[int(i / columnNum)][int(i % columnNum)] = 2;
        else
        {
            list[i]->setColor(Qt::white);
            m[int(i / columnNum)][int(i % columnNum)] = 0;
        }
    }

    bool flag = false;
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    QQueue<int> Q;
    Q.enqueue(startPoint);
    while (!Q.empty())
    {
        if (flag)
            break;

        int index = Q.head();
        Q.dequeue();

        for (int i = 0; i < 4; i++)
        {
            int nx = index / columnNum + dir[i][0];
            int ny = index % columnNum + dir[i][1];
            if (nx >= 0 && nx < rowNum && ny >= 0 && ny < columnNum)
            {
                if (m[nx][ny] == 0)
                {
                    PAUSE_AND_RESET;
                    list[nx * columnNum + ny]->setColor(Qt::cyan);
                    Q.enqueue(nx * columnNum + ny);
                    m[nx][ny] = -1;
                }
                else if (m[nx][ny] == 2)
                {
                    flag = true;
                    break;
                }
            }
        }
    }

    emit finished();
}

void Bfs::reset()
{
    reseted = true;
    intervalTime = 100;
    mouseEventEnabled = true;

    for (int i = 0; i < itemsNum; i++)
        list[i]->setColor(Qt::white);

    list[startIndex]->setColor(Qt::green);
    list[endIndex]->setColor(Qt::red);
}

void Bfs::replay()
{
    start();
}

DISPLAY_NAMESPACE_END
