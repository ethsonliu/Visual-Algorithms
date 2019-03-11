#ifndef VISUAL_ALGORITHMS_CONFIG_H
#define VISUAL_ALGORITHMS_CONFIG_H

#include <QDebug>

extern float gScaleSize;

#define DEBUG_QT_PLAIN qDebug()

#define DEBUG_QT_VARIABLE(e) DEBUG_QT_PLAIN << #e << "=" << (e)

#endif // VISUAL_ALGORITHMS_CONFIG_H
