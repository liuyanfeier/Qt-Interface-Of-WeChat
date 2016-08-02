#include "header/myQlable.h"

myQLabel::myQLabel(QWidget *parent)
    :QLabel(parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(showclicked()));
}

void myQLabel::mousePressEvent(QMouseEvent *e)
{
    emit clicked();
}

void myQLabel::showclicked()
{
}
