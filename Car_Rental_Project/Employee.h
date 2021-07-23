#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include"Person.h"


class Employee:public Person
{
public:
    Employee();
    void setEmployeeId(int newEmployeeId);

    int employeeId() const;

    const QString &hiringDate() const;
    void setHiringDate(const QString &newHiringDate);

    const QString &jobDescription() const;
    void setJobDescription(const QString &newJobDescription);

    double payRate() const;
    void setPayRate(double newPayRate);

    const QString &getFirstName() const;
    void setFirstName(const QString &newFirstName);

    const QString &getLastName() const;
    void setLastName(const QString &newLastName);

private:
    int mEmployeeId;
    QString firstName,lastName;
    QString mHiringDate;
    QString mJobDescription;
    double mPayRate;
};

#endif // EMPLOYEE_H
