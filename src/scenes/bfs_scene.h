#ifndef BFS_SCENE_H
#define BFS_SCENE_H

#include "searching_base_scene.h"

class BfsScene : public SearchingBaseScene
{
    Q_OBJECT

public:

    BfsScene(SearchingBaseScene* parent = nullptr);

public slots:

    virtual void startSlot();
    virtual void pauseSlot();
    virtual void replaySlot();
    virtual void restoreSlot();

};

#endif /* BFS_SCENE_H */
