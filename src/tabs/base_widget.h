#ifndef BASE_WIDGET_H
#define BASE_WIDGET_H

#include <QWidget>

extern double g_scaledSize;

#define FIT(x) int((x) * g_scaledSize)

class BaseWidget : public QWidget
{
public:
    BaseWidget(QWidget* parent = 0);
    ~BaseWidget();
};

#endif // BASE_WIDGET_H
