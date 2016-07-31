#include "header/mainwindow.h"
#include "header/frame.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.tein->setFocus();   //获取光标
    w.setStyleSheet("QMainWindow{background-image: url(:/chat.png)}");  //添加背景
    w.setWindowIcon(QIcon(":/we.png"));
    //    w.setWindowTitle("weChat");

//    w.setWindowOpacity(1);
//    w.setWindowFlags(Qt::FramelessWindowHint);
//    w.setAttribute(Qt::WA_TranslucentBackground);
//    w.setTitleBarWidget(titleWidget);
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
//    w.setWindowOpacity(0.7); //透明
//    w.setLineWidth(0);
//    w.setWindowFlags(Qt::FramelessWindowHint);     //去掉标题栏
    CustomFrame frame(&w, "weChat");
    frame.setWindowIcon(QIcon(":/we.png"));
//    frame.setStyleSheet("QPushButton{border-radius:5px;border-width:0px;}");
    frame.show();

    return a.exec();
}
