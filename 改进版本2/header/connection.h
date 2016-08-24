#ifndef CONNECTION_H
#define CONNECTION_H

#include <QHostAddress>
#include <QString>
#include <QStringList>
#include <QTcpSocket>
#include <QTimer>

class UserInfo
{
public:
    UserInfo() { user.clear();
                 realName.clear();
                 ip.clear();
                 channels.clear();
                 server.clear();
                 comment.clear();
                 away = false; }
    ~UserInfo() {}

    QString user;
    QString realName;
    QString ip;
    QString channels;
    QString server;
    QString comment;
    bool    away;
};

class Connection : public QTcpSocket
{
    Q_OBJECT
public:
    Connection(QObject *parent = 0);

    void setNick(const QString &name);
    QString nickName() const;
    void setHost(const QString &host);
    void start();
    void stop();

    QList<UserInfo*> users;

public slots:
    void sendMessage(const QString &message);

signals:
    void newMessage(const QString &from, const QString &message);     //信号，显示时使用
    void succStatusChange();
    void failStatusChange();
    void showChannels();

private slots:
    void login();
    void disconnected();
    void processReadyRead();

private:
    QTimer*     timer;
    QString     host;
    QString     username;
    QByteArray  buffer;
    bool        loginSent;
    int         position;
};

#endif
