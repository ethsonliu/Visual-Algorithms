#ifndef BFS_SCENE_H
#define BFS_SCENE_H

#include "searching_scene.h"
#include "../objects/bfs_object.h"

class BfsScene : public SearchingBaseScene
{
    Q_OBJECT

public:

    BfsScene(SearchingBaseScene* parent = nullptr);

    virtual void start();
    virtual void pause();
    virtual void replay();
    virtual void restore();

};

#endif /* BFS_SCENE_H */
