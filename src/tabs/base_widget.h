#ifndef BASE_WIDGET_H
#define BASE_WIDGET_H

#include "config.h"
#include <QWidget>

class BaseWidget : public QWidget
{
public:
    BaseWidget(QWidget* parent = 0);
    ~BaseWidget();
};

#endif /* BASE_WIDGET_H */
