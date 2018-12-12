#ifndef BFS_THREAD_H
#define BFS_THREAD_H

#include "searching_thread.h"

class BfsThread : public SearchingBaseThread
{
    Q_OBJECT

public:

    BfsThread(SearchingBaseThread* parent = nullptr);

public slots:

    void startSlot();
    void pauseSlot();
    void replaySlot();
    void restoreSlot();

};

#endif /* BFS_THREAD_H */
