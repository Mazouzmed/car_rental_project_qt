#ifndef ADDNEWVEHICLE_H
#define ADDNEWVEHICLE_H

#include <QDialog>
#include "dataprovider.h"

namespace Ui {
class AddNewVehicle;
}

class AddNewVehicle : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewVehicle(QWidget *parent = nullptr);
    ~AddNewVehicle();

private slots:
    void on_typeCombo_currentIndexChanged(int index);

    void on_makeCombo_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_addBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::AddNewVehicle *ui;
    dataProvider *data;
};

#endif // ADDNEWVEHICLE_H
