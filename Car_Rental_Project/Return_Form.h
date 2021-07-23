#ifndef RETURN_FORM_H
#define RETURN_FORM_H

#include <QDialog>

namespace Ui {
class Return_Form;
}

class Return_Form : public QDialog
{
    Q_OBJECT

public:
    explicit Return_Form(QWidget *parent = nullptr);
    ~Return_Form();

private slots:


    void on_btnExit_clicked();

private:
    Ui::Return_Form *ui;
};

#endif // RETURN_FORM_H
