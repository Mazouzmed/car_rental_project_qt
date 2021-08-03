#ifndef RENTFORM_H
#define RENTFORM_H

#include <QDialog>
#include<QDate>
#include<QTime>
#include"vehicle.h"

namespace Ui {
class RentForm;
}

class RentForm : public QDialog
{
    Q_OBJECT

public:
    explicit RentForm(QWidget *parent = nullptr);
    ~RentForm();
signals:
    void dateChanged(QDate&);
public slots:
    void generateDescription(Vehicle*,double fare);
    //void calculateFare(QDate&);
private slots:
    void on_changeBtn_clicked();
    void on_dateTo_userDateChanged( QDate &date);
    void calculateFare(QDate&);


private:
    Ui::RentForm *ui;
    Vehicle *v;

};

#endif // RENTFORM_H
