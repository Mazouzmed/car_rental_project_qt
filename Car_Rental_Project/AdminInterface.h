#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include <QDialog>
#include "AddEmployee.h"
#include "vehicleinventoryform.h"
#include "EmployeeInterface.h"

namespace Ui {
class AdminInterface;
}

class AdminInterface : public QDialog
{
    Q_OBJECT

public:
    explicit AdminInterface(QWidget *parent = nullptr);
    ~AdminInterface();
signals:
    void openedFromAdmin();

private slots:
    void on_btnViewEmployees_clicked();

    void on_btnViewStock_clicked();

    void on_btnOpenEmployeeInterface_clicked();

    void on_btnQuit_clicked();

private:
    Ui::AdminInterface *ui;
    AddEmployee *addEmployee;
    VehicleInventoryForm *vehicleInventoryForm;
};

#endif // ADMININTERFACE_H
