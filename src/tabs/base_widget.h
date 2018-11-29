#ifndef BASE_WIDGET_H
#define BASE_WIDGET_H

#include "config.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGroupBox>
#include <QLabel>

class BaseWidget : public QWidget
{
public:
    BaseWidget(QWidget* parent = nullptr);

public:
    QWidget*        m_helperWidget;
    QGraphicsView*  m_view;
    QGraphicsScene* m_scene;
    QGroupBox*      m_settingsGroupBox;
    QGroupBox*      m_descriptionGroupBox;

public:
    void setTitle(QString title);

private:
    QLabel* m_iconLabel;
    QLabel* m_titleLabel;
};

#endif /* BASE_WIDGET_H */
