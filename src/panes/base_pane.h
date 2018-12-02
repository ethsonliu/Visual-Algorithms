#ifndef BASE_WIDGET_H
#define BASE_WIDGET_H

#include "config.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QLabel>

class BasePane : public QWidget
{
public:
    BasePane(QWidget* parent = nullptr);

public slots:
    virtual void playSlot() = 0;
    virtual void pauseSlot() = 0;
    virtual void replaySlot() = 0;
    virtual void restoreSlot() = 0;

protected:
    void setPaneTitle(const QString & name);

private:
    QHBoxLayout* createMainPane();
    QHBoxLayout* createTitle(const QString & name, const QString & iconPath);

protected:
    QWidget*        m_settingWidget;
    QWidget*        m_descriptionWidget;
    QGraphicsView*  m_view;
    QGraphicsScene* m_scene;

private:
    QLabel*         m_titleLabel;
};

#endif /* BASE_WIDGET_H */
