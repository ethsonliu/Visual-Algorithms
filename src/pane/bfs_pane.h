#ifndef VISUAL_ALGORITHMS_PANE_BFS_WIDGET_H
#define VISUAL_ALGORITHMS_PANE_BFS_WIDGET_H

#include "src/pane/base_pane.h"
#include "src/scene/bfs_scene.h"

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

#endif // VISUAL_ALGORITHMS_PANE_BFS_WIDGET_H
