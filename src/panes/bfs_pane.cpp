#include "bfs_pane.h"

BfsPane::BfsPane(BasePane* parent) : BasePane(parent)
{
    m_titleLabel->setText(tr("Breadth First Search"));

    m_scene = new BfsScene;
    m_view->setScene(m_scene);
}

void BfsPane::playSlot()
{

}

void BfsPane::pauseSlot()
{

}

void BfsPane::replaySlot()
{

}

void BfsPane::restoreSlot()
{

}
