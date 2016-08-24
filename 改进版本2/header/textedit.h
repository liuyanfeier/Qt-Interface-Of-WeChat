#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QMimeData>
#include <QFileInfo>
#include <QImageReader>
#include <QMovie>
#include <QDebug>

class TextEdit : public QTextEdit
{
    Q_OBJECT

public:
    TextEdit(QWidget *parent = Q_NULLPTR);
    void addAnimate(const QUrl &url, const QString &fileName);
    bool canInsertFromMimeData(const QMimeData* source) const;
    void insertFromMimeData(const QMimeData* source);

private slots:
    void animate();

private:
    void dropImage(const QUrl& url, const QImage& image);
    void dropTextFile(const QUrl& url);

    QList<QUrl> lstUrl;
    QHash<QMovie*, QUrl> urls;

};

#endif // TEXTEDIT_H
