#ifndef DIALOGINPUT_H
#define DIALOGINPUT_H

#include <QDialog>

namespace Ui {
class DialogInput;
}

class DialogInput : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInput(QWidget *parent = nullptr);
    ~DialogInput();

    void setString(const QString &str);
    QString string() const;

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::DialogInput *ui;
};

#endif // DIALOGINPUT_H
