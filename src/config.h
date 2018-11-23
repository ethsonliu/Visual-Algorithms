#ifndef CONFIG_H
#define CONFIG_H

#include <QDebug>

#define VA_DEBUG_P qDebug()
#define VA_DEBUG(e) VA_DEBUG_P << #e << "=" << e

#endif /* CONFIG_H */
