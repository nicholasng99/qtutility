#pragma once

#include <QWidget>

class QGridLayout;
class QToolButton;
class QFrame;
class QParallelAnimationGroup;
class QScrollArea;

namespace QtUtility {
namespace widgets {

class QCollapsibleWidget : public QWidget
{
    Q_OBJECT
public:
    QCollapsibleWidget(const QString &title = "", QWidget *parent = nullptr);
    void setContentLayout(QLayout *contentLayout);

public slots:
    void setCollapsed(bool collapsed);
    void onContentUpdated();

private:
    QToolButton *m_titleButton;
    QGridLayout *m_layout;
    QScrollArea *m_content;
    QParallelAnimationGroup *m_animation;
};

} // namespace widgets
} // namespace QtUtility