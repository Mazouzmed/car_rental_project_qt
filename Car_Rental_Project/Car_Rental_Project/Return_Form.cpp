#include "Return_Form.h"
#include "ui_Return_Form.h"

Return_Form::Return_Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Return_Form)
{
    ui->setupUi(this);
    this->setWindowTitle("Return Form");
}

Return_Form::~Return_Form()
{
    delete ui;
}
void Return_Form::on_exitBtn_clicked()
{
    this->close();
}

