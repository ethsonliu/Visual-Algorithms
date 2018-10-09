#ifndef CONFIG_H
#define CONFIG_H

#if (1)

#include <QDebug>

#define VA_DEBUG_P qDebug()
#define VA_DEBUG(e) VA_DEBUG_P << #e << "=" << e

#endif

extern float gScaledSize;

#define FIT(x) int((x) * gScaledSize)

#endif /* CONFIG_H */
