#include "EmployeeInterface.h"
#include<QPixmap>

AdminInterface *adminWindow;
EmployeeInterface::EmployeeInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeInterface)
{
    ui->setupUi(this);

    /*
     * Using Qpixmap in order to include an image in the label
     */
    QPixmap pix(":/res/img/background1.jpg");
    int w = ui->lblBackgroundTitle->width(); // extracting the width of the label widget
    int h = ui->lblBackgroundTitle->height();// extracting the height of the label widget
    /*
     * calling setPixmap with the parameters we got in order to put a scaled image in the label
     */
    ui->lblBackgroundTitle->setPixmap(pix.scaled(w,h));

    //hiding the admin button
    ui->backToAdminBtn->hide();



    /*
     * setting up the model from the file
     * to populate the table view on the Ui
     */

    model = new QStandardItemModel(this);
    model->clear();
    /*
     * Creating the header of the table view
     */
    QStringList headers;
    headers.append("Type");
    headers.append("Make");
    headers.append("Model");
    headers.append("Year");
    headers.append("Color");
    headers.append("WheelDrive");
    headers.append("Mileage");
    headers.append("Fare");

    model->setColumnCount(5);
    model->setHorizontalHeaderLabels(headers);


    QFile sourceFile(":/res/utils/Available_Cars.txt");
    sourceFile.open(QIODevice::ReadOnly);
    if(!sourceFile.isOpen()){
        //  qDebug() << "Unable to open the file"<<endl;
        QMessageBox::information(this,"error",sourceFile.errorString());
    }
    QTextStream in(&sourceFile);
    int row =0;
    while(!in.atEnd()){

        QString line = in.readLine();
        QStringList fields = line.split(",");
        for(size_t i = 0;i<fields.length();i++){
            QStandardItem *item = new QStandardItem(fields.at(i));
            model->setItem(row,i,item);
        }

        row++;
    }
    sourceFile.close();
    ui->availableVehTable->setModel(model);
    ui->availableVehTable->setAlternatingRowColors(true);

}

EmployeeInterface::~EmployeeInterface()
{
    delete ui;
}

void EmployeeInterface::makeAdminButtonVisible()
{
    if(ui->backToAdminBtn->isHidden())
        ui->backToAdminBtn->show();
}

void EmployeeInterface::on_btnEmplQuit_clicked()
{
    QMessageBox::StandardButton reply =  QMessageBox::warning(this,"Quit?","Are you sure you want to quit ?",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        this->close();
    }
}

void EmployeeInterface::on_btnOptions_clicked()
{

}

void EmployeeInterface::on_btnRent_2_clicked()
{
    rentForm  = new RentForm(this);
    Vehicle *v = NULL;


    //retrieving the selected vehicle from the model.
    QModelIndexList selectedList = ui->availableVehTable->selectionModel()->selectedIndexes();
        if(selectedList.empty())
            QMessageBox::warning(this,"empty selection!","Please select the car to rent first");

        else{
        QModelIndex index = selectedList.at(0);
          if(index.data() == "Car")
             v= new Car;
          else if(index.data()=="Truck")
              v = new Truck;
          else
              v = new MotorCycle;

            v->setMake(selectedList.at(1).data().toString());
            v->setModel(selectedList.at(2).data().toString());
            v->setYear(selectedList.at(3).data().toInt());
            v->setColor(selectedList.at(4).data().toString());
            v->setWheelDrive(selectedList.at(5).data().toInt());
            v->setMileage(selectedList.at(6).data().toInt());
            double fare = selectedList.at(7).data().toDouble();

          QObject::connect(this,SIGNAL(rentEvent(Vehicle*,double)),rentForm,SLOT(generateDescription(Vehicle*,double)));
          emit rentEvent(v,fare);
          rentForm->show();


        qDebug()<<index.data();
        }



}

void EmployeeInterface::on_EmployeeInterface_accepted()
{
    // populate the table while loading the table
}

void EmployeeInterface::on_btnReturn_clicked()
{
    returnForm = new Return_Form(this);
    returnForm->show();

}

void EmployeeInterface::on_btnAddVehicle_clicked()
{
    addNewVehicle = new AddNewVehicle(this);
    addNewVehicle->show();

}

void EmployeeInterface::on_backToAdminBtn_clicked()
{
    //casting the parent object to Qdialog to invoke the show method.
    static_cast<QDialog*>(this->parent())->show();
    this->close();
}



void EmployeeInterface::on_availableVehTable_clicked(const QModelIndex &index)
{
    //selecting the whole row when clicking on a cell
   ui->availableVehTable->selectRow(index.row());
}

