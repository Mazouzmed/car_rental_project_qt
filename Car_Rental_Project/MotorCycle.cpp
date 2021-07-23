#include "MotorCycle.h"

MotorCycle::MotorCycle()
{

}
void MotorCycle::setType(QString type){
    mType = type;
}
void MotorCycle::setNumberOfHelmets(int numberOfHelmets){
    mNUmberOfHelmets = numberOfHelmets;}
void MotorCycle::setRidingGear(QString ridingGear){
    mRidingGear = ridingGear;
}
void MotorCycle::setHasAuxiliaryLights(bool hasAuxiliaryLights){
    mHasAuxiliaryLights = hasAuxiliaryLights;
}
QString MotorCycle::getType(){
    return mType;
}
int MotorCycle::getNumberofHelmets(){
    return mNUmberOfHelmets;
}
QString MotorCycle::getRidingGear(){
    return mRidingGear;}
bool MotorCycle::getHasAuxiliaryLights(){
        return mHasAuxiliaryLights;}
QString MotorCycle::toString(){
    return "" ;
}
