#include "header/channelinfo.h"

TabWidget::TabWidget(QWidget *parent)
    : QTabWidget(parent)
{
}

TabWidget::~TabWidget()
{
}

void TabWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
        emit rightClick(event->pos());

    event->ignore();
}

void TabWidget::setTabTextColor(int index, const QColor & color)
{
    tabBar()->setTabTextColor(index, color);
}
