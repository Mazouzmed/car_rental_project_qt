#include "AddEmployee.h"
#include "ui_AddEmployee.h"

#include <QFile>
#include<QDebug>

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

void AddEmployee::on_closeBtn_clicked()
{
    this->close();
}


void AddEmployee::on_saveBtn_clicked()
{
    QFile destinationFile(":/res/utils/employees.txt");
    destinationFile.open(QIODevice::Append);
    if (!destinationFile.isOpen())
        qDebug()<<"there was an error opening the file: " + destinationFile.errorString();
    QTextStream out(&destinationFile);
    out << "testing the add employee feature" <<endl;
    destinationFile.close();
}

