#include "QtUtility/widgets/qcollapsible_widget.hpp"

#include <QFrame>
#include <QGridLayout>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QScrollArea>
#include <QToolButton>

namespace {
// milliseconds
constexpr uint ANIMATION_DURATION = 100;
} // namespace

namespace QtUtility {
namespace widgets {

QCollapsibleWidget::QCollapsibleWidget(const QString &title, QWidget *parent)
    : QWidget(parent)

    , m_titleButton(new QToolButton())
    , m_layout(new QGridLayout(this))
    , m_content(new QScrollArea())
    , m_animation(new QParallelAnimationGroup())
{
    m_titleButton->setText(title);
    m_titleButton->setStyleSheet("QToolButton { border: none; padding-bottom: 5px; }");
    m_titleButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_titleButton->setArrowType(Qt::ArrowType::DownArrow);
    m_titleButton->setCheckable(true);
    m_titleButton->setChecked(false);

    m_content->setStyleSheet("QScrollArea { border: none; }");
    m_content->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    // start out collapsed
    m_content->setMaximumHeight(0);
    m_content->setMinimumHeight(0);
    // let the entire widget grow and shrink with its content
    m_animation->addAnimation(new QPropertyAnimation(this, "minimumHeight"));
    m_animation->addAnimation(new QPropertyAnimation(this, "maximumHeight"));
    m_animation->addAnimation(new QPropertyAnimation(m_content, "maximumHeight"));
    // don't waste space
    m_layout->setAlignment(Qt::AlignTop);
    m_layout->setVerticalSpacing(0);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_titleButton, 0, 0, 1, 1, Qt::AlignLeft);
    m_layout->addWidget(m_content, 1, 0, 1, 2);

    QObject::connect(m_titleButton, &QToolButton::clicked, this, &QCollapsibleWidget::setCollapsed);
}

void QCollapsibleWidget::setContentLayout(QLayout *contentLayout)
{
    if (!contentLayout)
        return;
    if (m_content->layout() == contentLayout)
        return;
    delete m_content->layout();
    m_content->setLayout(contentLayout);
    onContentUpdated();
}

void QCollapsibleWidget::onContentUpdated()
{
    const auto collapsedHeight = sizeHint().height() - m_content->maximumHeight();
    auto contentHeight = m_content->sizeHint().height();
    for (int i = 0; i < m_animation->animationCount() - 1; ++i) {
        QPropertyAnimation *spoilerAnimation = static_cast<QPropertyAnimation *>(
            m_animation->animationAt(i));
        spoilerAnimation->setDuration(ANIMATION_DURATION);
        spoilerAnimation->setStartValue(collapsedHeight);
        spoilerAnimation->setEndValue(collapsedHeight + contentHeight);
    }
    QPropertyAnimation *contentAnimation = static_cast<QPropertyAnimation *>(
        m_animation->animationAt(m_animation->animationCount() - 1));
    contentAnimation->setDuration(ANIMATION_DURATION);
    contentAnimation->setStartValue(0);
    contentAnimation->setEndValue(contentHeight);

    setMinimumHeight(collapsedHeight + contentHeight);
    setMaximumHeight(collapsedHeight + contentHeight);
    m_content->setMaximumHeight(contentHeight);
}

void QCollapsibleWidget::setCollapsed(bool collapsed)
{
    m_titleButton->setArrowType(collapsed ? Qt::ArrowType::RightArrow : Qt::ArrowType::DownArrow);
    m_animation->setDirection(collapsed ? QAbstractAnimation::Backward
                                        : QAbstractAnimation::Forward);
    m_animation->start();
}

} // namespace widgets
} // namespace QtUtility
