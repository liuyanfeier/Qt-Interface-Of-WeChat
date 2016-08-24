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
    explicit GLabel(QWidget *parent = 0, GLabel::PEOPLE f = GLabel::She);

    QLabel *label_text;
    QLabel *label_people;
    PEOPLE people;

public:
    int m_width;
    double m_height;
    int parent_maxwidth;

    void init();
    void setOurText(QString);
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
