#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include <QDialog>
#include <AddEmployee.h>

namespace Ui {
class AdminInterface;
}

class AdminInterface : public QDialog
{
    Q_OBJECT

public:
    explicit AdminInterface(QWidget *parent = nullptr);
    ~AdminInterface();

private slots:
    void on_btnViewEmployees_clicked();

private:
    Ui::AdminInterface *ui;
    AddEmployee *addEmployee;
};

#endif // ADMININTERFACE_H
