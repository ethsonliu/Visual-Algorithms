#include "bfs_pane.h"

BfsPane::BfsPane(BasePane* parent) : BasePane(parent)
{
    m_paneNameLabel->setText(tr("Breadth First Search"));

    m_scene = new BfsScene;
    m_view->setScene(static_cast<QGraphicsScene*>(m_scene));
}

void BfsPane::play()
{

}

void BfsPane::pause()
{

}

void BfsPane::replay()
{

}

void BfsPane::restore()
{

}
