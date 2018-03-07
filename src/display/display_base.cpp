#include "display_base.h"

DisplayScene::DisplayScene(QGraphicsScene *parent) : QGraphicsScene(parent)
{
    sceneWidth  = 1380;
    sceneHeight = 930;
    paused      = false;
    reseted     = false;

    setSceneRect(-sceneWidth / 2, -sceneHeight / 2, sceneWidth, sceneHeight);
}

void DisplayScene::pause()
{
    paused = !paused;
}
