#include "base_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
BaseWidget::BaseWidget(QWidget* parent) : QWidget(parent)
{
    QPixmap pixmap(":/images/tab.svg");
    pixmap = pixmap.scaled(26, 26);

    m_iconLabel = new QLabel;
    m_iconLabel->setPixmap(pixmap);

    m_titleLabel = new QLabel;
    m_titleLabel->setText("Ubuntu 18.04 x64 Dev");
    m_titleLabel->setStyleSheet("QLabel{font-size: 22px; color: rgb(7, 123, 227);}");

    QHBoxLayout* hLayout1 = new QHBoxLayout;
    hLayout1->addWidget(m_iconLabel);
    hLayout1->addWidget(m_titleLabel);
    hLayout1->addStretch();
    hLayout1->setSpacing(8);
    hLayout1->setContentsMargins(8, 8, 0, 8);

    m_helperWidget = new QWidget;
    m_helperWidget->setFixedWidth(350);

    m_view = new QGraphicsView;

    QWidget* settingWidget = createTitleWidget(tr("Settings"), ":/images/setting.svg");
    QWidget* descriptionWidget = createTitleWidget(tr("Description"), ":/images/description.svg");

    QVBoxLayout* vLayout1 = new QVBoxLayout(m_helperWidget);
    vLayout1->addSpacing(30);
    vLayout1->addWidget(settingWidget);
    vLayout1->addSpacing(100);
    vLayout1->addWidget(descriptionWidget);
    vLayout1->setSpacing(10);
    vLayout1->setMargin(0);

    QFrame* vLineFrame = new QFrame;
    vLineFrame->setFixedWidth(1);
    vLineFrame->setStyleSheet("QFrame{border: 1px solid rgb(214, 229, 245);}");
    QFrame* hLineFrame = new QFrame;
    hLineFrame->setFixedHeight(1);
    hLineFrame->setStyleSheet("QFrame{border: 1px solid rgb(214, 229, 245);}");

    QHBoxLayout* hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(m_helperWidget);
    hLayout2->addWidget(vLineFrame);
    hLayout2->addWidget(m_view);
    hLayout2->setSpacing(12);
    hLayout2->setMargin(0);

    QVBoxLayout* vLayout2 = new QVBoxLayout;
    vLayout2->addLayout(hLayout1);
    vLayout2->addWidget(hLineFrame);
    vLayout2->addLayout(hLayout2);
    vLayout2->setSpacing(0);
    vLayout2->setMargin(0);

    this->setLayout(vLayout2);
}

void BaseWidget::setPaneName(QString name)
{
    m_titleLabel->setText(name);
}

QWidget* BaseWidget::createTitleWidget(QString name, QString iconPath)
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

    QFrame* hLineFrame = new QFrame;
    hLineFrame->setFixedHeight(1);
    hLineFrame->setSizePolicy(sizePolicy);
    hLineFrame->setStyleSheet("QFrame{border: 1px solid rgb(226, 226, 226);}");

    QWidget* widget = new QWidget;

    QHBoxLayout* hLayout = new QHBoxLayout(widget);
    hLayout->addSpacing(10);
    hLayout->addWidget(iconLabel);
    hLayout->addSpacing(5);
    hLayout->addWidget(nameLabel);
    hLayout->addSpacing(3);
    hLayout->addWidget(hLineFrame);
    hLayout->setSpacing(0);
    hLayout->setMargin(0);

    return widget;
}

