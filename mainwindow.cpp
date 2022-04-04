#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialoginput.h"
#include "formpassword.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fPass(nullptr)
    , sizePolicyActionGroup(new QActionGroup(this))
{
    ui->setupUi(this);

    //Создание группы в выпадающем списке
    ui->actionFixed->setData(QSizePolicy::Fixed);
    sizePolicyActionGroup->addAction(ui->actionFixed);

    ui->actionMinimum->setData(QSizePolicy::Minimum);
    sizePolicyActionGroup->addAction(ui->actionMinimum);

    ui->actionMaximum->setData(QSizePolicy::Maximum);
    sizePolicyActionGroup->addAction(ui->actionMaximum);

    ui->actionPrefered->setData(QSizePolicy::Preferred);
    sizePolicyActionGroup->addAction(ui->actionPrefered);

    ui->actionMinimumExpanding->setData(QSizePolicy::MinimumExpanding);
    sizePolicyActionGroup->addAction(ui->actionExpanding);

    ui->actionExpanding->setData(QSizePolicy::Expanding);
    sizePolicyActionGroup->addAction(ui->actionMinimumExpanding);

    ui->actionIgnored->setData(QSizePolicy::Ignored);
    sizePolicyActionGroup->addAction(ui->actionIgnored);

    connect(sizePolicyActionGroup, &QActionGroup::triggered,
            this, &MainWindow::setSizePolicy);

//    if (ui->listWidget1->sizePolicy().verticalPolicy() == QSizePolicy::Fixed)
//        ui->actionFixed->setChecked(true);
    switch (ui->listWidget1->sizePolicy().verticalPolicy()) {
    case QSizePolicy::Fixed:
        ui->actionFixed->setChecked(true);
        break;
    case QSizePolicy::Minimum:
        ui->actionMinimum->setChecked(true);
        break;
    case QSizePolicy::Maximum:
        ui->actionMaximum->setChecked(true);
        break;
    case QSizePolicy::MinimumExpanding:
        ui->actionMinimumExpanding->setChecked(true);
        break;
    case QSizePolicy::Preferred:
        ui->actionPrefered->setChecked(true);
        break;
    case QSizePolicy::Expanding:
        ui->actionExpanding->setChecked(true);
        break;
    case QSizePolicy::Ignored:
        ui->actionIgnored->setChecked(true);
        break;
    }
}

MainWindow::~MainWindow()
{
    delete sizePolicyActionGroup;
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
//  fPass->setAttribute(Qt::WA_DeleteOnClose);
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

void MainWindow::setSizePolicy(QAction *action)
{
    if (ui->radioButtonList1->isChecked())
        switch (action->data().toInt()) {
        case QSizePolicy::Fixed:
            ui->listWidget1->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Fixed);
            break;
        case QSizePolicy::Minimum:
            ui->listWidget1->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Minimum);
            break;
        case QSizePolicy::Maximum:
            ui->listWidget1->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Maximum);
            break;
        case QSizePolicy::Preferred:
            ui->listWidget1->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Preferred);
            break;
        case QSizePolicy::MinimumExpanding:
            ui->listWidget1->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::MinimumExpanding);
            break;
        case QSizePolicy::Expanding:
            ui->listWidget1->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Expanding);
            break;
        case QSizePolicy::Ignored:
            ui->listWidget1->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Ignored);
            break;

        }
    if (ui->radioButtonList2->isChecked())
        switch (action->data().toInt()) {
        case QSizePolicy::Fixed:
            ui->listWidget2->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Fixed);
            break;
        case QSizePolicy::Minimum:
            ui->listWidget2->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Minimum);
            break;
        case QSizePolicy::Maximum:
            ui->listWidget2->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Maximum);
            break;
        case QSizePolicy::Preferred:
            ui->listWidget2->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Preferred);
            break;
        case QSizePolicy::MinimumExpanding:
            ui->listWidget2->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::MinimumExpanding);
            break;
        case QSizePolicy::Expanding:
            ui->listWidget2->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Expanding);
            break;
        case QSizePolicy::Ignored:
            ui->listWidget2->setSizePolicy(QSizePolicy::Fixed,
                                           QSizePolicy::Ignored);
            break;

        }
    //    ui->listWidget1->setSizePolicy(QSizePolicy::Fixed,
    //                                   action->data())
}


void MainWindow::on_radioButtonList1_clicked(bool checked)
{
    if (checked) {
        switch (ui->listWidget1->sizePolicy().verticalPolicy()) {
        case QSizePolicy::Fixed:
            ui->actionFixed->setChecked(true);
            break;
        case QSizePolicy::Minimum:
            ui->actionMinimum->setChecked(true);
            break;
        case QSizePolicy::Maximum:
            ui->actionMaximum->setChecked(true);
            break;
        case QSizePolicy::MinimumExpanding:
            ui->actionMinimumExpanding->setChecked(true);
            break;
        case QSizePolicy::Preferred:
            ui->actionPrefered->setChecked(true);
            break;
        case QSizePolicy::Expanding:
            ui->actionExpanding->setChecked(true);
            break;
        case QSizePolicy::Ignored:
            ui->actionIgnored->setChecked(true);
            break;
        }
    }
}


void MainWindow::on_radioButtonList2_clicked(bool checked)
{
    if (checked) {
        switch (ui->listWidget2->sizePolicy().verticalPolicy()) {
        case QSizePolicy::Fixed:
            ui->actionFixed->setChecked(true);
            break;
        case QSizePolicy::Minimum:
            ui->actionMinimum->setChecked(true);
            break;
        case QSizePolicy::Maximum:
            ui->actionMaximum->setChecked(true);
            break;
        case QSizePolicy::MinimumExpanding:
            ui->actionMinimumExpanding->setChecked(true);
            break;
        case QSizePolicy::Preferred:
            ui->actionPrefered->setChecked(true);
            break;
        case QSizePolicy::Expanding:
            ui->actionExpanding->setChecked(true);
            break;
        case QSizePolicy::Ignored:
            ui->actionIgnored->setChecked(true);
            break;
        }
    }
}

