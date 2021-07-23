#include "EmployeeAuthentication.h"

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
QString EmployeeAuthentication::getUsername(){
    return mUsername;
}
QString EmployeeAuthentication::getPassword(){
    return mPassword;
}

