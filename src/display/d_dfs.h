#ifndef D_DFS_H
#define D_DFS_H

#include "d_search_base.h"

DISPLAY_NAMESPACE_START

class Dfs : public SearchBase
{
    Q_OBJECT

public:
    Dfs(SearchBase *parent = 0);

private:
    void dfs(int i, int j, int m[50][50], int dir[4][2], bool& finded);

public slots:
    void start();
    void reset();
    void replay();
};

DISPLAY_NAMESPACE_END

#endif // D_DFS_H
