#include "d_dfs.h"

DISPLAY_NAMESPACE_START

Dfs::Dfs(SearchBase *parent) : SearchBase(parent)
{}

void Dfs::dfs(int i, int j, int m[50][50], int dir[4][2], bool& finded)
{
    for (int k = 0; k < 4; k++)
    {
        if (finded)
            return;

        int x = i + dir[k][0];
        int y = j + dir[k][1];

        if (x >= 0 && x < rowNum && y >= 0 && y < columnNum)
        {
            if (m[x][y] == 0)
            {
                PAUSE_AND_RESET;
                list[x * columnNum + y]->setColor(Qt::cyan);
                m[x][y] = -1;
                dfs(x, y, m, dir, finded);
            }
            else if (m[x][y] == 2)
                finded = true;
        }
    }
}

void Dfs::start()
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

    bool finded = false;
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    dfs(startPoint / columnNum, startPoint % columnNum, m, dir, finded);

    emit finished();
}

void Dfs::reset()
{
    reseted = true;
    intervalTime = 100;
    mouseEventEnabled = true;

    for (int i = 0; i < itemsNum; i++)
        list[i]->setColor(Qt::white);

    list[startIndex]->setColor(Qt::green);
    list[endIndex]->setColor(Qt::red);
}

void Dfs::replay()
{
    start();
}

DISPLAY_NAMESPACE_END
