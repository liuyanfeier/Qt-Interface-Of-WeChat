#include "header/glabel.h"
#include "header/readxml.h"

#include <QPen>
#include <QDebug>
#include <QMovie>
#include <QFile>

GLabel::GLabel(QWidget *parent, GLabel::PEOPLE f)
    : QLabel(parent)
    , people(f)
    , parent_maxwidth(((QWidget*)this->parent())->width())
{
    this->setMaximumWidth(405);
    init();
    setTextInteractionFlags(Qt::TextSelectableByMouse);//设置鼠标可以选择标志
    connect(this, SIGNAL(clicked()), this, SLOT(onDetailClicked()));
}

void GLabel::init()
{
//    label = new QLabel();
//    label->setPixmap(QPixmap::fromImage(image));
//    label->resize(QSize(image.width(),image.height()));
//    ui->scrollImag->setWidget(label);

    label_text = new QLabel(this);
//    label_text->setMaximumWidth(300);
//    this->setMaximumWidth(300);
    label_text->setWordWrap(true);
    label_text->setGeometry(20 + 30, 20, this->width() - 40 - 30, this->height() - 40);
    label_text->setStyleSheet("QLabel{background:rgb(255, 255, 255)}");
    label_text->show();

    label_people = new QLabel(this);
    if (people == GLabel::She) {
        label_people->setGeometry(15, 11, 30, 30);
        label_text->setStyleSheet("QLabel{background:rgb(255 , 255 ,255)}");
        label_people->setPixmap(QPixmap(":/b"));
    } else {
       label_people->setGeometry(this->width() - 15, 11, 30, 30);
       label_text->setStyleSheet("QLabel{background:rgb(0, 255, 0)}");
       label_people->setPixmap(QPixmap(":/a"));
    }
}

void GLabel::setOurPixmap(QString paramstr)
{
    qDebug() << paramstr;

    label_text->setWordWrap(false);
    label_text->adjustSize();

    label_text->setWordWrap(true);

    m_height = 60;

    label_text->setGeometry(20 + 30, 20, this->width() + 100, this->height() + 100);
    qDebug() << label_text->width() << this->width();
    QPixmap Pix;
    Pix.load(paramstr);

    if (Pix.width() < 100 || Pix.height() < 100) {
        Pix= Pix.scaled(30, 30, Qt::KeepAspectRatio);
        label_text->setPixmap(Pix);

        m_width = label_text->width();
        this->resize(m_width - 90, m_height + 10);

        label_text->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
        label_text->adjustSize();
    } else {
        Pix= Pix.scaled(100, 100, Qt::KeepAspectRatio);
        label_text->setPixmap(Pix);

        m_width = label_text->width() + 40 + 30;
        this->resize(m_width - 90, m_height + 80);

        label_text->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
        label_text->adjustSize();
    }

    if (people == GLabel::She) {
        label_text->setGeometry(20 + 40, 20, this->width() - 40 - 30, this->height()-40);
    } else {
        label_text->setGeometry(20, 20, this->width() - 40 - 30, this->height() - 40);
    }
    update();
}

void GLabel::setGifPixmap(QString paramstr)
{
    int max_width = parent_maxwidth - 50;
    int all_word_width;

    qDebug() << paramstr;

    label_text->setWordWrap(false);
    label_text->adjustSize();

    all_word_width = label_text->width();
    label_text->setWordWrap(true);

    if (all_word_width > max_width) {
        qDebug() << parent_maxwidth;

        label_text->setMaximumWidth(max_width - 20 - 30);

        QMovie *movie = new QMovie(paramstr);
        QPixmap pixmap(paramstr);
        if (pixmap.width() > 50 || pixmap.height() > 50) {
            movie->setScaledSize(QSize(50, 50));
        }
        label_text->setMovie(movie);
        movie->start();

        label_text->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
        label_text->adjustSize();

//        m_height = label_text->width() * 1.0 / 300 * label_text->height();
        m_height = label_text->height();
        m_width  = parent_maxwidth - 10;
        this->resize(m_width, m_height + 40);

    } else {
        label_text->setWordWrap(false);
        m_height = 60;

        QMovie *movie = new QMovie(paramstr);

        QPixmap pixmap(paramstr);
        if (pixmap.width() > 60 || pixmap.height() > 60) {
            movie->setScaledSize(QSize(60, 60));
            m_height = 90;
        }
        label_text->setMovie(movie);
        movie->start();

        if (m_height == 90) {
            m_width = label_text->width() + 40 + 65;
        } else {
            m_width = label_text->width() + 40 + 30;
        }

        this->resize(m_width + 18, m_height);

        label_text->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
        label_text->adjustSize();
    }

    if (people == GLabel::She) {
        label_text->setGeometry(20 + 35, 20, this->width() - 40 - 30, this->height()-40);
    } else {
        label_text->setGeometry(15, 20, this->width() - 40 - 20, this->height() - 40);
    }
    update();
}

