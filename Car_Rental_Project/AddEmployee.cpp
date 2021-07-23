#include "AddEmployee.h"
#include "ui_AddEmployee.h"

AddEmployee::AddEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployee)
{
    ui->setupUi(this);
    this->setWindowTitle("Add new Employee");
}

AddEmployee::~AddEmployee()
{
    delete ui;
}
