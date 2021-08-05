#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person:public QObject
{
    /*
     * Using QOBJECT Macro to support signal and slots for
     * all children classes
     */
    Q_OBJECT

public:
    Person();
    void setName(QString name);
    void setAddress(QString address);
    void setDateOfBirth(QString dob);
    QString getName();
    QString getAddress();
    QString getDateOfBirth();
    int getAge();
    QString toString();
private:
    QString mName,mAddress,mDob;
};

#endif // PERSON_H
