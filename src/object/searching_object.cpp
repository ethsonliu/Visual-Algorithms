#include "src/object/searching_object.h"

SearchingBaseObject::SearchingBaseObject(BaseObject* parent) : BaseObject(parent)
{
    m_ma = nullptr;
    m_width = m_height = m_start = m_end = 0;
}

SearchingBaseObject::~SearchingBaseObject()
{
    delete[] m_ma;
}

void SearchingBaseObject::init(int* ma, int width, int height, int start, int end)
{
    memcpy(m_ma, ma, sizeof(int) * size_t(width) * size_t(height));

    m_width  = width;
    m_height = height;
    m_start  = start;
    m_end    = end;
}
