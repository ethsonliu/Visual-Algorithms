#include "bfs_pane.h"

BfsPane::BfsPane(BasePane* parent) : BasePane(parent)
{
    m_titleLabel->setText(tr("Breadth First Search"));

    m_scene = new BfsScene;
    m_view->setScene(m_scene);
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
