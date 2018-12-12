#ifndef BFS_WIDGET_H
#define BFS_WIDGET_H

#include "base_pane.h"
#include "../scenes/bfs_scene.h"
#include "../threads/bfs_thread.h"

class BfsPane : public BasePane
{
    Q_OBJECT

public:

    BfsPane(BasePane* parent = nullptr);

public slots:
    virtual void playSlot();
    virtual void pauseSlot();
    virtual void replaySlot();
    virtual void restoreSlot();

};

#endif /* BFS_WIDGET_H */
