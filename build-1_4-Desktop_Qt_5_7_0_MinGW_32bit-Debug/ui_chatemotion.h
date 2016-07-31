/********************************************************************************
** Form generated from reading UI file 'chatemotion.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATEMOTION_H
#define UI_CHATEMOTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "header/myQlable.h"

QT_BEGIN_NAMESPACE

class Ui_chatEmotion
{
public:
    QTabWidget *tabWidget;
    QWidget *default_faces;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    myQLabel *label_8;
    myQLabel *label_7;
    myQLabel *label_6;
    myQLabel *label_5;
    myQLabel *label_4;
    myQLabel *label_3;
    myQLabel *label_2;
    myQLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    myQLabel *label_11;
    myQLabel *label_16;
    myQLabel *label_15;
    myQLabel *label_14;
    myQLabel *label_13;
    myQLabel *label_12;
    myQLabel *label_10;
    myQLabel *label_9;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    myQLabel *label_20;
    myQLabel *label_22;
    myQLabel *label_24;
    myQLabel *label_23;
    myQLabel *label_21;
    myQLabel *label_19;
    myQLabel *label_18;
    myQLabel *label_17;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    myQLabel *label_27;
    myQLabel *label_32;
    myQLabel *label_31;
    myQLabel *label_30;
    myQLabel *label_29;
    myQLabel *label_28;
    myQLabel *label_26;
    myQLabel *label_25;
    QWidget *sdefine_faces;

    void setupUi(QWidget *chatEmotion)
    {
        if (chatEmotion->objectName().isEmpty())
            chatEmotion->setObjectName(QStringLiteral("chatEmotion"));
        chatEmotion->resize(377, 170);
        tabWidget = new QTabWidget(chatEmotion);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, -20, 371, 161));
        default_faces = new QWidget();
        default_faces->setObjectName(QStringLiteral("default_faces"));
        horizontalLayoutWidget = new QWidget(default_faces);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 381, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new myQLabel(horizontalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/imqface/8.gif")));

        horizontalLayout->addWidget(label_8);

        label_7 = new myQLabel(horizontalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/imqface/7.gif")));

        horizontalLayout->addWidget(label_7);

        label_6 = new myQLabel(horizontalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/imqface/6.gif")));

        horizontalLayout->addWidget(label_6);

        label_5 = new myQLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/imqface/5.gif")));

        horizontalLayout->addWidget(label_5);

        label_4 = new myQLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/imqface/4.gif")));

        horizontalLayout->addWidget(label_4);

        label_3 = new myQLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/imqface/3.gif")));

        horizontalLayout->addWidget(label_3);

        label_2 = new myQLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/imqface/2.gif")));

        horizontalLayout->addWidget(label_2);

        label = new myQLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imqface/1.gif")));

        horizontalLayout->addWidget(label);

        horizontalLayoutWidget_2 = new QWidget(default_faces);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 30, 381, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_11 = new myQLabel(horizontalLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/imqface/11.gif")));

        horizontalLayout_2->addWidget(label_11);

        label_16 = new myQLabel(horizontalLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/imqface/16.gif")));

        horizontalLayout_2->addWidget(label_16);

        label_15 = new myQLabel(horizontalLayoutWidget_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/imqface/15.gif")));

        horizontalLayout_2->addWidget(label_15);

        label_14 = new myQLabel(horizontalLayoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/imqface/14.gif")));

        horizontalLayout_2->addWidget(label_14);

        label_13 = new myQLabel(horizontalLayoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/imqface/13.gif")));

        horizontalLayout_2->addWidget(label_13);

        label_12 = new myQLabel(horizontalLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/imqface/12.gif")));

        horizontalLayout_2->addWidget(label_12);

        label_10 = new myQLabel(horizontalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/imqface/10.gif")));

        horizontalLayout_2->addWidget(label_10);

        label_9 = new myQLabel(horizontalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/imqface/9.gif")));

        horizontalLayout_2->addWidget(label_9);

        horizontalLayoutWidget_3 = new QWidget(default_faces);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 60, 381, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_20 = new myQLabel(horizontalLayoutWidget_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/imqface/20.gif")));

        horizontalLayout_3->addWidget(label_20);

        label_22 = new myQLabel(horizontalLayoutWidget_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/imqface/22.gif")));

        horizontalLayout_3->addWidget(label_22);

        label_24 = new myQLabel(horizontalLayoutWidget_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/imqface/24.gif")));

        horizontalLayout_3->addWidget(label_24);

        label_23 = new myQLabel(horizontalLayoutWidget_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/imqface/23.gif")));

        horizontalLayout_3->addWidget(label_23);

        label_21 = new myQLabel(horizontalLayoutWidget_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/imqface/21.gif")));

        horizontalLayout_3->addWidget(label_21);

        label_19 = new myQLabel(horizontalLayoutWidget_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/imqface/19.gif")));

        horizontalLayout_3->addWidget(label_19);

        label_18 = new myQLabel(horizontalLayoutWidget_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/imqface/18.gif")));

        horizontalLayout_3->addWidget(label_18);

        label_17 = new myQLabel(horizontalLayoutWidget_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/imqface/17.gif")));

        horizontalLayout_3->addWidget(label_17);

        horizontalLayoutWidget_4 = new QWidget(default_faces);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(0, 90, 381, 37));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_27 = new myQLabel(horizontalLayoutWidget_4);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/imqface/27.gif")));

        horizontalLayout_4->addWidget(label_27);

        label_32 = new myQLabel(horizontalLayoutWidget_4);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setPixmap(QPixmap(QString::fromUtf8(":/imqface/32.gif")));

        horizontalLayout_4->addWidget(label_32);

        label_31 = new myQLabel(horizontalLayoutWidget_4);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setPixmap(QPixmap(QString::fromUtf8(":/imqface/31.gif")));

        horizontalLayout_4->addWidget(label_31);

        label_30 = new myQLabel(horizontalLayoutWidget_4);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setPixmap(QPixmap(QString::fromUtf8(":/imqface/30.gif")));

        horizontalLayout_4->addWidget(label_30);

        label_29 = new myQLabel(horizontalLayoutWidget_4);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setPixmap(QPixmap(QString::fromUtf8(":/imqface/29.gif")));

        horizontalLayout_4->addWidget(label_29);

        label_28 = new myQLabel(horizontalLayoutWidget_4);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setPixmap(QPixmap(QString::fromUtf8(":/imqface/28.gif")));

        horizontalLayout_4->addWidget(label_28);

        label_26 = new myQLabel(horizontalLayoutWidget_4);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/imqface/26.gif")));

        horizontalLayout_4->addWidget(label_26);

        label_25 = new myQLabel(horizontalLayoutWidget_4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setPixmap(QPixmap(QString::fromUtf8(":/imqface/25.gif")));

        horizontalLayout_4->addWidget(label_25);

        tabWidget->addTab(default_faces, QString());
        sdefine_faces = new QWidget();
        sdefine_faces->setObjectName(QStringLiteral("sdefine_faces"));
        tabWidget->addTab(sdefine_faces, QString());

        retranslateUi(chatEmotion);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(chatEmotion);
    } // setupUi

    void retranslateUi(QWidget *chatEmotion)
    {
        chatEmotion->setWindowTitle(QApplication::translate("chatEmotion", "Form", 0));
        label_8->setText(QString());
        label_7->setText(QString());
        label_6->setText(QString());
        label_5->setText(QString());
        label_4->setText(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        label->setText(QString());
        label_11->setText(QString());
        label_16->setText(QString());
        label_15->setText(QString());
        label_14->setText(QString());
        label_13->setText(QString());
        label_12->setText(QString());
        label_10->setText(QString());
        label_9->setText(QString());
        label_20->setText(QString());
        label_22->setText(QString());
        label_24->setText(QString());
        label_23->setText(QString());
        label_21->setText(QString());
        label_19->setText(QString());
        label_18->setText(QString());
        label_17->setText(QString());
        label_27->setText(QString());
        label_32->setText(QString());
        label_31->setText(QString());
        label_30->setText(QString());
        label_29->setText(QString());
        label_28->setText(QString());
        label_26->setText(QString());
        label_25->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(default_faces), QApplication::translate("chatEmotion", "\351\273\230\350\256\244\350\241\250\346\203\205", 0));
        tabWidget->setTabText(tabWidget->indexOf(sdefine_faces), QApplication::translate("chatEmotion", "\350\207\252\345\256\232\344\271\211", 0));
    } // retranslateUi

};

namespace Ui {
    class chatEmotion: public Ui_chatEmotion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATEMOTION_H
