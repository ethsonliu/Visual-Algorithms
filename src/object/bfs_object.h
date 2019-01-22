#ifndef BFS_THREAD_H
#define BFS_THREAD_H

#include "searching_object.h"

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

#endif /* BFS_THREAD_H */
