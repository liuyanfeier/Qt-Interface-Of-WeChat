#ifndef GLABEL_H
#define GLABEL_H

#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QTextEdit>
#include <QCoreApplication>
#include <QtXml> //也可以include <QDomDocument>

#include "mainwindow.h"

class GLabel : public QLabel        // public QTextEdit
{
    Q_OBJECT

public:
    enum PEOPLE{She,Me};
    Q_PROPERTY(QString str_context READ getStrContext WRITE setContext)
    explicit GLabel(QWidget *parent = 0, GLabel::PEOPLE f = GLabel::She);
    void setContext(const QString s){str_context = s;}
    QString getStrContext()const{return str_context;}

    QString str_context;
    QLabel *label_text;
    QLabel *label_people;
    PEOPLE people;

public:
    int m_width;
    double m_height;
    int parent_maxwidth;

    void init();
    void initUI(GLabel::PEOPLE f){}
    void setOurText(QString, int);
    void setOurPixmap(QString);
    void setGifPixmap(QString);
    void paintEvent(QPaintEvent *e);

signals:
    void clicked();

public slots:
    void onDetailClicked(){}

private:
    void resizeEvent(QResizeEvent* size);
};

#endif
