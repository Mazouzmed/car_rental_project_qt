#ifndef TRUCK_H
#define TRUCK_H


#include"Car.h"

class Truck:public Car
{

public:
    Truck();
    virtual ~Truck()=default;
    void setBedSize(int);
    void setHasCamperShell(bool);
    void setTowPower(int);
    int getBedSize();
    bool getHasCamperShell();
    int getTowPower();
    QString toString();
private:
    int mBedSize;
    bool mHasCamperShell;
    int mTowPower;
};

#endif // TRUCK_H
