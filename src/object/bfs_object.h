#ifndef VA_OBJECT_BFS_THREAD_H
#define VA_OBJECT_BFS_THREAD_H

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

#endif // VA_OBJECT_BFS_THREAD_H
