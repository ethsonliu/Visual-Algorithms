#ifndef VA_PANE_BASE_WIDGET_H
#define VA_PANE_BASE_WIDGET_H

#include "src/config.h"
#include "src/scene/base_scene.h"

#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLabel>

class BasePane : public QWidget
{

public:

    BasePane(QWidget* parent = nullptr);

    virtual void play()    = 0;
    virtual void pause()   = 0;
    virtual void replay()  = 0;
    virtual void restore() = 0;

    inline ThreadState threadState() const { return m_scene->threadState(); }
    inline QString paneName() const { return m_paneNameLabel->text(); }

private:

    QHBoxLayout* createMainPane();
    QHBoxLayout* createTitle(const QString & iconPath, const QString & name);

protected:

    QLabel*         m_paneNameLabel;
    QWidget*        m_settingWidget;
    QWidget*        m_descriptionWidget;
    QGraphicsView*  m_view;
    BaseScene*      m_scene;

};

#endif // VA_PANE_BASE_WIDGET_H
