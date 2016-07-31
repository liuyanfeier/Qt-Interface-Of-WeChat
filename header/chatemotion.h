#ifndef CHATEMOTION_H
#define CHATEMOTION_H

#include <QWidget>
#include <QMovie>

#include "myqlable.h"

namespace Ui {
class chatEmotion;
}

class chatEmotion : public QWidget
{
    Q_OBJECT

public:
    explicit chatEmotion(QWidget *parent = 0);
    ~chatEmotion();

private slots:
    void myqlable_clicked();

signals:
    void load_face(QString myqlabel_name);

private:
    Ui::chatEmotion *ui;
    myQLabel *lable;

protected:
    bool eventFilter(QObject *o, QEvent *e);//事件过滤器
};

#endif // CHATEMOTION_H
