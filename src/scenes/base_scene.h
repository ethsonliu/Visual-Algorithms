#ifndef BASE_SCENE_H
#define BASE_SCENE_H

#include "../config.h"
#include <QGraphicsScene>

class BaseScene : public QGraphicsScene
{
    Q_OBJECT

public:

    BaseScene(QGraphicsScene* parent = nullptr);

public slots:

    virtual void startSlot() = 0;
    virtual void pauseSlot() = 0;
    virtual void replaySlot() = 0;
    virtual void restoreSlot() = 0;

signals:

    void finishedSignal();

protected:

    int  m_sceneWidth;
    int  m_sceneHeight;

};

#endif /* BASE_SCENE_H */
