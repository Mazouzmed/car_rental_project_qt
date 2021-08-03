#ifndef ADDEMPLOYEE_H
#define ADDEMPLOYEE_H

#include <QDialog>

namespace Ui {
class AddEmployee;
}

class AddEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployee(QWidget *parent = nullptr);
    ~AddEmployee();

private slots:
    void on_closeBtn_clicked();

    void on_saveBtn_clicked();

private:
    Ui::AddEmployee *ui;
};

#endif // ADDEMPLOYEE_H
