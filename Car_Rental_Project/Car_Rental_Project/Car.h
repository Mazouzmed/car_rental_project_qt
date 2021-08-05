#ifndef CAR_H
#define CAR_H
#include<QString>
#include"vehicle.h"
#include<QObject>

class Car:public Vehicle
{
    Q_OBJECT
public:
    Car();
    virtual ~Car()=default;
    void setNumberOfDoors(int);
    void setTrunckSize(double);
    void setHasSunRoof(bool);
    void setBodyType(QString);
    void setOptions(QString);
    void setEngineType(QString);
    void setBaseFare(double);
    int getNumberOfDoors();
    double getTrunckSize();
    bool getHasSunRoof();
    QString getBodyType();
    QString getOptions();
    QString getEngineType();
    double getBasFare();
    double calculatePrice();
    double  calculateFare() override ;
    QString toString() ;


private:
    int mNumberOfDoor;
    double mTrunckSize;
    bool mHasSunRoof;
    QString mBodyType;
    QString mOptions;
    QString mEngineType;
    double mBaseFare;

};

#endif // CAR_H
