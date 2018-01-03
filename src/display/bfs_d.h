#ifndef DISPLAY_BFS_H
#define DISPLAY_BFS_H

#include <QQueue>
#include "search_base.h"

DISPLAY_NAMESPACE_START

class BFS : public SearchBase
{
    Q_OBJECT

public:
    explicit BFS(SearchBase *parent = 0) : SearchBase(parent)
    {
    }

    void bfs(int i, int j, int **map, int dir[][2])
    {
        QQueue<int> Q;
        Q.enqueue(i * columnNum + j);
        while (!Q.empty())
        {
            int pos = Q.head();
            Q.dequeue();

            for (int i = 0; i < 4; i++)
            {
                int posX = pos / columnNum + dir[i][0];
                int posY = pos % columnNum + dir[i][1];

                if (posX >= 0 && posX < rowNum && posY >= 0 && posY < columnNum)
                {
                    if (map[posX][posY] == 0)
                    {
                        WAIT_A_MINUTE_1

                        list[posX * columnNum + posY]->setItemColor(RectItem::CYAN);
                        Q.enqueue(posX * columnNum + posY);
                        map[posX][posY] = -1;
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
    }

public slots:
    void start_bfs()
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

        bfs(int(start / columnNum), int(start % columnNum), map, dir);

        for (int i = 0; i < rowNum; i++)
            delete[] map[i];
        delete[] map;
    }
};

DISPLAY_NAMESPACE_END

#endif // DISPLAY_BFS_H
