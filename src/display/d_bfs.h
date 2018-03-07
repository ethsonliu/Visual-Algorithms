#ifndef D_BFS_H
#define D_BFS_H

#include "d_search_base.h"

DISPLAY_NAMESPACE_START

class Bfs : public SearchBase
{
    Q_OBJECT

public:
    Bfs(SearchBase *parent = 0);

public slots:
    void start();
    void reset();
    void replay();
};

DISPLAY_NAMESPACE_END

#endif // D_BFS_H
