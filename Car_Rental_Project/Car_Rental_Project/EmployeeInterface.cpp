#include "EmployeeInterface.h"
#include <QDir>
#include<QPixmap>

AdminInterface *adminWindow;





EmployeeInterface::EmployeeInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeInterface)
{
    ui->setupUi(this);
    setupTheBanner();
    setupIcons();
    setupTheModel();
    populateTable();
    ui->backToAdminBtn->hide();

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


       // qDebug()<<index.data();
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


void EmployeeInterface::on_backToLoginBtn_clicked()
{
    MainWindow *loginWindow;
    loginWindow = new MainWindow;
    loginWindow->show();
    this->close();
}
void EmployeeInterface::populateTable()
{
    QString path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project/Available_Cars.txt";
    QFile sourceFile(path);
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
void EmployeeInterface::setupIcons()
{
    QString path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project//icons/refreshIcon.png";
    QPixmap pixmap(path);
    QIcon ButtonIcon(pixmap);
    ui->refreshBtn->setIcon(ButtonIcon);
    ui->refreshBtn->setIconSize(pixmap.rect().size()/5);
    path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project//icons/addIcon.png";
    pixmap = path;
    ButtonIcon = pixmap;
    ui->btnAddVehicle->setIcon(ButtonIcon);
    ui->btnAddVehicle->setIconSize(pixmap.rect().size()/3);
    path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project//icons/addUser.png";
    pixmap = path;
    ButtonIcon = pixmap;
    ui->btnAddCustomer->setIcon(ButtonIcon);
    ui->btnAddCustomer->setIconSize(pixmap.rect().size()/3);
    path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project//icons/rentIcon.png";
    pixmap = path;
    ButtonIcon = pixmap;
    ui->btnRent_2->setIcon(ButtonIcon);
    ui->btnRent_2->setIconSize(pixmap.rect().size()/3);
    path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project//icons/printIcon.png";
    pixmap = path;
    ButtonIcon = pixmap;
    ui->printBtn->setIcon(ButtonIcon);
    ui->printBtn->setIconSize(pixmap.rect().size()/5);
    path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project//icons/returnIcon.png";
    pixmap = path;
    ButtonIcon = pixmap;
    ui->btnReturn->setIcon(ButtonIcon);
    ui->btnReturn->setIconSize(pixmap.rect().size()/3);
    path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project//icons/optionsIcon.png";
    pixmap = path;
    ButtonIcon = pixmap;
    ui->btnOptions->setIcon(ButtonIcon);
    ui->btnOptions->setIconSize(pixmap.rect().size()/3);
    path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project//icons/logoutIcon.png";
    pixmap = path;
    ButtonIcon = pixmap;
    ui->backToLoginBtn->setIcon(ButtonIcon);
    ui->backToLoginBtn->setIconSize(pixmap.rect().size()/3);
    path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project//icons/quitIcon.png";
    pixmap = path;
    ButtonIcon = pixmap;
    ui->btnEmplQuit->setIcon(ButtonIcon);
    ui->btnEmplQuit->setIconSize(pixmap.rect().size()/3.5);
    path = "C:/Users/zouma/OneDrive/Bureau/Car_Rental_Project//icons/updateIcon.png";
    pixmap = path;
    ButtonIcon = pixmap;
    ui->updateBtn->setIcon(ButtonIcon);
    ui->updateBtn->setIconSize(pixmap.rect().size()/5);
    qDebug()<<QDir().absolutePath();
}

void EmployeeInterface::setupTheBanner()
{
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
}
void EmployeeInterface::setupTheModel()
{
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
}


void EmployeeInterface::on_refreshBtn_clicked()
{
    populateTable();
}


void EmployeeInterface::on_printBtn_clicked()
{
    Printer printer ;
    QTextDocument document ;
    QPrinter print;
    QPrintDialog *dialog = new QPrintDialog(&print,this);
    if(dialog->exec() == QDialog::Accepted) {

        document.setHtml(printer.printModel(model));
        document.print(&print);
}
}


void EmployeeInterface::on_updateBtn_clicked()
{
    data = new dataProvider;
    if(!data->writeModelToFile(model))
        QMessageBox::warning(this,"Error!","Could not open the file for writing!");
    else
        QMessageBox::information(this,"Success","Vehicle updated successfully!");
}


void EmployeeInterface::on_viewRentedBtn_clicked()
{
    transactions = new TransactionDisplay(this);
    this->hide();
    transactions->show();
}

