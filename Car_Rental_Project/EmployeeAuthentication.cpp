#include "EmployeeAuthentication.h"
#include <QDebug>

EmployeeAuthentication::EmployeeAuthentication():mUsername(""),mPassword(""){}
EmployeeAuthentication::EmployeeAuthentication(QString username,QString password){
    setUsername(username);
    setPassword(password);
}
void EmployeeAuthentication::setUsername(QString username){
    mUsername = username;
}
void EmployeeAuthentication::setPassword(QString password){
    mPassword = password;
}

bool EmployeeAuthentication::authenticate(EmployeeAuthentication &employee)
{
    QFile file(":/res/utils/auth.dat");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    EmployeeAuthentication emp ;
    QString username,password;
    in >> username >> password;
    emp.setUsername(username);
    emp.setPassword(password);
    //qDebug()<<username << " " << password;
    if(employee.equals(emp)){
        return true;
    }
    else{
        return false;
    }
}

bool EmployeeAuthentication::authenticate(QString &&username, QString &&password)
{
    EmployeeAuthentication emp;
    emp.setUsername(username);
    emp.setPassword(password);
    //using the standard authentication method
    return EmployeeAuthentication::authenticate(emp);
}

bool EmployeeAuthentication::authenticate(QString username, QString password)
{
    EmployeeAuthentication emp;
    emp.setUsername(username);
    emp.setPassword(password);
    return EmployeeAuthentication::authenticate(emp);
}

bool EmployeeAuthentication::registration(EmployeeAuthentication &employee)
{
    QFile file(":/res/utils/auth.dat");
   if(file.open(QIODevice::WriteOnly)){
    QTextStream out(&file);
    out << employee.getUsername();
    out << employee.getPassword();

    qDebug() <<employee.getUsername()<<employee.getPassword();
    return true;
   }
   else
       return false;
}

/*
 * method for teting the equality between 2 authentications
 * it will be usefule when comparing the login info with the info on file
 */
bool EmployeeAuthentication::equals(EmployeeAuthentication &other)
{
    return (mUsername == other.mUsername && mPassword == other.mPassword);
}
QString EmployeeAuthentication::getUsername(){
    return mUsername;
}
QString EmployeeAuthentication::getPassword(){
    return mPassword;
}

