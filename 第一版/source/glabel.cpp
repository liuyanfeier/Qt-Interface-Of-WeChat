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
        label_people->setGeometry(10, 18, 30, 30);
        label_text->setStyleSheet("QLabel{background:rgb(255 , 255 ,255)}");
        label_people->setPixmap(QPixmap(":/b"));
    } else {
       label_people->setGeometry(this->width() - 10, 18, 30, 30);
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

    m_height = 66;

    label_text->setGeometry(20 + 30, 20, this->width() + 100, this->height() + 100);
    qDebug() << label_text->width() << this->width();
    QPixmap Pix;
    Pix.load(paramstr);

    if (Pix.width() < 100 || Pix.height() < 100) {
        Pix= Pix.scaled(30, 30, Qt::KeepAspectRatio);
        label_text->setPixmap(Pix);

        m_width = label_text->width();
        this->resize(m_width - 90, m_height - 1);

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
        if (movie->scaledSize().width() > 30) {
            movie->setScaledSize(QSize(30, 30));
        }
        label_text->setMovie(movie);
        movie->start();


        label_text->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
        label_text->adjustSize();

//        m_height = label_text->width() * 1.0 / 300 * label_text->height();
        m_height = label_text->height();
        m_width  = parent_maxwidth - 15;
        this->resize(m_width, m_height + 40);

    } else {
        label_text->setWordWrap(false);
        m_height = 66;

        QMovie *movie = new QMovie(paramstr);
        qDebug() << movie->scaledSize().height();
        if (movie->scaledSize().width() > 30) {
            movie->setScaledSize(QSize(30, 30));
        }
        label_text->setMovie(movie);
        movie->start();

        label_text->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
        label_text->adjustSize();

        m_width = label_text->width() + 40 + 30;
        this->resize(m_width + 10, m_height);

//        label_text->setMaximumWidth(100);
//        this->setMaximumWidth(100);
    }

    if (people == GLabel::She) {
        label_text->setGeometry(20 + 40, 20, this->width() - 40 - 30, this->height()-40);
    } else {
        label_text->setGeometry(20, 20, this->width() - 40 - 30, this->height() - 40);
    }
    update();
}

void GLabel::setOurText(QString paramstr)
{
    int max_width = parent_maxwidth - 50;
    int all_word_width;

    qDebug() << paramstr;

//    //让QLabel自适应text的大小，直接用下面的代码;
//    label_text->adjustSize();
//    //让QLabel能够自动判断并换行显示;
//    label_text->setWordWrap(true);
//    label_text->setAlignment(Qt::AlignTop);
//    label_text = new QLabel;

    label_text->setWordWrap(false);
    label_text->setText(paramstr);
    label_text->adjustSize();

    all_word_width = label_text->width();
    label_text->setWordWrap(true);

    if (all_word_width > max_width) {
        qDebug() << parent_maxwidth;

        label_text->setMaximumWidth(max_width - 20 - 30);
        label_text->setScaledContents(true);
        label_text->setText(paramstr);

        label_text->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
        label_text->adjustSize();

        m_height = label_text->height();
        m_width  = parent_maxwidth - 15;
        this->resize(m_width, m_height + 40);

    } else {
        label_text->setWordWrap(false);
        m_height = 66;

        label_text->setScaledContents(true);
        label_text->setText(paramstr);

        label_text->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
        label_text->adjustSize();

        m_width = label_text->width() + 40 + 30;
        this->resize(m_width + 10, m_height);

    }

    if (people == GLabel::She) {
        label_text->setGeometry(20 + 40, 20, this->width() - 40 - 30, this->height()-40);
    } else {
        label_text->setGeometry(20, 20, this->width() - 40 - 30, this->height() - 40);
    }
    update();
}

void GLabel::resizeEvent(QResizeEvent* size){
//    parent_maxwidth = ((QWidget*)this->parent())->width();
    if (people==GLabel::Me) {
        label_people->setGeometry(this->width() - 30, 18, 30, 30);
        this->setGeometry(((QWidget*)this->parent())->width()- 15 - this->width(), this->y(), this->width(), (this->height()));
    }
}

void GLabel::paintEvent(QPaintEvent *e)
{
    if (people == GLabel::She) {
        QRectF rectangle(50.0, 10.0, this->width() - 20 - 40, this->height() - 20);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(QBrush(QColor(255, 255, 255)));
        painter.drawRoundedRect(rectangle, 10, 10);

        QPointF points[3] = {
           QPointF(40, 33),
           QPointF(51, 29),
           QPointF(50, 38),
       };

       QPen pen;
       pen.setColor(QColor(255, 255, 255));
       painter.setPen(pen);
       painter.drawPolygon(points, 3);

       QPen pen1;
       pen1.setColor(Qt::black);
       painter.setRenderHint(QPainter::Antialiasing, true);
       painter.setPen(pen1);
       painter.drawLine(points[0], points[1]);
       painter.drawLine(points[0], points[2]);
    }
    else if(people == GLabel::Me)
    {
        QRectF rectangle;
//        if (this->width() > 300) {
//            rectangle.setRect(10.0, 10.0, 300, this->height() - 20);
//        } else {
//            rectangle.setRect(10.0, 10.0, this->width() - 20 - 40, this->height() - 20);
//        }
        rectangle.setRect(10.0, 10.0, this->width() - 20 - 40, this->height() - 20);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(QBrush(QColor(0, 255, 0)));
        painter.drawRoundedRect(rectangle, 10, 10);

        QPointF points[3] = {
           QPointF(this->width()-40, 33),
           QPointF(this->width()-51, 28),
           QPointF(this->width()-51, 38),
       };

       QPen pen;
       pen.setColor(QColor(0, 255, 0));
       painter.setPen(pen);
       painter.drawPolygon(points, 3);

       QPen pen1;
       pen.setColor(Qt::black);
       painter.setPen(pen1);
       painter.setRenderHint(QPainter::Antialiasing, true);
       painter.drawLine(points[0], points[1]);
       painter.drawLine(points[0], points[2]);

       label_people->setGeometry(this->width() - 30, 18, 30, 30);

//       if (this->width() > 300) {
//           this->setGeometry(((QWidget*)this->parent())->width()- 15 - this->width(), this->y(), 360, (this->height()));
//       } else {
//           this->setGeometry(((QWidget*)this->parent())->width()- 15 - this->width(), this->y(), this->width(), (this->height()));
//       }
       this->setGeometry(((QWidget*)this->parent())->width()- 15 - this->width(), this->y(), this->width(), (this->height()));
    }
}
