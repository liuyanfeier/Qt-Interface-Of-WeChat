#include "header/mainwindow.h"
#include <QApplication>
#include <QScrollBar>
#include <QScrollArea>

static int a = 20;
int b = 0 ;
QString str1 = " ";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    installEventFilter(this);

    QPixmap *pixmap = NULL;
    pixmap = new QPixmap(200, 150);
    pixmap->load(":/file");
    QIcon *icon = new QIcon(*pixmap);
    chatPicture = new QPushButton(*icon, tr("P"), this);
    chatPicture->setIconSize(QSize(190, 150));
    chatPicture->setFixedSize(25, 25);
//    chatPicture->setStyleSheet("background:white");   //设置背景色

    QPixmap *pixmap1 = NULL;
    pixmap1 = new QPixmap(200, 150);
    pixmap1->load(":/e");
    QIcon *icon1 = new QIcon(*pixmap1);
    chatEmotion1 = new QPushButton(*icon1, tr("E"), this);
    chatEmotion1->setIconSize(QSize(190, 150));
    chatEmotion1->setFixedSize(24, 24);
//    chatEmotion1->setStyleSheet("background:white");

    QPixmap *pixmap2 = NULL;
    pixmap2 = new QPixmap(200, 150);
    pixmap2->load(":/c.png");
    QIcon *icon2 = new QIcon(*pixmap2);
    chatSend = new QPushButton(*icon2, tr("发送(S)"), this);
    chatSend->setIconSize(QSize(190, 150));
    chatSend->setFixedSize(60, 25);
//    chatSend->setStyleSheet("background:white");
    chatSend->setFocus(); //设置默认焦点
    chatSend->setStyleSheet("background-color: rgb(255, 255, 255);");
//    chatSend->setFlat(true);
    //chatSend->setDefault(true); //设置默认按钮，设置了这个属性，当用户按下回车的时候，就会按下该按钮
    chatSend->setShortcut(QKeySequence::InsertParagraphSeparator);

    tein = new TextEdit;
//    tein->setStyleSheet("border:none");
//    tein->setFocus();

    QGridLayout *layout = new QGridLayout;

//    layout->addWidget(pArea, 0, 0, 13, 9);
    layout->addWidget(chatEmotion1, 0, 0, 1, 1);
    layout->addWidget(chatPicture, 0, 1, 1, 1);
    layout->addWidget(chatSend, 0, 2, 1, 1);
    layout->addWidget(tein, 1, 0, 1, 11);

    pArea= new QScrollArea(this);

    //改变滚动条式样
    pArea->setStyleSheet("QScrollArea{background:#efefef;}"     //整体背景
                         "QScrollBar::vertical{background:#efefef;border:-5px solid white;margin:6px 0px 5px 0px;width:4px;}"
                         "QScrollBar::horizontal{background:#D3D3D3;border:0px solid #126691;height:10px;}"  //横向和竖向
                         "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background:#ffffff;}"
                         );
//    pArea->setFrameShape(QFrame::NoFrame);
    pArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    pArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //设置为设置为Qt::ScrollBarAlwaysOff就可以隐藏滚动条了

    teout = new QTextEdit;
    QWidget *pWidget = new QWidget();

    layout1 = new QVBoxLayout();
    layout1->setSpacing(0);
//    layout1->addStretch(1);
    pWidget->setLayout(layout1);
    pArea->setWidget(pWidget);
    pArea->setWidgetResizable(true);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(pArea, 5);
    mainLayout->addLayout(layout, 2);

    QWidget *mainWidget = new QWidget;
    mainWidget->setMinimumSize(450, 600);
    mainWidget->setLayout(mainLayout);

    setCentralWidget(mainWidget);

    this->setGeometry(0, 0, 450, 400);

    qDebug() <<  mainWidget->width();

    //verticalScrollBar(),返回垂直滚动条
    connect(pArea->verticalScrollBar(), &QAbstractSlider::rangeChanged, this, &MainWindow::slider);
    connect(chatEmotion1, &QPushButton::clicked, this, &MainWindow::Emotion); //插入表情
    connect(chatPicture, SIGNAL(clicked()), this, SLOT(insertImage()));//插入图片
    connect(chatSend, &QPushButton::clicked, this, &MainWindow::sendfun);//发送消息
}

MainWindow::~MainWindow()
{
}

void MainWindow::Emotion() //表情
{
    chatEmotion *mychat_face = new chatEmotion();
    mychat_face->setGeometry(mapToGlobal(chatEmotion1->pos()).x(),
                             mapToGlobal(chatEmotion1->pos()).y() - mychat_face->height(), 100 , 100);
    mychat_face->show();
    connect(mychat_face, SIGNAL(load_face(QString)), this, SLOT(loadface(QString)));
}

void MainWindow::loadface(QString clickedname)
{
    QString beclick_name=clickedname;
    int num_name=beclick_name.size();

    QStringList array;
    QString second_name;
    QString str;

    if(num_name==5) {
        str = tr("/1.gif");
    } else {
        array = beclick_name.split("_");//字符串分割，将对应的图片资源加载到聊天窗口
        second_name = array.at(1);
        str = "/" + second_name + ".gif";
    }

    tein->insertHtml(tr("<img src='") + "%3A"+str + tr("'/>"));
    tein->addAnimate(QUrl("%3A"+str), ":"+str);
}

