#ifndef C_BFS_H
#define C_BFS_H

#include "c_search_base.h"

CONFIG_NAMESPACE_START

class Bfs : public SearchBase
{
public:
    Bfs(SearchBase *parent = 0);
};

CONFIG_NAMESPACE_END

#endif // C_BFS_H
