#ifndef VISUAL_ALGORITHMS_OBJECT_BFS_THREAD_H
#define VISUAL_ALGORITHMS_OBJECT_BFS_THREAD_H

#include "src/object/searching_object.h"

class BfsObject : public SearchingBaseObject
{
    Q_OBJECT

public:

    BfsObject(SearchingBaseObject* parent = nullptr);

public slots:

    void startSlot();
    void pauseSlot();
    void replaySlot();
    void restoreSlot();

};

#endif // VISUAL_ALGORITHMS_OBJECT_BFS_THREAD_H
