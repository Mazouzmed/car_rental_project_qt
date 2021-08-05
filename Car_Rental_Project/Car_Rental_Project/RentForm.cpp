#include "RentForm.h"
#include "ui_RentForm.h"
#include"EmployeeInterface.h"
#include"QDebug"

RentForm::RentForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RentForm)
{

    //connect(this,ui->dateTo->dateChanged(QDate&),this,)
    qDebug()<< QObject::connect(this,SIGNAL(ui->dateTo->dateChanged(QDate&)),this,SLOT(CalculateFare(QDate&)));
    ui->setupUi(this);
    this->setWindowTitle("Rental Summary");
    QDate date = QDate::currentDate();
    ui->dateFrom->setDate(QDate::currentDate());
    date = date.addDays(1);
    ui->dateTo->setDate(date);
    ui->insuranceCheckBox->setText("Include insurance(+"+QString::number(INSURANCE_RATE)+"/day)");



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
    emit dateChanged(date);
}

void RentForm::on_dateTo_userDateChanged(const QDate &date)
{

}


void RentForm::on_calculateFare_clicked()
{

    int numberOfDays = 0;
    double total = 0;
    QString fareString = ui->fareLbl->text().replace("$","");
    double fare = fareString.toDouble();
    QDate todayDate = QDate::currentDate();
    QDate toDate = ui->dateTo->date();
    numberOfDays = todayDate.daysTo(toDate);
    if(numberOfDays<0)
       QMessageBox::warning(this,"Error","Error calculating the total, please check the dates!");
    else{
        if(ui->insuranceCheckBox->isChecked())
            fare+=INSURANCE_RATE;
        total = fare * numberOfDays;
        ui->totalLcd->display(QString::number(total));
    }
}


void RentForm::on_saveBtn_clicked()
{
    QString path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project/rental_transactions.txt";
    QString str;
    str = ui->txtId->text()+","+
            ui->txtId->text()+","+
            ui->txtName->text()+","+
            ui->txtAddress->text()+","+
            ui->txtPhone->text()+","+
            ui->makeLbl->text()+","+
            ui->modelLbl->text()+","+
            ui->yearLbl->text()+","+
            QString::number(ui->totalLcd->intValue())+","+
            ui->dateFrom->text()+","+
            ui->dateTo->text();
    if(dataProvider::appendToFile(str,path)){
        QMessageBox::information(this,"Saved!","Transaction saved Successfully!");
    }
    else
        QMessageBox::warning(this,"Error!","Unable to save the transaction!");
}

