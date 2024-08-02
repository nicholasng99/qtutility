#pragma once

#include <QWidget>

class QToolButton;
class QVBoxLayout;
class QScrollArea;

namespace QtUtility {
namespace widgets {

class QCollapsibleWidget : public QWidget
{
    Q_OBJECT
public:
    QCollapsibleWidget(const QString &title = "", QWidget *parent = nullptr);
    void setContentLayout(QLayout *contentLayout);

signals:
    void contentSizeChanged();

public slots:
    void setCollapsed(bool collapsed);
    void updateContentSize();

private:
    QToolButton *m_titleButton;
    QVBoxLayout *m_layout;
    QScrollArea *m_content;
};

} // namespace widgets
} // namespace QtUtility