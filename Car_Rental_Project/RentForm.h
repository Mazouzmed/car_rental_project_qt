#ifndef RENTFORM_H
#define RENTFORM_H

#include <QDialog>
#include<QDate>
#include<QTime>

namespace Ui {
class RentForm;
}

class RentForm : public QDialog
{
    Q_OBJECT

public:
    explicit RentForm(QWidget *parent = nullptr);
    ~RentForm();

private:
    Ui::RentForm *ui;
};

#endif // RENTFORM_H
