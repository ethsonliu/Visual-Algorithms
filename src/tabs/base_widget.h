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
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void replay() = 0;
    virtual void restore() = 0;

protected:
    void setPaneName(const QString & name);

private:
    QWidget* createTitleWidget(const QString & name, const QString & iconPath);

protected:
    QWidget*        m_settingWidget;
    QWidget*        m_descriptionWidget;
    QGraphicsView*  m_view;
    QGraphicsScene* m_scene;

private:
    QWidget*        m_helperWidget;
    QLabel*         m_iconLabel;
    QLabel*         m_titleLabel;
};

#endif /* BASE_WIDGET_H */
