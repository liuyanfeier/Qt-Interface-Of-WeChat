#ifndef SETTING_H
#define SETTING_H

#include <QSettings>
#include <QDialog>

class QPushButton;
class QLineEdit;
class QComboBox;

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

    QString hostname();
    QString nickname();

private slots:
    void saveAndClose();

private:
    QSettings* config;
    QPushButton* closeButton;
    QLineEdit* hostLine;
    QLineEdit* nickLine;
    QString host;
    QString nick;
};

#endif // SETTING_H
