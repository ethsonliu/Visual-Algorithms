#include "c_bfs.h"

CONFIG_NAMESPACE_START

Bfs::Bfs(SearchBase *parent) : SearchBase(parent)
{
    illustrationTextEdit->setPlainText(tr("Red Square      : the beginning\n"
                                          "Green Square    : the end\n"
                                          "DarkGray Square : the block"));
}

CONFIG_NAMESPACE_END
