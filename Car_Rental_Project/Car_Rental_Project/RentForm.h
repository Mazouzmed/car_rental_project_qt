#ifndef RENTFORM_H
#define RENTFORM_H

#include <QDialog>
#include<QDate>
#include<QTime>
#include"vehicle.h"
#include<QStandardItemModel>
#include<QStandardItem>
#include "dataprovider.h"

//declaring the insurance rate as a constant to be used in the class
#define INSURANCE_RATE 20

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



    void on_dateTo_userDateChanged(const QDate &date);

    void on_calculateFare_clicked();

    void on_saveBtn_clicked();

private:
    Ui::RentForm *ui;
    Vehicle *v;
    QStandardItemModel *model;
    dataProvider* data;

};

#endif // RENTFORM_H
