#ifndef DISPLAY_BASE_H
#define DISPLAY_BASE_H

#include <QTest>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>

#define DISPLAY_NAMESPACE_START namespace Display {
#define DISPLAY_NAMESPACE_END   }

#define WAIT_A_MINUTE_1 \
    while (isPause) \
    { \
        if (isReset) \
        { \
            isFinished = true; \
            return; \
        } \
        QTest::qWait(10); \
    } \
    QTest::qWait(speed);

#define WAIT_A_MINUTE_2 \
    while (isPause) \
    { \
        if (isReset) \
            return; \
        QTest::qWait(10); \
    } \
    QTest::qWait(speed);

class DisplayScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit DisplayScene(QGraphicsScene *parent = 0) : QGraphicsScene(parent)
    {
        sceneWidth  = 1380;
        sceneHeight = 930;
        isPause     = false;
        isReset     = false;

        setSceneRect(-sceneWidth / 2, -sceneHeight / 2, sceneWidth, sceneHeight);
    }

public slots:
    void pause()
    {
        isPause = !isPause;
    }

signals:
    void finished();

protected:
    int sceneWidth;
    int sceneHeight;

    volatile bool isReset;
    volatile bool isPause;
    volatile int  speed;
};

#endif // DISPLAY_BASE_H
