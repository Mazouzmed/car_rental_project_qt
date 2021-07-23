#include "Person.h"
#include <QDate>


Person::Person(){}
void Person::setName(QString name){
    mName = name;
}
void Person::setAddress(QString address){
  mAddress = address;  
}
void Person::setDateOfBirth(QString dob){
    mDob = dob;
}
QString Person::getName(){
    return mName;
}
QString Person::getAddress(){
    return mAddress;
}
QString Person::getDateOfBirth(){
    return mDob;
}

int Person::getAge()
{
    /*
     * calculate the age of the person
     */
    int age = 0 ;
    QDate dob = QDate::fromString(mDob,"mm/dd/yyyy");
    QDate today = QDate::currentDate();
    age = (dob.daysTo(today))/365;
    return age;
}
QString Person::toString(){
    return "name: " + mName;
}