void GLabel::setOurText(QString paramstr, int a)
{
    int max_width = 360;
    int all_word_width;

    qDebug() << paramstr;

    label_text->setWordWrap(false);
    label_text->setText(paramstr);
    label_text->adjustSize();
    all_word_width = label_text->width();
    label_text->setWordWrap(true);

    if (all_word_width > max_width) {
        qDebug() << label_text->width();
        if (a==1) {
            label_text->setScaledContents(true);
            label_text->setText(paramstr);
        }
        label_text->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
        label_text->adjustSize();

        m_height = label_text->height();
        m_width  = parent_maxwidth - 15;
        qDebug() << m_height;
        if (m_height <= 15){
            this->resize(m_width, label_text->width() / 10);
        } else if (m_height < 200) {
            this->resize(m_width, m_height + (m_height / 44 )* 10);
        } else {
            this->resize(m_width, m_height + (m_height / 44 )* 20);
        }


    } else {
        label_text->setWordWrap(false);
        m_height = 66;

        if (a==1) {
            label_text->setScaledContents(true);
            label_text->setText(paramstr);

        }
        label_text->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
        label_text->adjustSize();

        m_width = label_text->width() + 40 + 30 + 5;
        this->resize(m_width, m_height);

//        label_text->setMaximumWidth(100);
//        this->setMaximumWidth(100);
    }

    if (people == GLabel::She) {
        label_text->setGeometry(20 + 38, 20, this->width() - 40 - 30, this->height()-40);
    } else {
        label_text->setGeometry(18, 20, this->width() - 40 - 30, this->height() - 40);
    }
    update();
}

void GLabel::resizeEvent(QResizeEvent *size)
{
//    parent_maxwidth = ((QWidget*)this->parent())->width();
    if (people == GLabel::Me) {
        label_people->setGeometry(this->width() - 30, 18, 30, 30);
        this->setGeometry(((QWidget*)this->parent())->width()- 15 - this->width(), this->y(), this->width(), (this->height()));
    }
}

void GLabel::paintEvent(QPaintEvent *e)
{
    if (people == GLabel::She) {
        QRectF rectangle(50.0, 10.0, this->width() - 18 - 40, this->height() - 24);

        QPainter painter(this);
        painter.setPen(QPen(Qt::black, 1));
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(QPen(Qt::white));
        painter.setBrush(QBrush(QColor(255, 255, 255)));
        painter.drawRoundRect(rectangle, 3.0, 3.0);

        QPointF points[3] = {
           QPointF(44, 23),
           QPointF(50, 20),
           QPointF(50, 26),
       };

       QPen pen;
       pen.setColor(QColor(255, 255, 255));
       painter.setPen(pen);
       painter.drawPolygon(points, 3);

       QPen pen1;
       pen1.setColor(Qt::white);
       painter.setRenderHint(QPainter::Antialiasing, true);
       painter.setPen(pen1);
       painter.drawLine(points[0], points[1]);
       painter.setRenderHint(QPainter::Antialiasing, true);
       painter.drawLine(points[0], points[2]);
    } else if (people == GLabel::Me) {
        QRectF rectangle;
        rectangle.setRect(10.0, 10.0, this->width() - 16 - 40, this->height() - 24);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(QPen(Qt::green));
        painter.setBrush(QBrush(QColor(0, 255, 0)));
        painter.drawRoundRect(rectangle, 3.0, 3.0);

        QPointF points[3] = {
           QPointF(this->width()-42, 23),
           QPointF(this->width()-48, 18),
           QPointF(this->width()-48, 28),
       };

       QPen pen;
       pen.setColor(QColor(0, 255, 0));
       painter.setPen(pen);
       painter.drawPolygon(points, 3);

       QPen pen1;
       pen1.setColor(Qt::green);
       painter.setPen(pen1);
       painter.setRenderHint(QPainter::Antialiasing, true);
       painter.drawLine(points[0], points[1]);
       painter.setRenderHint(QPainter::Antialiasing, true);
       painter.drawLine(points[0], points[2]);

       label_people->setGeometry(this->width() - 33, 11, 30, 30);
       this->setGeometry(((QWidget*)this->parent())->width()- 15 - this->width(), this->y(), this->width(), (this->height()));
    }
}
