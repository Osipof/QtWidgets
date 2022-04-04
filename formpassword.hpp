#ifndef FORMPASSWORD_H
#define FORMPASSWORD_H

#include <QWidget>

namespace Ui {
class FormPassword;
}

class FormPassword : public QWidget
{
    Q_OBJECT

public:
    struct UserData
    {
        QString userName;
        QString password;
    };

    explicit FormPassword(QWidget *parent = nullptr);
    ~FormPassword();

    void setUserData(const UserData &ud);
    UserData userData() const;

signals:
    void valueChanged(FormPassword::UserData ud);

private slots:
    void on_pushButtonOk_clicked();

private:
    Ui::FormPassword *ui;
    UserData currentUserData;
};

#endif // FORMPASSWORD_H
