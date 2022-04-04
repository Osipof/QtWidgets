#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//class FormPassword;
#include "formpassword.hpp"

class QActionGroup;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonDialogInput_clicked();

    void on_pushButtonPass_clicked();

    void on_pushButtonShow_clicked();

    void setStatusBarMessage(FormPassword::UserData ud);

    void on_pushButtonSendData_clicked();

    void setSizePolicy(QAction *action);

    void on_radioButtonList1_clicked(bool checked);

    void on_radioButtonList2_clicked(bool checked);

    void on_spinBoxStretch_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    FormPassword *fPass;
    QActionGroup *sizePolicyActionGroup;
};
#endif // MAINWINDOW_H
