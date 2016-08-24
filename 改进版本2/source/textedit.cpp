#include "header/textedit.h"

#include <QFile>
#include <QDebug>
#include <QMovie>

TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent)
{
}

bool TextEdit::canInsertFromMimeData(const QMimeData* source) const
{
    return source->hasImage() || source->hasUrls() ||
        QTextEdit::canInsertFromMimeData(source);
}

void TextEdit::insertFromMimeData(const QMimeData* source)
{
    if (source->hasImage()) {
        qDebug() << "hasImage";
        static int i = 1;
        QUrl url(QString("dropped_image_%1").arg(i++));
        dropImage(url, qvariant_cast<QImage>(source->imageData()));
    } else if (source->hasUrls()) {
        qDebug() << "hasUrls";
        foreach (QUrl url, source->urls()) {
            QFileInfo info(url.toLocalFile());
            if (QImageReader::supportedImageFormats().contains(info.suffix().toLower().toLatin1())) {
                dropImage(url, QImage(info.filePath()));
            }
            else {
                dropTextFile(url);
            }
        }
    } else {
        QTextEdit::insertFromMimeData(source);
    }
}

//显示动图
void TextEdit::addAnimate(const QUrl &url, const QString &fileName)
{
    QFile *file = new QFile(fileName);
    if (!file->open(QIODevice::ReadOnly)) {
        qDebug() << "Open Err";
    }

    if (lstUrl.contains(url)){
        return;
    } else {
        lstUrl << url;
    }

    QMovie *movie = new QMovie(this);
    movie->setFileName(fileName);
    movie->setCacheMode(QMovie::CacheNone);
    urls.insert(movie, url);
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(animate()));
    movie->start();
}

void TextEdit::animate(){
    if (QMovie *movie = qobject_cast<QMovie *>(sender())) {
        document()->addResource(QTextDocument::ImageResource, urls.value(movie), movie->currentPixmap());
        setLineWrapColumnOrWidth(lineWrapColumnOrWidth());
    }
}

void TextEdit::dropImage(const QUrl& url, const QImage& image)
{
    if (!image.isNull()) {
        insertHtml(QString("<img src='%1'/>").arg(url.toString()));

        if (lstUrl.contains(url)) {
            return;
        } else {
            lstUrl << url;
        }

        QMovie *movie = new QMovie(this);
        movie->setFileName(url.toLocalFile());
        movie->setCacheMode(QMovie::CacheNone);
        urls.insert(movie, url);
        connect(movie, SIGNAL(frameChanged(int)), this, SLOT(animate()));
        movie->start();
    }
}

void TextEdit::dropTextFile(const QUrl& url)
{
    QFile file(url.toLocalFile());
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        textCursor().insertText(file.readAll());
    }
}

