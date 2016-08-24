#include "header/mainwindow.h"
#include <QApplication>
#include <QScrollBar>
#include <QScrollArea>

static int a = 20;
int b = 0 ;
QString currentChannels = " ";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    installEventFilter(this);

    settingsDialog = new SettingsDialog;
    connection = new Connection;

    connect(connection, SIGNAL(newMessage(const QString &, const QString &)),
            this, SLOT(displayMessage(const QString &, const QString &)));
    connect(connection, SIGNAL(succStatusChange()),
            this, SLOT(succStatusChange()));
    connect(connection, SIGNAL(failStatusChange()),
            this, SLOT(failStatusChange()));

    QDesktopWidget desktop;
    QRect space = desktop.availableGeometry();

    tabWidget = new TabWidget;
    tabWidget->setTabPosition(QTabWidget::South);
    if(space.width() > 640) {
        tabWidget->setMinimumWidth(540);
    } else {
        tabWidget->setMinimumWidth(space.width() * 3 / 4);
    }

    channelListView = 0;

    loginAct = new QAction(tr("&Connect"), this);
    connect(loginAct, SIGNAL(triggered()), this, SLOT(login()));
    logoutAct = new QAction(tr("&Disconnect"), this);
    connect(logoutAct, SIGNAL(triggered()), this, SLOT(logout()));
    listAct = new QAction(tr("&Join Channel"), this);
    connect(listAct, SIGNAL(triggered()), this, SLOT(channelList()));
    closeWindowAct = new QAction(tr("&Close"), this);
    connect(closeWindowAct, SIGNAL(triggered()), this, SLOT(closeWindow()));

    connect(connection, SIGNAL(showChannels()), this, SLOT(channelList()));

    serverMenu = new QMenu(tr("&Server"), this);
    serverMenu->addAction(loginAct);
    serverMenu->addAction(logoutAct);
    serverMenu->addAction(listAct);
    serverMenu->addAction(closeWindowAct);

    menuBar()->addMenu(serverMenu);

    settingsAct = new QAction(tr("&Settings"), this);
    connect(settingsAct, SIGNAL(triggered()), this, SLOT(settings()));

    preferencesMenu = new QMenu(tr("&Settings"), this);
    preferencesMenu->addAction(settingsAct);

    menuBar()->addMenu(preferencesMenu);

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);

    menuBar()->addMenu(helpMenu);





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

    statusLabel = new QLabel();
    statusLabel->setText(tr("ready"));
    QGridLayout *layout = new QGridLayout;

//    layout->addWidget(pArea, 0, 0, 13, 9);
    layout->addWidget(chatEmotion1, 0, 0, 1, 1);
    layout->addWidget(chatPicture, 0, 1, 1, 1);
    layout->addWidget(chatSend, 0, 2, 1, 1);
    layout->addWidget(statusLabel, 0, 9, 1, 2);
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
//    pArea->setStyleSheet("border:none");
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

    this->setGeometry(100, 100, 450, 400);

    qDebug() <<  mainWidget->width();

    //verticalScrollBar(),返回垂直滚动条
    connect(pArea->verticalScrollBar(), &QAbstractSlider::rangeChanged, this, &MainWindow::slider);
    connect(chatEmotion1, &QPushButton::clicked, this, &MainWindow::Emotion); //插入表情
    connect(chatPicture, &QPushButton::clicked, this, &MainWindow::insertImage);//插入图片
    connect(chatSend, &QPushButton::clicked, this, &MainWindow::sendfun);//发送消息
    
//    //测试效率
//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(produce()));
//    timer->start(100);
}

MainWindow::~MainWindow()
{
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About weChat"),
            tr("<p>weChat is a special irc chat client that allows you to make "
               "audio calls to other weChat users on your channel.</p>"
               "<p>COMMANDS:</p>"
               "/close (Closes current window)<br>"
               "/exit (Close All windows and exit application)<br>"
               "/quit (Leave current channel, closing all associated windows)<br>"
               "/list (List all available channels)<br>"
               "/join {#channel} (Join a channel)<br>"
               ));
}

void MainWindow::settings()
{
    settingsDialog->show();
}

void MainWindow::succStatusChange()
{
    statusLabel->setText(tr("已连接"));
}

