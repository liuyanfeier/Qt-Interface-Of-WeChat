#ifndef FRAME_H
#define FRAME_H
//重绘标题栏

#include <QFrame>

class QToolButton;

class CustomFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CustomFrame(QWidget *contentWidget, const QString &title);

public slots:
    void slotHide();
    void slotShowSmall();
    void slotShowMaxRestore();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    bool nativeEvent(const QByteArray & eventType, void * message, long * result);
    void paintEvent(QPaintEvent *);

private:
    bool isMax_;
    bool isPress_;
    QPoint startPos_;
    QPoint clickPos_;
    QWidget *contentWidget_;
    QPixmap maxPixmap_;
    QPixmap restorePixmap_;
    QToolButton *maxButton_;
};

#endif // FRAME_H
