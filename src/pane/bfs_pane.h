#ifndef BFS_WIDGET_H
#define BFS_WIDGET_H

#include "base_pane.h"
#include "../scenes/bfs_scene.h"

class BfsPane : public BasePane
{
    Q_OBJECT

public:

    BfsPane(BasePane* parent = nullptr);

    virtual void play();
    virtual void pause();
    virtual void replay();
    virtual void restore();

};

#endif /* BFS_WIDGET_H */
