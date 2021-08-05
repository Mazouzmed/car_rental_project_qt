#ifndef EMPLOYEEAUTHENTICATION_H
#define EMPLOYEEAUTHENTICATION_H
#include<QString>
#include<QObject>
#include<QDataStream>
#include<QFile>

class EmployeeAuthentication:public QObject
{
Q_OBJECT
public:
    EmployeeAuthentication();
    EmployeeAuthentication(QString,QString);
    void setUsername(QString);
    void setPassword(QString);
    static bool authenticate(EmployeeAuthentication &employee);
    static bool authenticate(QString&&, QString&&);
    static bool authenticate(QString,QString);
    //registring a user using the employeeAuthentication class
    static bool registration(EmployeeAuthentication &employee);
    //overloading the method to support string literals as well
    static bool registration(QString &&username, QString &&password);
    //overloading the method to accept Qstring arguments.
    static bool registration(QString userName, QString password);
    QString getUsername();
    QString getPassword();

private:
    QString mUsername;
    QString mPassword;
    bool equals(EmployeeAuthentication &other);
};

#endif // EMPLOYEEAUTHENTICATION_H
