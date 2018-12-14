#ifndef BASE_SCENE_H
#define BASE_SCENE_H

#include "../config.h"
#include <QThread>
#include <QGraphicsScene>

class BaseScene : public QGraphicsScene
{
    Q_OBJECT

public:

    BaseScene(QGraphicsScene* parent = nullptr);
    ~BaseScene();

public slots:

    virtual void startSlot() = 0;
    virtual void pauseSlot() = 0;
    virtual void replaySlot() = 0;
    virtual void restoreSlot() = 0;

protected:

    int      m_sceneWidth;
    int      m_sceneHeight;

    QObject*  m_object;
    QThread*  m_thread;
};

#endif /* BASE_SCENE_H */
