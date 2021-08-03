#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"EmployeeInterface.h"
#include"AdminInterface.h"
#include "EmployeeAuthentication.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnSignIn_clicked();

    void on_btnClose_clicked();

private:
    Ui::MainWindow *ui;
    //creating a pointer to the employeeInterface Window
    EmployeeInterface *employeeInterface;
    AdminInterface *adminInterface;
};
#endif // MAINWINDOW_H
