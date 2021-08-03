#ifndef EMPLOYEEINTERFACE_H
#define EMPLOYEEINTERFACE_H

#include <QDialog>
#include"vehicle.h"
#include<EmployeeAuthentication.h>
#include"Return_Form.h"
#include"addnewvehicle.h"
#include<QStringList>
#include <QStringListModel>
#include<QStandardItemModel>
#include "ui_EmployeeInterface.h"
#include "RentForm.h"
#include <QMessageBox>
#include<QFile>
#include<QTextStream>
#include<EmployeeAuthentication.h>
#include<QFile>
#include<QDebug>
#include"Car.h"
#include"AdminInterface.h"
#include"Truck.h"
#include"MotorCycle.h"

namespace Ui {
class EmployeeInterface;
}

class EmployeeInterface : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeInterface(QWidget *parent = nullptr);
    ~EmployeeInterface();
signals:
    Vehicle rentEvent(Vehicle*,double fare);
public slots:
    void makeAdminButtonVisible();

private slots:

    void on_btnEmplQuit_clicked();

    void on_btnOptions_clicked();

    void on_btnRent_2_clicked();

    void on_EmployeeInterface_accepted();

    void on_btnReturn_clicked();

    void on_btnAddVehicle_clicked();

    void on_backToAdminBtn_clicked();

    void on_availableVehTable_clicked(const QModelIndex &index);

protected:
    //void setAdminWindow(AdminInterface *);

private:
    Ui::EmployeeInterface *ui;
    RentForm *rentForm;
    Return_Form *returnForm;
    AddNewVehicle *addNewVehicle;
    QStandardItemModel *model;


};

#endif // EMPLOYEEINTERFACE_H
