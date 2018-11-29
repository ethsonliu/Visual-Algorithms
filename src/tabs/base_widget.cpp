#include "base_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

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

    m_settingsGroupBox = new QGroupBox(tr("Settings"));
//    m_settingsGroupBox->setFlat(true);
//    m_settingsGroupBox->setStyleSheet("QGroupBox{border: 1px solid rgb(214, 229, 245);}");
    m_descriptionGroupBox = new QGroupBox(tr("Description"));
//    m_descriptionGroupBox->setFlat(true);
//    m_descriptionGroupBox->setStyleSheet("QGroupBox{border: 1px solid rgb(214, 229, 245);}");

    QVBoxLayout* vLayout1 = new QVBoxLayout(m_helperWidget);
    vLayout1->addSpacing(30);
    vLayout1->addWidget(m_settingsGroupBox);
    vLayout1->addWidget(m_descriptionGroupBox);
    vLayout1->setSpacing(10);
    vLayout1->setMargin(0);

    QFrame* vLineFrame = new QFrame;
    vLineFrame->setFrameShape(QFrame::StyledPanel);
    vLineFrame->setFixedWidth(1);
    vLineFrame->setStyleSheet("QFrame{border: 1px solid rgb(214, 229, 245);}");
    QFrame* hLineFrame = new QFrame;
    hLineFrame->setFrameShape(QFrame::StyledPanel);
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

void BaseWidget::setTitle(QString title)
{
    m_titleLabel->setText(title);
}
