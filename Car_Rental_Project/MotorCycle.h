#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include"vehicle.h"

class MotorCycle : public Vehicle
{
Q_OBJECT
public:
    MotorCycle();
    virtual ~MotorCycle()=default;
    void setType(QString);
    void setNumberOfHelmets(int);
    void setRidingGear(QString);
    void setHasAuxiliaryLights(bool);
    QString getType();
    int getNumberofHelmets();
    QString getRidingGear();
    bool getHasAuxiliaryLights();
    QString toString();
    double calculateFare() override;
private:
    QString mType;
    int mNUmberOfHelmets;
    QString mRidingGear;
    bool mHasAuxiliaryLights;
};

#endif // MOTORCYCLE_H
