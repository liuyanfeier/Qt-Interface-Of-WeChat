#include "header/frame.h"

#include <QtWidgets>

static const int TITLE_HEIGHT = 30;
static const int FRAME_BORDER = 2;

CustomFrame::CustomFrame(QWidget *contentWidget, const QString &title)
    : contentWidget_(contentWidget)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setMouseTracking(true);

    isMax_ = false;
    isPress_ = false;

    QLabel *logoLabel = new QLabel();
    logoLabel->setPixmap(QPixmap(":/we.png"));
    logoLabel->setFixedSize(16, 16);
    logoLabel->setScaledContents(true);

    QLabel *titleLabel = new QLabel();
    titleLabel->setText(title);
    QFont titleFont = titleLabel->font();
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setObjectName("whiteLabel");

    QToolButton *minButton = new QToolButton();
    QPixmap minPixmap = this->style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minButton->setIcon(minPixmap);
    minButton->setMaximumSize(25, 25);
//    minButton->setStyleSheet("background-color: rgb(255, 255, 255);");
    minButton->setStyleSheet("border:none");
    connect(minButton, SIGNAL(clicked()), this, SLOT(slotShowSmall()));

    maxButton_ = new QToolButton();
    maxPixmap_ = this->style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
//    maxButton_->setStyleSheet("QPushButton{border-radius:5px;border-width:0px;}");
//    maxButton_->setStyleSheet("background-color: rgb(255, 255, 255);");
    maxButton_->setMaximumSize(25, 25);
    maxButton_->setStyleSheet("border:none");
    restorePixmap_ = this->style()->standardPixmap(QStyle::SP_TitleBarNormalButton);
    maxButton_->setIcon(maxPixmap_);
    connect(maxButton_, SIGNAL(clicked()), this, SLOT(slotShowMaxRestore()));

    QToolButton *closeButton = new QToolButton();
    QPixmap closePixmap = this->style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    closeButton->setIcon(closePixmap);
//    closeButton->setStyleSheet("background-color: rgb(255, 255, 255);");
    closeButton->setMaximumSize(25, 25);
    closeButton->setStyleSheet("border:none");
    connect(closeButton, SIGNAL(clicked()), this, SLOT(slotHide()));

    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->addWidget(logoLabel);
    titleLayout->addWidget(titleLabel);
    titleLabel->setContentsMargins(4, 0, 0, 0);
    titleLayout->addStretch();
    titleLayout->addWidget(minButton, 0, Qt::AlignTop);
    titleLayout->addWidget(maxButton_, 0, Qt::AlignTop);
    titleLayout->addWidget(closeButton, 0, Qt::AlignTop);
    titleLayout->setSpacing(4);
    titleLayout->setContentsMargins(4, 0, 0, 0);

    QWidget *titleWidget = new QWidget();
    titleWidget->setLayout(titleLayout);
    titleWidget->installEventFilter(0);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(titleWidget);
    mainLayout->addWidget(contentWidget_);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(5);   //表示控件与窗体的左右边距
    this->setLayout(mainLayout);
}

void CustomFrame::slotShowSmall()
{
    this->showMinimized();
}

void CustomFrame::slotHide()
{
    this->hide();
//    this->close();
}

void CustomFrame::slotShowMaxRestore()
{
    if (isMax_) {
        this->showNormal();
        maxButton_->setIcon(maxPixmap_);
    } else {
        this->showMaximized();
        maxButton_->setIcon(restorePixmap_);
    }
    isMax_ = !isMax_;
}

void CustomFrame::mousePressEvent(QMouseEvent *e)
{
    startPos_ = e->globalPos();
    clickPos_ = e->pos();

    if (e->button() == Qt::LeftButton) {
        if (e->type() == QEvent::MouseButtonPress) {
            isPress_ = true;
        } else if (e->type() == QEvent::MouseButtonDblClick && e->pos().y() <= TITLE_HEIGHT) {
            this->slotShowMaxRestore();
        }
    }
}

void CustomFrame::mouseMoveEvent(QMouseEvent *e)
{
    if (isMax_ || !isPress_) {
        return;
    }
    this->move(e->globalPos() - clickPos_);
}

void CustomFrame::mouseReleaseEvent(QMouseEvent *)
{
    isPress_ = false;
}

bool CustomFrame::nativeEvent(const QByteArray & eventType, void * message, long * result)
{
    Q_UNUSED(eventType);
    const int HIT_BORDER = 5;
    const MSG *msg = static_cast <MSG*> (message);

    if(msg->message == WM_NCHITTEST) {
        int xPos = ((int)(short)LOWORD(msg->lParam)) - this->frameGeometry().x();
        int yPos = ((int)(short)HIWORD(msg->lParam)) - this->frameGeometry().y();
        if(this->childAt(xPos,yPos) == 0) {
            *result = HTCAPTION;
        } else {
            return false;
        }
        if(xPos > 0 && xPos < HIT_BORDER) {
            *result = HTLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0)) {
            *result = HTRIGHT;
        }
        if(yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOP;
        }
        if(yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOM;
        }
        if(xPos > 0 && xPos < HIT_BORDER && yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOPLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0) && yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOPRIGHT;
        }
        if(xPos > 0 && xPos < HIT_BORDER && yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOMLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0) && yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOMRIGHT;
        }
        return true;
    }
    return false;
}

void CustomFrame::paintEvent(QPaintEvent *e)
{
    int border = FRAME_BORDER;
    if (this->isMaximized()) {
        border = 0;
    }

    QPainter painter(this);
    QPainterPath painterPath;
    painterPath.setFillRule(Qt::WindingFill);
    painterPath.addRect(border, border, this->width() - 2 * border, this->height() - 2 * border);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(painterPath, QBrush(Qt::white));
    QColor color(200, 200, 200);
    for (int i = 0; i < border; i++) {
        color.setAlpha((i + 1) * 30);
        painter.setPen(color);
        painter.drawRect(border - i, border - i, this->width() - (border - i) * 2, this->height() - (border - i) * 2);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);

    painter.drawPixmap(QRect(border, border, this->width() - 3 * border, this->height() - 2 * border), QPixmap(":/chat.png"));
    painter.drawRect(QRect(border, TITLE_HEIGHT, this->width() - 3 * border, this->height() - TITLE_HEIGHT - border));

    QFrame::paintEvent(e);
}
