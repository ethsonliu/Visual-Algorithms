#ifndef BASE_WIDGET_H
#define BASE_WIDGET_H

#include "../config.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QLabel>

class BasePane : public QWidget
{

public:

    BasePane(QWidget* parent = nullptr);

    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void replay() = 0;
    virtual void restore() = 0;

private:

    QHBoxLayout* createMainPane();
    QHBoxLayout* createTitle(const QString & iconPath, const QString & name);

protected:

    QLabel*         m_titleLabel;
    QWidget*        m_settingWidget;
    QWidget*        m_descriptionWidget;
    QGraphicsView*  m_view;
    QGraphicsScene* m_scene;

};

#endif /* BASE_WIDGET_H */
