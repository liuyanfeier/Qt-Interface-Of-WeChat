#include "chatemotion.h"
#include "ui_chatemotion.h"
#include <QHBoxLayout>

chatEmotion::chatEmotion(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatEmotion)
{
    ui->setupUi(this);

    setFixedSize(365, 130);
    setWindowFlags(windowFlags() &~ (Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint));
    setWindowFlags(Qt::FramelessWindowHint);//这个是widget的标题栏和边框去掉

    installEventFilter(this);

    //这个部分是用来显示动态图片的部分

    QMovie *pm = new QMovie(":/1.gif");
    ui->label->setMovie(pm);
    pm->start();

    pm = new QMovie(":/2.gif");
    ui->label_2->setMovie(pm);
    pm->start();

    pm = new QMovie(":/3.gif");
    ui->label_3->setMovie(pm);
    pm->start();

    pm = new QMovie(":/4.gif");
    ui->label_4->setMovie(pm);
    pm->start();

    pm = new QMovie(":/5.gif");
    ui->label_5->setMovie(pm);
    pm->start();

    pm = new QMovie(":/6.gif");
    ui->label_6->setMovie(pm);
    pm->start();

    pm = new QMovie(":/7.gif");
    ui->label_7->setMovie(pm);
    pm->start();

    pm = new QMovie(":/8.gif");
    ui->label_8->setMovie(pm);
    pm->start();

    pm = new QMovie(":/9.gif");
    ui->label_9->setMovie(pm);
    pm->start();

    pm = new QMovie(":/10.gif");
    ui->label_10->setMovie(pm);
    pm->start();

    pm = new QMovie(":/11.gif");
    ui->label_11->setMovie(pm);
    pm->start();

    pm = new QMovie(":/12.gif");
    ui->label_12->setMovie(pm);
    pm->start();

    pm = new QMovie(":/13.gif");
    ui->label_13->setMovie(pm);
    pm->start();

    pm = new QMovie(":/14.gif");
    ui->label_14->setMovie(pm);
    pm->start();

    pm = new QMovie(":/15.gif");
    ui->label_15->setMovie(pm);
    pm->start();

    pm = new QMovie(":/16.gif");
    ui->label_16->setMovie(pm);
    pm->start();

    pm = new QMovie(":/17.gif");
    ui->label_17->setMovie(pm);
    pm->start();

    pm = new QMovie(":/18.gif");
    ui->label_18->setMovie(pm);
    pm->start();

    pm = new QMovie(":/19.gif");
    ui->label_19->setMovie(pm);
    pm->start();

    pm = new QMovie(":/20.gif");
    ui->label_20->setMovie(pm);
    pm->start();

    pm = new QMovie(":/21.gif");
    ui->label_21->setMovie(pm);
    pm->start();

    pm = new QMovie(":/22.gif");
    ui->label_22->setMovie(pm);
    pm->start();

    pm = new QMovie(":/23.gif");
    ui->label_23->setMovie(pm);
    pm->start();

    pm = new QMovie(":/24.gif");
    ui->label_24->setMovie(pm);
    pm->start();

    connect(ui->label, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));//将单击的信号链接到相应的槽函数中；
    connect(ui->label_2, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_3, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_4, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_5, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_6, SIGNAL(clicked()), this ,SLOT(myqlable_clicked()));
    connect(ui->label_7, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_8, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_9, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));

    connect(ui->label_10, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_11, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_12, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_13, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_14, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_15, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_16, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_17, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_18, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_19, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));

    connect(ui->label_20, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_21, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_22, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_23, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));
    connect(ui->label_24, SIGNAL(clicked()), this, SLOT(myqlable_clicked()));

    connect(ui->label, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_2, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_3, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_4, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_5, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_6, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_7, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_8, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_9, SIGNAL(clicked()), this, SLOT(close()));

    connect(ui->label_10, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_11, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_12, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_13, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_14, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_15, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_16, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_17, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_18, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_19, SIGNAL(clicked()), this, SLOT(close()));

    connect(ui->label_20, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_21, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_22, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_23, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->label_24, SIGNAL(clicked()), this, SLOT(close()));
}

void chatEmotion::myqlable_clicked()
{
    myQLabel *sendname = qobject_cast<myQLabel*>(sender());//获取被单击的我的myqlabel的对象的名称；
    QString beclicked_name = sendname->objectName();
//    qDebug()<<beclicked_name;
    emit load_face(beclicked_name);//   发送被单击后的对戏那个的控件的名称；
}

bool chatEmotion::eventFilter(QObject *o , QEvent *e)
{
   if (QEvent::WindowDeactivate == e->type()) {//窗口停用
        hide();//或者关闭窗口
   } else
       return QWidget::eventFilter(o , e);
}

chatEmotion::~chatEmotion()
{
    delete ui;
}
