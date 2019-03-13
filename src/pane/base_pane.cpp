#include "src/pane/base_pane.h"

#include <QVBoxLayout>
#include <QSizePolicy>
#include <QGraphicsView>

BasePane::BasePane(QWidget* parent) : QWidget(parent)
{
    QPixmap pixmap(":/pane_icon.svg");
    pixmap = pixmap.scaled(28, 28);
    QLabel* iconLabel = new QLabel;
    iconLabel->setPixmap(pixmap);

    m_paneNameLabel = new QLabel;
    m_paneNameLabel->setStyleSheet("QLabel{font-size: 20px; color: rgb(7, 123, 227);}");

    QHBoxLayout* hLayout1 = new QHBoxLayout;
    hLayout1->addWidget(iconLabel);
    hLayout1->addWidget(m_paneNameLabel);
    hLayout1->addStretch();
    hLayout1->setSpacing(8);
    hLayout1->setContentsMargins(10, 10, 0, 10);

    QHBoxLayout* hLayout2 = createMainPane();

    QWidget* hLineWidget = new QWidget;
    hLineWidget->setFixedHeight(1);
    hLineWidget->setStyleSheet("QWidget{border: 1px solid rgb(226, 226, 226);}");

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addLayout(hLayout1);
    vLayout->addWidget(hLineWidget);
    vLayout->addLayout(hLayout2);
    vLayout->setSpacing(0);
    vLayout->setMargin(0);

    setLayout(vLayout);
}

QHBoxLayout* BasePane::createMainPane()
{
    QHBoxLayout* settingTitleLayout     = createTitle(":/setting.svg", tr("Settings"));
    QHBoxLayout* descriptionTitleLayout = createTitle(":/description.svg", tr("Description"));

    QSizePolicy sizePolicy;
    sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
    m_settingWidget = new QWidget;
    m_settingWidget->setSizePolicy(sizePolicy);

    m_descriptionWidget = new QWidget;
    m_descriptionWidget->setFixedHeight(300);

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addSpacing(10);
    vLayout->addLayout(settingTitleLayout);
    vLayout->addWidget(m_settingWidget);
    vLayout->addLayout(descriptionTitleLayout);
    vLayout->addWidget(m_descriptionWidget);
    vLayout->setMargin(0);

    QWidget* helperWidget = new QWidget;
    helperWidget->setFixedWidth(394);
    helperWidget->setLayout(vLayout);

    QWidget* vLineWidget = new QWidget;
    vLineWidget->setFixedWidth(1);
    vLineWidget->setStyleSheet("QWidget{border: 1px solid rgb(226, 226, 226);}");

    m_view = new QGraphicsView;
    m_view->setStyleSheet("border: none;");

    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(m_view);
    hLayout->addWidget(vLineWidget);
    hLayout->addWidget(helperWidget);
    hLayout->setSpacing(0);
    hLayout->setMargin(0);

    return hLayout;
}

QHBoxLayout* BasePane::createTitle(const QString & iconPath, const QString & name)
{
    QPixmap pixmap(iconPath);
    pixmap = pixmap.scaled(16, 16);
    QLabel* iconLabel = new QLabel;
    iconLabel->setPixmap(pixmap);

    QLabel* nameLabel = new QLabel;
    nameLabel->setText(name);
    nameLabel->setStyleSheet("QLabel{font-size: 16px; color: rgb(70, 84, 206);}");

    QSizePolicy sizePolicy;
    sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
    QWidget* hLineWidget = new QWidget;
    hLineWidget->setFixedHeight(1);
    hLineWidget->setSizePolicy(sizePolicy);
    hLineWidget->setStyleSheet("QWidget{border: 1px solid rgb(226, 226, 226);}");

    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addSpacing(10);
    hLayout->addWidget(iconLabel);
    hLayout->addSpacing(5);
    hLayout->addWidget(nameLabel);
    hLayout->addSpacing(3);
    hLayout->addWidget(hLineWidget);
    hLayout->setSpacing(0);
    hLayout->setMargin(0);

    return hLayout;
}

