#ifndef VA_SCENE_BASE_SCENE_H
#define VA_SCENE_BASE_SCENE_H

#include "src/config.h"
#include "src/object/base_object.h"

#include <QGraphicsScene>
#include <QThread>

class BaseScene : public QGraphicsScene
{
    Q_OBJECT

public:

    BaseScene(QGraphicsScene* parent = nullptr);
    virtual ~BaseScene();

    virtual void start()   = 0;
    virtual void pause()   = 0;
    virtual void replay()  = 0;
    virtual void restore() = 0;

    inline ThreadState threadState() const { return m_object->threadState(); }

signals:

    void startSignal();
    void pauseSignal();
    void replaySignal();
    void restoreSignal();

protected:

    int          m_sceneWidth;
    int          m_sceneHeight;

    BaseObject*  m_object;
    QThread*     m_thread;

};

#endif // VA_SCENE_BASE_SCENE_H
