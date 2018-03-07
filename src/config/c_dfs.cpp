#include "c_dfs.h"

CONFIG_NAMESPACE_START

Dfs::Dfs(SearchBase *parent) : SearchBase(parent)
{
    illustrationTextEdit->setPlainText(tr("this id dfs\n"
                                          "Red Square      : the beginning\n"
                                          "Green Square    : the end\n"
                                          "DarkGray Square : the block"));
}

CONFIG_NAMESPACE_END
