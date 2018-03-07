#ifndef C_DFS_H
#define C_DFS_H

#include "c_search_base.h"

CONFIG_NAMESPACE_START

class Dfs : public SearchBase
{
public:
    Dfs(SearchBase *parent = 0);
};

CONFIG_NAMESPACE_END

#endif // C_DFS_H
