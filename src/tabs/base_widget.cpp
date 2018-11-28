#include "base_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

BaseWidget::BaseWidget(QWidget* parent) : QWidget(parent)
{
    helperWidget = new QWidget;
    helperWidget->setFixedWidth(350);
    view = new QGraphicsView;
    settingsGroupBox = new QGroupBox(tr("Settings"));
    descriptionGroupBox = new QGroupBox(tr("Description"));
    QVBoxLayout* vLayout1 = new QVBoxLayout(helperWidget);
    vLayout1->addSpacing(30);
    vLayout1->addWidget(settingsGroupBox);
    vLayout1->addWidget(descriptionGroupBox);
    vLayout1->setSpacing(10);
    vLayout1->setMargin(0);

    QHBoxLayout* hLayout1 = new QHBoxLayout(this);
    hLayout1->addWidget(helperWidget);
    hLayout1->addWidget(view);
    hLayout1->setMargin(0);
}
