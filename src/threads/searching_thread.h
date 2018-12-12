#ifndef SEARCHING_BASE_THREAD_H
#define SEARCHING_BASE_THREAD_H

#include "base_thread.h"

enum SearchingFlag { start, end, blank, obstacle, pass };

class SearchingBaseThread : public BaseThread
{

public:

    SearchingBaseThread(BaseThread* parent = nullptr);

public slots:

    virtual void startSlot() = 0;
    virtual void pauseSlot() = 0;
    virtual void replaySlot() = 0;
    virtual void restoreSlot() = 0;



private:


};

#endif // SEARCHING_BASE_THREAD_H
