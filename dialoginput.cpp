#include "dialoginput.h"
#include "ui_dialoginput.h"

DialogInput::DialogInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInput)
{
    ui->setupUi(this);
}

DialogInput::~DialogInput()
{
    delete ui;
}

void DialogInput::setString(const QString &str)
{
    ui->lineEdit->setText(str);
}

QString DialogInput::string() const
{
    return ui->lineEdit->text();
}

void DialogInput::on_lineEdit_textChanged(const QString &arg1)
{
    if (!arg1.isEmpty())
        ui->pushButtonOk->setEnabled(true);
    else
        ui->pushButtonOk->setDisabled(true);

}

