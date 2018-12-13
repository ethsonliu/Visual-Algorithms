#include "searching_thread.h"

SearchingBaseThread::SearchingBaseThread(BaseThread* parent) : BaseThread(parent)
{
    m_ma = nullptr;
    m_width = m_height = m_start = m_end = 0;
}

SearchingBaseThread::~SearchingBaseThread()
{
    delete[] m_ma;
}
