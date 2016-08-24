#include "header/connection.h"

#include <QtNetwork>
#include <iostream>
#include <QThread>
#include <QTime>
#include <windows.h>

Connection::Connection(QObject *parent)
    : QTcpSocket(parent)
{
    QObject::connect(this, SIGNAL(readyRead()), this, SLOT(processReadyRead()));
    QObject::connect(this, SIGNAL(connected()),this, SLOT(login()));
    QObject::connect(this, SIGNAL(disconnected()),this, SLOT(disconnected()));
    loginSent = false;
}

void Connection::start()
{
    loginSent = false;
    connectToHost(host, 18901);
    login();
}

void Connection::setNick(const QString& nick)
{
    username = nick;
}

QString Connection::nickName() const
{
    return username;
}

void Connection::setHost(const QString& hostname)
{
    host = hostname;
}

//发送消息给服务器
void Connection::sendMessage(const QString &message)
{
    if (message.isEmpty())
        return;
    QByteArray msg = message.toUtf8();
    write(msg);
}

//接受消息并解析，发回等
void Connection::processReadyRead()
{
    bool flag = false;
    while(bytesAvailable() > 0) {
        buffer.clear();
        buffer.append(readLine(256));    //读一行
        QList<QByteArray> list = buffer.split(' ');

        if(list.size() >= 2) {
            if (list.at(1).toInt() == 322) {   //322里面装的是channels
                QString msg = buffer.mid(buffer.indexOf('#'));
                qDebug() << msg;
                emit newMessage(host, msg);
//                qDebug() << host;
                flag = true;

            } else if (list.at(1).toInt() == 376) {
                sendMessage("LIST\n");
            }  else if (list.at(1).toInt() == 421) {   //Unknown command
                emit newMessage("qtchat", tr("Unknown command"));

            } else {
                if (qstrcmp(list.at(0).constData(), "PING") == 0) {
                    QString str = QString("PONG %1\n").arg(list.at(1).constData());
                    sendMessage(str);

                } else if(qstrcmp(list.at(1).constData(), "PONG") == 0) {
                    break;

                } else if ((qstrcmp(list.at(1).constData(), "QUIT") == 0) || (qstrcmp(list.at(1).constData(), "PART") == 0)) {
                    list = buffer.split('!');     //不划分，一起发出去
                    QString msg = list.at(0);
                    msg.remove(":");
                    msg.remove("\r\n");
                    qDebug() << msg;
                    emit newMessage("server", msg);
                    for (int i = 0; i < users.size(); ++i) {
                        if (qstrcmp(msg.toLocal8Bit().constData(), users.at(i)->user.toLocal8Bit().constData()) == 0) {
                            users.removeAll(users.at(i));
                            break;
                        }
                    }

                } else if (qstrcmp(list.at(1).constData(), "JOIN") == 0) {
                    list = buffer.split('!');
                    qDebug() << QString(list.at(0).constData());
                    QString msg = QString(list.at(0).constData());
                    msg.remove(":");
                    msg.remove("\r\n");
                    qDebug() << msg;
                    if (!msg.contains(username)) {
                        emit newMessage("server", msg);
                    }
                    bool match = false;
                    for (int i = 0; i < users.size(); ++i) {
                        if(qstrcmp(msg.toLocal8Bit().constData(), users.at(i)->user.toLocal8Bit().constData()) == 0)
                            match = true;
                    }
                    if (!match) {
                        UserInfo* newUser = new UserInfo;
                        newUser->user = msg;
                        users.append(newUser);
                    }

                } else if (qstrcmp(list.at(1).constData(), "PRIVMSG") == 0) {
                    QString user = QString(list.at(0).constData());
                    user.remove(":");
                    qDebug() << user << 987654321;
                    if (list.size() > 2 && list.at(2).startsWith("#")) {
                        // message to channel
                        QString channel = list.at(2);
                        QString msg = buffer.mid(list.at(0).length() + list.at(1).length() + list.at(2).length() + 4);
                        msg = QString("%1: %2").arg(user).arg(msg);
                        emit newMessage(channel, msg);

                    } else {
                        QString msg = QString("%1: %2").arg(user).arg(buffer.mid(list.at(0).length() + list.at(1).length() + list.at(2).length() + 4).constData());
                        emit newMessage(user, msg);
                    }
                }
            }
        }
    }
    if (flag) {
//        qDebug() << 12345678;
        Sleep(10);
        emit showChannels();
    }
}

//注册用户名等
void Connection::login()
{
    if(!loginSent) {
        QString msg = QString(tr("Trying to login as user %1")).arg(username);
        emit newMessage("qtchat", msg);
        QByteArray data;
        data = "NICK " + QByteArray(username.toUtf8()) + "\n";
        write(data);
        data.clear();
        data.append("USER ");
        data.append(username.toUtf8());
        data.append(" 0 * :");
        data.append(username.toUtf8());
        data.append("\n");
        write(data);
        loginSent = true;
    }
     emit succStatusChange();
}

void Connection::stop()
{
    loginSent = false;
    close();
    emit failStatusChange();
}

void Connection::disconnected()
{
    if(loginSent)
        emit newMessage("qtchat", "disconnected from server");
    loginSent = false;
    emit failStatusChange();
}

