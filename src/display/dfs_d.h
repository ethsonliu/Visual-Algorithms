#ifndef DISPLAY_DFS_H
#define DISPLAY_DFS_H

#include "search_base.h"

DISPLAY_NAMESPACE_START

class DFS : public SearchBase
{
    Q_OBJECT

public:
    explicit DFS(SearchBase *parent = 0) : SearchBase(parent)
    {
    }

    void dfs(int i, int j, int **map, int dir[][2])
    {
        for (int k = 0; k < 4; k++)
        {
            int posX = dir[k][0] + i;
            int posY = dir[k][1] + j;

            if (posX >= 0 && posX < rowNum && posY >= 0 && posY < columnNum)
            {
                if (isFinished)
                    return;

                if (map[posX][posY] == 0)
                {
                    WAIT_A_MINUTE_1

                    list[posX * columnNum + posY]->setItemColor(RectItem::CYAN);
                    map[posX][posY] = -1;
                    dfs(posX, posY, map, dir);
                }
                else if (map[posX][posY] == 2)
                {
                    isFinished = true;
                    emit finished();
                    return;
                }
            }
        }
    }

public slots:
    void start_dfs()
    {
        isReset           = false;
        isPause           = false;
        isFinished        = false;
        mouseEventEnabled = false;

        int **map = new int *[rowNum];
        for (int i = 0; i < rowNum; i++)
            map[i] = new int[columnNum];

        int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

        int start;
        for (int i = 0; i < itemsNum; i++)
        {
            if (list[i]->color == RectItem::DARKGRAY)
                map[int(i / columnNum)][int(i % columnNum)] = -1;
            else if (list[i]->color == RectItem::GREEN)
            {
                map[int(i / columnNum)][int(i % columnNum)] = 1;
                start = i;
            }
            else if (list[i]->color == RectItem::RED)
                map[int(i / columnNum)][int(i % columnNum)] = 2;
            else
                map[int(i / columnNum)][int(i % columnNum)] = 0;
        }

        dfs(int(start / columnNum), int(start % columnNum), map, dir);

        for (int i = 0; i < rowNum; i++)
            delete[] map[i];
        delete[] map;
    }
};

DISPLAY_NAMESPACE_END

#endif // DISPLAY_DFS_H
