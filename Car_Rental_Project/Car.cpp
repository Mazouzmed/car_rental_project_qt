
#include"Car.h"
Car::Car(){}
void Car::setNumberOfDoors(int numberOfDoors){
    mNumberOfDoor = numberOfDoors;
}
void Car::setTrunckSize(double trunckSize){
    mTrunckSize = trunckSize;
}
void Car::setHasSunRoof(bool hasSunRoof){
    mHasSunRoof = hasSunRoof;
}
void Car::setBodyType(QString bodyType){
    mBodyType = bodyType;
}
void Car::setOptions(QString options){
    mOptions = options;
}
void Car::setEngineType(QString engineType){
    mEngineType = engineType;
}
int Car::getNumberOfDoors(){
    return mNumberOfDoor;
}
double Car::getTrunckSize(){
    return mTrunckSize;
}
bool Car::getHasSunRoof(){
    return mHasSunRoof;
}
QString Car::getBodyType(){
    return mBodyType;
}
QString Car::getOptions(){
    return mOptions;
}
QString Car::getEngineType(){
    return mEngineType;
}
double Car::calculatePrice(){
    return (mBaseFare*getMileage());
}

double Car::calculateFare()
{
    return 0;
}


