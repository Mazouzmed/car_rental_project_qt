#include "RentForm.h"
#include "ui_RentForm.h"

RentForm::RentForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RentForm)
{
    ui->setupUi(this);
    ui->dateFrom->setDate(QDate::currentDate());
    ui->timeFrom->setTime(QTime::currentTime());
    ui->dateTo->setDate(QDate::currentDate());
    ui->timeTo->setTime(QTime::currentTime());
}

RentForm::~RentForm()
{
    delete ui;
}
