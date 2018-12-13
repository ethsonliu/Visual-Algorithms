#ifndef SEARCHING_BASE_THREAD_H
#define SEARCHING_BASE_THREAD_H

#include "base_thread.h"

enum SearchingFlag { start, end, blank, obstacle, pass };

class SearchingBaseThread : public BaseThread
{

public:

    SearchingBaseThread(BaseThread* parent = nullptr);
    ~SearchingBaseThread();

    void init(int* ma, int width, int height, int start, int end);

public slots:

    virtual void startSlot() = 0;
    virtual void pauseSlot() = 0;
    virtual void replaySlot() = 0;
    virtual void restoreSlot() = 0;

protected:

    int* m_ma;
    int  m_width;
    int  m_height;
    int  m_start;
    int  m_end;

};

#endif // SEARCHING_BASE_THREAD_H
