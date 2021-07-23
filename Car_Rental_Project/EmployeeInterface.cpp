#include "EmployeeInterface.h"
#include "ui_EmployeeInterface.h"
#include <QMessageBox>
#include<QFile>
#include<QTextStream>
#include<EmployeeAuthentication.h>
#include<QDir>
#include<QMenuBar>
#include<QFile>
#include <QList>
#include<QDebug>

EmployeeInterface::EmployeeInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeInterface)
{
    ui->setupUi(this);
    QMenuBar().addMenu("File");
    QMenuBar().addMenu("Edit");
    QMenuBar().addMenu("Settings");
    QMenuBar().addMenu("Help");

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
     if(!sourceFile.open(QIODevice::ReadOnly)){
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

             qDebug() << item->data();
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



void EmployeeInterface::on_btnEmplQuit_clicked()
{
    QMessageBox::StandardButton reply =  QMessageBox::warning(this,"Quit?","Are you sure you want to quit ?",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        this->close();
    }
}






void EmployeeInterface::on_btnOptions_clicked()
{
    //Vehicle v ;
  //  v.setMake("HONDA");
   // v.setModel("ACCORD");
   // v.setVin("2343454342");
  //  v.setYear(2020);

    //EmployeeInterface::write();
   // EmployeeInterface::read();
    // QString string= "test";
    //QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(
   //     (ui->table2->rowCount()+1)*(ui->table2->columnCount()+1)));
   // ui->table2->insertRow(ui->table2->rowCount());
   // ui->table2->setItem(ui->table2->rowCount(),1,newItem);
   // ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    //ui->tableWidget->setItem(ui->tableWidget->rowCount(),1,item);

   // QTableWidgetItem *item = new QTableWidgetItem("Honda");
    //ui->availableVTable->insertRow(1);
    //ui->availableVTable->setItem(1,1,item);
};
void EmployeeInterface::write(){

    EmployeeAuthentication ea1("test","test");
    //ea.setPassword("password");
    //ea.setUsername("username");
    QString path = QDir::currentPath()+QDir::separator()+"test.dat";
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        return;
    }
    QDataStream stream(&file);
    //QString username,password;
    stream << ea1.getUsername();
    stream << ea1.getPassword();
    file.close();
    //ui->lbltest->setText(path);
}
void EmployeeInterface::read(){
    QString path = QDir::currentPath()+QDir::separator()+"test.dat";
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }
    EmployeeAuthentication ea;
    QDataStream stream(&file);
    QString username,password;
    stream>>username;
    stream>>password;
    ea.setPassword(password);
    ea.setUsername(username);
    ui->lbltest->setText("password:" + ea.getPassword()+"username: " +ea.getUsername());
}

void EmployeeInterface::on_btnRent_2_clicked()
{
    //show the rent form
    rentForm  = new RentForm(this);
    rentForm->show();

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

void EmployeeInterface::on_tableWidget_cellClicked(int row, int column)
{

}

void EmployeeInterface::on_btnAddVehicle_clicked()
{
  addNewVehicle = new AddNewVehicle(this);
  addNewVehicle->show();

}
