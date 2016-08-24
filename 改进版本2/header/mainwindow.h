#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "textedit.h"
#include "glabel.h"
#include "chatemotion.h"
#include "setting.h"
#include "connection.h"
#include "channelinfo.h"

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

#include <QList>
#include <QTextEdit>
#include <QDialog>
#include <QTabWidget>
#include <QModelIndex>
#include <QListView>
#include <QStandardItemModel>

class QGridLayout;
class QListWidget;
class QLabel;
class QLineEdit;
class QListWidgetItem;

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

    QPushButton *chatEmotion1;
    QPushButton *chatPicture;
    QPushButton *chatSend;
    QFont f;
    QColor c;
    QTextEdit *teout;
    QScrollArea *pArea;
    QVBoxLayout *layout1;
    QLabel *l;

    QLabel *statusLabel;
    void resizeEvent(QResizeEvent* size);

private slots:
    void Emotion();
    void insertImage();
    void sendfun();
    void loadface(QString clickedname);
    void slider();
    void produce();

public slots:
     bool eventFilter(QObject *,QEvent *);    //注意这里

private:
    QMenu   *serverMenu;
    QMenu   *preferencesMenu;
    QMenu   *windowMenu;
    QMenu   *helpMenu;

    QAction *loginAct;
    QAction *logoutAct;
    QAction *settingsAct;
    QAction *aboutAct;
    QAction *closeWindowAct;
    QAction *listAct;

    SettingsDialog* settingsDialog;

private:
    QLabel      *label;
    TabWidget   *tabWidget;
    QListView   *channelListView;

    QList<ChannelInfo*> channelLists;
    QList<ChannelInfo*> allChannels;

    Connection* connection;
    QString nickname;
    QString hostname;

public:
    void setNick(QString nick);
    void setHost(QString host);
    void start();

    void showMessage(const QString &channel, const QString &msg, QColor color);
    void closeCurrentWindow();
    void channelSelection();

private slots:
    void about();
    void settings();
    void login();
    void logout();
    void closeWindow();
    void channelList();

public slots:
    void displayMessage(const QString &from, const QString &message);
    void joinChannel(const QModelIndex& index);
    void succStatusChange();
    void failStatusChange();
};

#endif // MAINWINDOW_H
