#ifndef BASE_WIDGET_H
#define BASE_WIDGET_H

#include "config.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>

class BaseWidget : public QWidget
{
public:
    BaseWidget(QWidget* parent = nullptr);

protected:
    void setPaneName(QString name);

private:
    QWidget* createTitleWidget(QString name, QString iconPath);

protected:
    QWidget*        m_helperWidget;
    QWidget*        m_settingWidget;
    QWidget*        m_descriptionWidget;
    QGraphicsView*  m_view;
    QGraphicsScene* m_scene;

private:
    QLabel* m_iconLabel;
    QLabel* m_titleLabel;
};

#endif /* BASE_WIDGET_H */
