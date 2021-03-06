#include "addnewvehicle.h"
#include "ui_addnewvehicle.h"
#include <QMessageBox>


AddNewVehicle::AddNewVehicle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewVehicle)
{
    ui->setupUi(this);
    this->setFixedSize(750,500);
    this->setWindowTitle("Add New Vehicle");
    QPixmap pix(":/res/img/car_logo.jpg");
    int w = ui->lblBanner->width(); // extracting the width of the label widget
    int h = ui->lblBanner->height();// extracting the height of the label widget
    // calling setPixmap with the parameters we got in order to put a scaled image in the label
    ui->lblBanner->setPixmap(pix.scaled(w,h));
    /*
     * instantiating the dataProvider class;
     */
    data = new dataProvider;
    /*
     * initilazing comboboxes with data from the data provider class
     */
    ui->typeCombo->addItems(data->vehicleTypes());
    ui->colorCombo->addItems(data->getColors());
    ui->yearCombo->addItems(data->years());
    ui->passengerCapacityCombo->addItems(data->passengerCapacity());
    ui->wdCombo->addItems(data->wheelDrive());


}

AddNewVehicle::~AddNewVehicle()
{
    delete ui;
    delete data;
}

void AddNewVehicle::on_typeCombo_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        ui->makeCombo->clear();
        ui->makeCombo->addItems(data->carMakes());
        break;
    case 1:
        ui->makeCombo->clear();
        ui->makeCombo->addItems(data->truckMakes());
        break;
    case 2:
        ui->makeCombo->clear();
        ui->makeCombo->addItems(data->motoMakes());

        break;
        ;

    }
}


void AddNewVehicle::on_makeCombo_currentIndexChanged(int index)
{
    ui->modelCombo->clear();
    ui->modelCombo->addItems(data->getModels(ui->makeCombo->currentText()));
}



void AddNewVehicle::on_pushButton_2_clicked()
{
    int ret = QMessageBox::warning(this,"Quit?","Do you really want to quit?",QMessageBox::Yes,QMessageBox::No);
    if(ret == QMessageBox::Yes)
    this->close();
}


void AddNewVehicle::on_addBtn_clicked()
{
    //Generating the String to be sent to the dataProvider for saving
    QString str;
    str = ui->typeCombo->currentText()+","+
            ui->makeCombo->currentText()+","+
            ui->modelCombo->currentText()+","+
            ui->yearCombo->currentText()+","+
            ui->colorCombo->currentText()+","+
            ui->wdCombo->currentText()+","+
            ui->mileageLineEdit->text()+","+
            ui->baseFare->text();
    //sending the generated string to the dataprovider class
    data->addNewVehicle(str);

}


void AddNewVehicle::on_closeBtn_clicked()
{
    this->close();
}

