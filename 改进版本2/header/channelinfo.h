#ifndef CHANNELINFO_H
#define CHANNELINFO_H

#include <QString>
#include <QTabWidget>
#include <QMouseEvent>
#include <QTabBar>

class ChannelInfo
{
public:
    QString channel;
    QStringList users;
    int userCount;
    QString topic;
};

class TabWidget : public QTabWidget
{
    Q_OBJECT
public:
    TabWidget(QWidget *parent = 0);
    ~TabWidget();

    void setTabTextColor(int index, const QColor & color );

signals:
    void rightClick(const QPoint& pos);

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // CHANNELINFO_H
