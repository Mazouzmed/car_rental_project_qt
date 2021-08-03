#include "RentForm.h"
#include "ui_RentForm.h"
#include"EmployeeInterface.h"
#include"QDebug"

RentForm::RentForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RentForm)
{

    QObject::connect(this,SIGNAL(dateChanged(QDate&)),this,SLOT(CalculateFare(QDate&)));
    ui->setupUi(this);
    this->setWindowTitle("Rental Summary");
    ui->dateFrom->setDate(QDate::currentDate());
    ui->timeFrom->setTime(QTime::currentTime());
    ui->dateTo->setDate(QDate::currentDate());
    ui->timeTo->setTime(QTime::currentTime());



}

RentForm::~RentForm()
{
    delete ui;
}



void RentForm::generateDescription(Vehicle *v,double fare)
{

    ui->makeLbl->setText( v->getMake());
    ui->modelLbl->setText( v->getModel());
    ui->yearLbl->setText( QString::number(v->getYear()));
    ui->mileageLbl->setText(QString::number(v->getMileage()));
    ui->wheelDriveLbl->setText(QString::number(v->getWheelDrive()));
    ui->fareLbl->setText("$"+ QString::number(fare));
}



void RentForm::on_changeBtn_clicked()
{
    this->close();
    static_cast<QDialog*>(this->parent())->show();
}


void RentForm::on_dateTo_userDateChanged(QDate &date)
{
    emit dateChanged( date);
}

void RentForm::calculateFare(QDate &date)
{
    int numberOfDays = 0;
    double total = 0;
    double fare = ui->fareLbl->text().toDouble();
    QDate todayDate = QDate::currentDate();
    numberOfDays = date.daysTo(todayDate);
    if(numberOfDays<0)
        ui->totalLbl->setText("Error! wrong number of days");
    total = fare * numberOfDays;
    ui->totalLbl->setText(QString::number(total));

}

