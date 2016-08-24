#include <QtGui>

#include "header/setting.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    config = new QSettings("liuyanfeier", "124.243.202.5");

    nick = config->value("nickname").toString();
    host = config->value("hostname").toString();

    QGridLayout* mainLayout = new QGridLayout(this);

    QLabel* hostLabel = new QLabel;
    hostLabel->setText(tr("hostname"));

    QLabel* nickLabel = new QLabel;
    nickLabel->setText(tr("nickname"));

    hostLine = new QLineEdit;
    hostLine->setText(host);

    nickLine = new QLineEdit;
    nickLine->setText(nick);

    closeButton = new QPushButton(tr("Save and Close"));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(saveAndClose()));

    mainLayout->addWidget(hostLabel, 0, 0, 1, 1);
    mainLayout->addWidget(hostLine, 0, 1, 1, 1);
    mainLayout->addWidget(nickLabel, 1, 0, 1, 1);
    mainLayout->addWidget(nickLine, 1, 1, 1, 1);

    mainLayout->addWidget(closeButton, 2, 0, 1, 2);

    setLayout(mainLayout);
    setWindowTitle(tr("Settings"));
}

SettingsDialog::~SettingsDialog()
{
}

QString SettingsDialog::nickname()
{
    return nick;
}

QString SettingsDialog::hostname()
{
    return host;
}

void SettingsDialog::saveAndClose()
{
    host = hostLine->text();
    nick = nickLine->text();

    config->setValue("hostname", host);
    config->setValue("nickname", nick);

    close();
}


