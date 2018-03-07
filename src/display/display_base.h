#ifndef DISPLAY_BASE_H
#define DISPLAY_BASE_H

#define DISPLAY_NAMESPACE_START namespace Display {
#define DISPLAY_NAMESPACE_END }
#define PAUSE_AND_RESET \
    while (paused) \
    { \
        if (reseted) \
            return; \
        QTest::qWait(10); \
    } \
    QTest::qWait(intervalTime);

#include <QGraphicsScene>
#include <QTest>

class DisplayScene : public QGraphicsScene
{
    Q_OBJECT

public:
    DisplayScene(QGraphicsScene *parent = 0);

public slots:
    void pause();

signals:
    void finished();

protected:
    int  sceneWidth;
    int  sceneHeight;
    int  runningTime;
    int  intervalTime;
    bool paused;
    bool reseted;
};

#endif // DISPLAY_BASE_H
