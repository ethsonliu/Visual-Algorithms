#include "src/scene/base_scene.h"

BaseScene::BaseScene(QGraphicsScene* parent) : QGraphicsScene(parent)
{
    m_sceneWidth  = 1140;
    m_sceneHeight = 840;

    m_object      = nullptr;
    m_thread      = nullptr;

    setSceneRect(-m_sceneWidth / 2, -m_sceneHeight / 2, m_sceneWidth, m_sceneHeight);
}

BaseScene::~BaseScene()
{
    m_object->deleteLater();
    m_thread->deleteLater();
}