void MainWindow::failStatusChange()
{
    statusLabel->setText(tr("已断开"));
}

void MainWindow::setNick(QString nick)
{
    nickname = nick;
    connection->setNick(nick);
}

void MainWindow::setHost(QString host)
{
    hostname = host;
    connection->setHost(host);
}

void MainWindow::start()
{
    QString msg = QString(tr("Trying to connect to %1 on port 18901").arg(hostname));
    displayMessage("qtchat", msg);

    connection->start();    //连接服务器
    allChannels.clear();    //清空之前的channels
}

void MainWindow::logout()
{
    QString msg = QString(tr("User disconnection from %1").arg(hostname));
    displayMessage("qtchat", msg);
    connection->stop();
}

void MainWindow::closeCurrentWindow()
{
    if (currentChannels != " ") {
        QString msg = QString("PART #%1\n").arg(currentChannels);
        connection->sendMessage(msg);
    }
    exit(0);
}

//显示消息
void MainWindow::displayMessage(const QString &from, const QString &message)
{
    if(from.isEmpty() || message.isEmpty())
        return;

    QColor msgColor = Qt::gray;

    //添加channels
    if (from.contains(hostname) && message.startsWith("#")) {
        // Entry from channel list
        QStringList list = message.split(" ");
        if(list.size() >= 3) {
            QString ch = list.at(0);
            ch.remove("#");
            int count = list.at(1).toInt();
            QString topic = message.mid(list.at(0).length() + list.at(1).length() + 3);
            topic.remove("\n");
            bool match = false;
            for (int i = 0; i < allChannels.size(); ++i) {
                if (allChannels.at(i)->channel == ch) {
                    match = true;
                    break;
                }
            }
            if(!match) {
                ChannelInfo *info = new ChannelInfo;
                info->channel = ch;
                info->userCount = count;
                info->topic = topic;
                allChannels.append(info);
            }
        }
        return;
    }

    QString msg = QString(message);
    msg.remove("\n");
    showMessage(from, msg, msgColor);
}

//显示
void MainWindow::showMessage(const QString &channel, const QString &message, QColor color)
{
    QDateTime now(QDateTime::currentDateTime());
    QString msg = QString("%1: %2").arg(now.toString("dd/MM/yy HH:mm")).arg(message);

    GLabel *label;
    if (channel.contains("server") || channel.contains("qtchat")) {
        label = new GLabel(this, GLabel::She);
    } else {
        label = new GLabel(this, GLabel::Me);
    }

    qDebug() << msg << nickname;
    if (msg.contains(nickname)) {
        qDebug() << msg << 12345678;
        QFont ft("宋体", 15);
//        ft.setPointSize(30);
        label->setFont(ft);
//        QPalette pa;
//        pa.setColor(QPalette::WindowText,Qt::red);
//        label->setPalette(pa);
    }

    label->setOurText(msg);
    qDebug() << label->width() << label->height();

    label->setMinimumSize(label->width(), label->height());
    label->setMaximumSize(label->width(), label->height());
    label->setScaledContents(true);   //自动和文本一样的高度

    layout1->insertWidget(b++, label);
    layout1->addSpacerItem(new QSpacerItem(label->width(), label->height(), QSizePolicy::Expanding, QSizePolicy::Expanding));

//   pArea->verticalScrollBar()->setValue(pArea->verticalScrollBar()->maximumHeight());
//滚动条自动滚动到最后，但是差一点？？？？
}

//显示并选择channels
void MainWindow::channelSelection()
{
    if(!channelListView) {
        channelListView = new QListView;
        connect(channelListView, SIGNAL(pressed(const QModelIndex&)),
                this, SLOT(joinChannel(const QModelIndex&)));
        QStandardItemModel *model = new QStandardItemModel();
        for(int i = 0; i < allChannels.size() ; ++i) {
            QStandardItem *item = new QStandardItem(allChannels.at(i)->channel);
            model->setItem(i, 0, item);
        }
        channelListView->setModel(model);
    }
    channelListView->show();
}

void MainWindow::login()
{
    qDebug() << settingsDialog->hostname() << settingsDialog->nickname();
    this->setHost(settingsDialog->hostname());
    this->setNick(settingsDialog->nickname());
    this->start();
}

