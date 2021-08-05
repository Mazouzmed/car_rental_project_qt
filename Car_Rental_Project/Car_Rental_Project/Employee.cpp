#include "Employee.h"

Employee::Employee()
{

}

void Employee::setEmployeeId(int newEmployeeId)
{
    mEmployeeId = newEmployeeId;
}

int Employee::employeeId() const
{
    return mEmployeeId;
}

const QString &Employee::hiringDate() const
{
    return mHiringDate;
}

void Employee::setHiringDate(const QString &newHiringDate)
{
    mHiringDate = newHiringDate;
}

const QString &Employee::jobDescription() const
{
    return mJobDescription;
}

void Employee::setJobDescription(const QString &newJobDescription)
{
    mJobDescription = newJobDescription;
}

double Employee::payRate() const
{
    return mPayRate;
}

void Employee::setPayRate(double newPayRate)
{
    mPayRate = newPayRate;
}

const QString &Employee::getFirstName() const
{
    return firstName;
}

void Employee::setFirstName(const QString &newFirstName)
{
    firstName = newFirstName;
}

const QString &Employee::getLastName() const
{
    return lastName;
}

void Employee::setLastName(const QString &newLastName)
{
    lastName = newLastName;
}