bool MainWindow::readxml(QString str, TextEdit *t)
{
    QDomDocument doc ;
    if (!doc.setContent(str)) {
        return false;
    }

    QDomElement root = doc.documentElement();
    QDomNode child = root.firstChild();

    while (!child.isNull()) {
        if (child.toElement().tagName() == "body") {
            parseImgElement(child.toElement(), t);
        }
        child = child.nextSibling();
    }
    return true;
}

void MainWindow::slider()
{
    pArea->verticalScrollBar()->setValue(pArea->verticalScrollBar()->maximumHeight());
}

bool MainWindow::parseImgElement(const QDomElement &element, TextEdit *t)
{
    QDomNode child = element.firstChild();

    int n = rand();

    while (!child.isNull()) {
//        qDebug() << child.toElement().tagName();
        if (child.toElement().tagName() == "img") {
            QString str1 = child.toElement().attribute("src");
            qDebug() << str1;

            if (str1.indexOf("file:///") != -1)
                str1.remove("file:///");

            GLabel *label;
            if (n % 2) {
                label = new GLabel(this, GLabel::Me);
            } else {
                label = new GLabel(this, GLabel::She);
            }

//            label->setGeometry(5, a, 100, 66);
//            label->show();
//            a = label->y() + label->height() + 10;
            if(str1.indexOf("gif") != -1) {
                label->setGifPixmap(str1);
            }
            else {
                label->setOurPixmap(str1);
            }

            label->setMinimumSize(label->width(), label->height());
            label->setMaximumSize(label->width(), label->height());
            label->setScaledContents(true);   //自动和文本一样的高度

            layout1->insertWidget(b, label);
            b++;

            layout1->addSpacerItem(new QSpacerItem(87, 66, QSizePolicy::Expanding, QSizePolicy::Expanding));

            t->insertHtml(tr("<img src='") + str1 + tr("'/>"));
            t->addAnimate(QUrl(str1), str1);

            parseImgElement(child.toElement(), t);

        } else if (child.toElement().tagName() == "p") {
            qDebug() << child.toElement().text();
            if (child.toElement().text() != "") {
                GLabel *label;
                if (n % 2) {
                    label = new GLabel(this, GLabel::Me);
                } else {
                    label = new GLabel(this, GLabel::She);
                }

//                label->show();
//                label->setGeometry(5, a, 100, 66);
                label->setOurText(child.toElement().text(), 1);
                qDebug() << label->width() << label->height();

                label->setMinimumSize(label->width(), label->height());
                label->setMaximumSize(label->width(), label->height());
                label->setScaledContents(true);   //自动和文本一样的高度

                layout1->insertWidget(b, label);
                layout1->addSpacerItem(new QSpacerItem(87, 66, QSizePolicy::Expanding, QSizePolicy::Expanding));
                b++;

//                pArea->verticalScrollBar()->setValue(pArea->verticalScrollBar()->maximumHeight());
                //滚动条自动滚动到最后，但是差一点？？？？

                qDebug() << layout1->count();
                t->append(str1);
            }
            parseImgElement(child.toElement(), t);
        }
        child = child.nextSibling();
    }
}

void MainWindow::resizeEvent(QResizeEvent* size)
{
}

void MainWindow::sendfun()
{
    if (tein->toPlainText() == "") {
        QMessageBox::information(this, tr("..."), tr("消息为空"));
        return;
    }

    l = new QLabel(this);

    if (str1 != showTime()) {
        l->setText(showTime());
        layout1->insertWidget(b, l);   //居中显示
        l->setAlignment(Qt::AlignHCenter);
        b++;
    }
    str1 = showTime();
//    l->move(100, 0);

//    pArea->setWidget(l);
//    l->setGeometry((this->size().width()) / 2 - 80, a - 10 , 100, 66);
//    l->setWordWrap(true);
//    l->setAlignment(Qt::AlignHCenter);
//    l->show();

    QString str = tein->toHtml();
    str.replace("%3A", ":");
    qDebug() << str;

    TextEdit *t = new TextEdit(teout);
    readxml(str, t);
//    pArea->ensureVisible(5, a + 20);
    tein->clear();
}

void MainWindow::insertImage() //插入图片
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                                ".", tr("Images (*.png *.gif *.jpg *jpeg)"));
    if (file.isEmpty()) {
        return;
    }

    tein->insertHtml(tr("<img src='") + file + tr("'/>"));
    tein->addAnimate(QUrl(file), file);
//    QTextImageFormat imageFormat;
//    imageFormat.setName(file);
//    QTextCursor cursor = tein->textCursor();
//    cursor.insertImage(imageFormat);
}

QString MainWindow::showTime()//获取系统时间
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    return text;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    Q_ASSERT (obj == tein) ;
    if (e ->type() == QEvent::KeyPress )
    {
       QKeyEvent *event = static_cast <QKeyEvent*>(e) ;
       if (event->key() == Qt::Key_Return && (event->modifiers() & Qt::ControlModifier ) )
       {
           sendfun();
           return true ;
       }
    }
    return false ;
}

