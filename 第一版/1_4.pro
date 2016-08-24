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


SOURCES += source/main.cpp\
        source/mainwindow.cpp \
    source/textedit.cpp \
    source/glabel.cpp \
    source/myqlable.cpp \
    source/chatemotion.cpp \
    source/frame.cpp

HEADERS  += header/mainwindow.h \
    header/textedit.h \
    header/glabel.h \
    header/myqlable.h \
    header/chatemotion.h \
    header/frame.h

FORMS    += UI/mainwindow.ui \
    UI/chatemotion.ui

RESOURCES += resource/res.qrc\
