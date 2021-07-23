#include "MainWindow.h"
#include "ui_MainWindow.h"
#include<QPixmap>
#include<QMessageBox>
#include<EmployeeAuthentication.h>
#include<QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Using Qpixmap in order to include an image in the label
    QPixmap pix(":/res/img/loginImg.png");
    int w = ui->lblLoginIcon->width(); // extracting the width of the label widget
    int h = ui->lblLoginIcon->height();// extracting the height of the label widget
    // calling setPixmap with the parameters we got in order to put a scaled image in the label
    ui->lblLoginIcon->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}



//when login button is clicked
void MainWindow::on_btnSignIn_clicked()
{
    QString userName = ui->txtUsername->text();
    QString password = ui->txtPassword->text();
    if(userName == "test" && password == "test"){
            this->close();
            employeeInterface = new EmployeeInterface(this);
            employeeInterface->show();
    }
    else if(userName == "admin" && password=="admin"){
        this->close();
        adminInterface = new AdminInterface(this);
        adminInterface->show();
    }
    else{
        QMessageBox::critical(this,"Authentication Error","Username or password incorrect! Please try again");
    }


}

void MainWindow::on_btnClose_clicked()
{
    this->close();
}
