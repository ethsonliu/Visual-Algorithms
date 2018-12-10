#ifndef BFS_THREAD_H
#define BFS_THREAD_H

#include "base_thread.h"

class BfsThread : public BaseThread
{
    Q_OBJECT

public:

    BfsThread(BaseThread* parent = nullptr);

public slots:

    void startSlot();
    void pauseSlot();
    void replaySlot();
    void restoreSlot();

};

#endif /* BFS_THREAD_H */
