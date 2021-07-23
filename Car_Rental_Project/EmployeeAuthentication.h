#ifndef EMPLOYEEAUTHENTICATION_H
#define EMPLOYEEAUTHENTICATION_H
#include<QString>
#include<QObject>

class EmployeeAuthentication:public QObject
{
Q_OBJECT
public:
    EmployeeAuthentication();
    EmployeeAuthentication(QString,QString);
    void setUsername(QString);
    void setPassword(QString);
    QString getUsername();
    QString getPassword();

private:
    QString mUsername;
    QString mPassword;
};

#endif // EMPLOYEEAUTHENTICATION_H
