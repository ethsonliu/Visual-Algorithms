#ifndef BASE_WIDGET_H
#define BASE_WIDGET_H

#include "config.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGroupBox>

class BaseWidget : public QWidget
{
public:
    BaseWidget(QWidget* parent = nullptr);

public:
    QWidget*        helperWidget;
    QGraphicsView*  view;
    QGraphicsScene* scene;
    QGroupBox*      settingsGroupBox;
    QGroupBox*      descriptionGroupBox;
};

#endif /* BASE_WIDGET_H */
