#ifndef VA_OBJECT_BASE_THREAD_H
#define VA_OBJECT_BASE_THREAD_H

#include "src/config.h"

#include <QObject>
#include <atomic>

enum ThreadState { running, paused, finished };

class BaseObject : public QObject
{
    Q_OBJECT

public:

    BaseObject(QObject* parent = nullptr);

    inline ThreadState threadState() const { return m_threadState.load(); }

public slots:

    virtual void startSlot()   = 0;
    virtual void pauseSlot()   = 0;
    virtual void replaySlot()  = 0;
    virtual void restoreSlot() = 0;

protected:

    std::atomic<ThreadState> m_threadState;

    inline void setThreadState(ThreadState state) { m_threadState.store(state); }

};

#endif // VA_OBJECT_BASE_THREAD_H
