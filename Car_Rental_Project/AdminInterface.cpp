#include "AdminInterface.h"
#include "ui_AdminInterface.h"
#include <QPixmap>


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
    addEmployee = new AddEmployee;
    addEmployee->show();
}

