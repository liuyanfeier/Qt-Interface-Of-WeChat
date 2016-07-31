#include "readxml.h"

readXml::readXml()
{
}

readXml::~readXml()
{
}

bool readXml::read(QString str)
{
    QDomDocument doc ;
    if (!doc.setContent(str)) {
        return false;
    }

    QDomElement root = doc.documentElement();
    QDomNode child = root.firstChild();

    while (!child.isNull()) {
        if (child.toElement().tagName() == "body") {
            parseImgElement(child.toElement());
        }
        child = child.nextSibling();
    }
    return true;
}

void readXml::parseImgElement(const QDomElement &element)
{
    QDomNode child = element.firstChild();

    while (!child.isNull()) {
//        qDebug() << child.toElement().tagName();
        if (child.toElement().tagName() == "img") {
            qDebug() << child.toElement().attribute("src");
            parseImgElement(child.toElement());
        } else if (child.toElement().tagName() == "p") {
            qDebug() << child.toElement().text();
            parseImgElement(child.toElement());
        }
        child = child.nextSibling();
    }
}
