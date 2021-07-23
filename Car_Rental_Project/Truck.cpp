#include "Truck.h"

Truck::Truck()
{

}
void Truck::setBedSize(int bedSize){
    mBedSize = bedSize;
}
void Truck::setHasCamperShell(bool hasCamperShell){
    mHasCamperShell = hasCamperShell;
}
void Truck::setTowPower(int towPower){
    mTowPower = towPower;
}
int Truck::getBedSize(){
    return mBedSize;
}
bool Truck::getHasCamperShell(){
    return mHasCamperShell;
}
int Truck::getTowPower(){
    return mTowPower;
}
QString Truck::toString(){
    return "" ;
}
