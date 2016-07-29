#-------------------------------------------------
#
# Project created by QtCreator 2016-07-22T11:02:46
#
#-------------------------------------------------

QT       +=  xml
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = weChat
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    textedit.cpp \
    glabel.cpp \
    myqlable.cpp \
    chatemotion.cpp \
    frame.cpp

HEADERS  += mainwindow.h \
    textedit.h \
    glabel.h \
    myqlable.h \
    chatemotion.h \
    frame.h

FORMS    += mainwindow.ui \
    chatemotion.ui

RESOURCES += \
    res.qrc
