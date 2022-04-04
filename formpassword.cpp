#include "formpassword.hpp"
#include "ui_formpassword.h"

FormPassword::FormPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPassword)
{
    ui->setupUi(this);
}

FormPassword::~FormPassword()
{
    delete ui;
}

void FormPassword::setUserData(const UserData &ud)
{
    currentUserData = ud;
    ui->lineEditUserName->setText(ud.userName);
    ui->lineEditPassword->setText(ud.password);
}

FormPassword::UserData FormPassword::userData() const
{
    return currentUserData;
}

void FormPassword::on_pushButtonOk_clicked()
{
    currentUserData.userName = ui->lineEditUserName->text();
    currentUserData.password = ui->lineEditPassword->text();

    emit valueChanged(currentUserData);
    close();
}

