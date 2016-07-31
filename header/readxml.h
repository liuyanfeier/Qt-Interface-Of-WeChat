#ifndef READXML_H
#define READXML_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QDebug>
#include <QDomElement>

class readXml
{
public:
    readXml();
    ~readXml();

    bool read(QString str);

private:
    void parseImgElement(const QDomElement &element);
};

#endif // READXML_H
