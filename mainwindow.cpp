#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialoginput.h"
#include "formpassword.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fPass(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonDialogInput_clicked()
{
    DialogInput diag(this);

    diag.exec();

    if (diag.result() == DialogInput::Accepted)
        ui->statusbar->showMessage(diag.string());
}


void MainWindow::on_pushButtonPass_clicked()
{
    fPass = new FormPassword(this);
    fPass->setWindowFlag(Qt::Window);
//    fPass->setAttribute(Qt::WA_DeleteOnClose);
    fPass->setWindowModality(Qt::WindowModal);

    connect(fPass, &FormPassword::valueChanged,
            this, &MainWindow::setStatusBarMessage);

    fPass->show();

}


void MainWindow::on_pushButtonShow_clicked()
{
    if(fPass)
        fPass->show();
}

void MainWindow::setStatusBarMessage(FormPassword::UserData ud)
{
   ui->statusbar->showMessage("User Name: " + ud.userName +
                              " |Password: " + ud.password);
}


void MainWindow::on_pushButtonSendData_clicked()
{
    FormPassword::UserData newUD = {"Name", "pass"};

    fPass->setUserData(newUD);
    fPass->show();
}