void MainWindow::closeWindow()
{
    this->closeCurrentWindow();
}

void MainWindow::channelList()
{
//    QString msg = QString("LIST");
//    displayMessage("server", msg);
//    msg.append("\n");
//    connection->sendMessage(msg);
    this->channelSelection();
}

//加入channels
void MainWindow::joinChannel(const QModelIndex& index)
{
    channelListView->hide();
    qWarning() << index.data();
    currentChannels = index.data().toString();
    QString msg = QString("JOIN #%1").arg(index.data().toString());
    displayMessage(QString("#%1").arg(index.data().toString()), msg);
    msg.append("\n");
    connection->sendMessage(msg);
}

void MainWindow::Emotion() //表情
{
    chatEmotion *mychat_face = new chatEmotion();
    mychat_face->setGeometry(mapToGlobal(chatEmotion1->pos()).x(),
                             mapToGlobal(chatEmotion1->pos()).y() - mychat_face->height(), 100 , 100);
    //设置子窗口显示的时候相对主窗口的位置
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

void MainWindow::slider()
{
    pArea->verticalScrollBar()->setValue(pArea->verticalScrollBar()->maximumHeight());
}

void MainWindow::produce()
{
    QString str = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">当从 QPixmap 对象构造图标时，系统会自动产生窗口不同状态下对应的图像，比如窗口在禁用状态下其图标为灰色。从文件构造图标时，文件并不是立刻加载，而是当图标要显示时才加载。 </p></body></html>";
    tein->insertHtml(str);
//    sleep(500);
    chatSend->click();
//    str = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/20.gif\" /></p></body></html>";
//    tein->insertHtml(str);
//    chatSend->click();
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

            layout1->insertWidget(b++, label);
            layout1->addSpacerItem(new QSpacerItem(label->width(), label->height(), QSizePolicy::Expanding, QSizePolicy::Expanding));

            t->insertHtml(tr("<img src='") + str1 + tr("'/>"));
            t->addAnimate(QUrl(str1), str1);

            parseImgElement(child.toElement(), t);

        } else if (child.toElement().tagName() == "p") {
            qDebug() << child.toElement().text();
            if (child.toElement().text() != "") {

                QString text = child.toElement().text();
                qDebug() << text;

                QRegExp rr1("/exit");
                QRegExp rr2("/close");
                QRegExp rr3("/quit");
                QRegExp rr4("/list");
                QRegExp rr5("/join.*");

                if (rr1.exactMatch(text)) {
                    exit(0);
                } else if (rr2.exactMatch(text)) {
                    closeCurrentWindow();
                } else if (rr3.exactMatch(text)) {
                    closeCurrentWindow();
                } else if (rr4.exactMatch(text)) {
                    QString msg = QString("LIST");
                    displayMessage("server", msg);
                    msg.append("\n");
                    connection->sendMessage(msg);
//                    sleep(1);
//                    emit listAct->trigger();
//                    connect(this, SIGNAL(listAct), SLOT(triggered()));
                } else if (rr5.exactMatch(text)) {
                    QStringList list = text.split(' ');
                    QString msg = QString("JOIN %1").arg(list.at(1));
                    qDebug() << msg;
                    currentChannels = QString("%1").arg(list.at(1)).remove("#");
                    displayMessage("server", msg);
                    msg.append("\n");
                    connection->sendMessage(msg);
                } else {
                    QString msg = QString("%1: ").arg(nickname);
                    msg.append(text);

                    qDebug() << currentChannels;
                    text = QString("PRIVMSG #%1 :%2").arg(currentChannels).arg(text);
                    displayMessage(currentChannels, msg);
                    text.append("\n");
                    connection->sendMessage(text);
                }

                qDebug() << layout1->count();
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

//    l = new QLabel(this);

//    if (str1 != showTime()) {
//        l->setText(showTime());
//        layout1->insertWidget(b++, l);   //居中显示
//        l->setAlignment(Qt::AlignHCenter);
//    }
//    str1 = showTime();
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

bool MainWindow::eventFilter(QObject *obj, QEvent *e)   //回车快捷键设置
{
//    Q_ASSERT (obj == tein) ;
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

