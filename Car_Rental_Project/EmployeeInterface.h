#ifndef EMPLOYEEINTERFACE_H
#define EMPLOYEEINTERFACE_H

#include <QDialog>
#include"vehicle.h"
#include<EmployeeAuthentication.h>
#include"RentForm.h"
#include"Return_Form.h"
#include"addnewvehicle.h"
#include<QStringList>
#include <QStringListModel>
#include<QStandardItemModel>

namespace Ui {
class EmployeeInterface;
}

class EmployeeInterface : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeInterface(QWidget *parent = nullptr);
    ~EmployeeInterface();

private slots:

    void on_btnEmplQuit_clicked();

    void on_btnOptions_clicked();
    void write();
    void read();

    void on_btnRent_2_clicked();

    void on_EmployeeInterface_accepted();

    void on_btnReturn_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_btnAddVehicle_clicked();

private:
    Ui::EmployeeInterface *ui;
    RentForm *rentForm;
    Return_Form *returnForm;
    AddNewVehicle *addNewVehicle;
    QStandardItemModel *model;
};

#endif // EMPLOYEEINTERFACE_H
