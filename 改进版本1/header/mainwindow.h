#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "textedit.h"
#include "glabel.h"
#include "chatemotion.h"

#include <QMainWindow>
#include <QDialog>
#include <QDebug>
#include <QObject>
#include <QPoint>
#include <QColorDialog>
#include <QPushButton>
#include <QFileDialog>
#include <QMimeData>
#include <QFontDialog>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QTextEdit>
#include <QClipboard>
#include <QTime>
#include <QTextBrowser>
#include <QGridLayout>
#include <QPlainTextEdit>
#include <QTextDocument>
#include <unistd.h>
#include <QMimeData>
#include <QFileInfo>
#include <QImageReader>
#include <QMovie>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QScrollArea>
#include <QMessageBox>
#include <QUrl>
#include <QTextBlock>
#include <QTextDocument>
#include <QPixmap>
#include <QDesktopWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public  QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString showTime();
    TextEdit *tein;

    bool readxml(QString str, TextEdit *);
    bool parseImgElement(const QDomElement &element, TextEdit *);

private:
    Ui::MainWindow *ui;

private:
    QPushButton *chatEmotion1;
    QPushButton *chatPicture;
    QPushButton *chatSend;
    QFont f;
    QColor c;
    QTextEdit *teout;
    QScrollArea *pArea;
    QVBoxLayout *layout1;
    QLabel *l;
    void resizeEvent(QResizeEvent* size);


private slots:
    void Emotion();
    void insertImage();
    void sendfun();
    void loadface(QString clickedname);
    void slider();

public slots:
     bool eventFilter(QObject *,QEvent *);    //注意这里
};

#endif // MAINWINDOW_H
