#ifndef VA_CONFIG_H
#define VA_CONFIG_H

#include <QDebug>

#define VA_DEBUG_P qDebug()
#define VA_DEBUG(e) VA_DEBUG_P << #e << "=" << e

#endif // VA_CONFIG_H
