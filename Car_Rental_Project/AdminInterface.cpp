#include "AdminInterface.h"
#include "ui_AdminInterface.h"
#include <QPixmap>


EmployeeInterface *empWindow;
AdminInterface::AdminInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminInterface)
{
    ui->setupUi(this);
    QPixmap pix(":/res/img/background1.jpg");
    int w = ui->lblBanner->width(); // extracting the width of the label widget
    int h = ui->lblBanner->height();// extracting the height of the label widget
    // calling setPixmap with the parameters we got in order to put a scaled image in the label
    ui->lblBanner->setPixmap(pix.scaled(w,h));
}

AdminInterface::~AdminInterface()
{
    delete ui;
}

void AdminInterface::on_btnViewEmployees_clicked()
{
    addEmployee = new AddEmployee(this);
    addEmployee->show();
}


void AdminInterface::on_btnViewStock_clicked()
{
    vehicleInventoryForm = new VehicleInventoryForm(this);
    vehicleInventoryForm->show();

}


void AdminInterface::on_btnOpenEmployeeInterface_clicked()
{
    empWindow = new EmployeeInterface(this);
    QObject::connect(this, SIGNAL(openedFromAdmin()), empWindow, SLOT(makeAdminButtonVisible()));
    this->hide();
    empWindow->show();
    emit openedFromAdmin();
}


void AdminInterface::on_btnQuit_clicked()
{
    int decision = QMessageBox::warning(this,"Quit?","Are you sure you want to close admin interface?",QMessageBox::Yes|QMessageBox::No);
    if(decision ==QMessageBox::Yes)
        this->close();
}

