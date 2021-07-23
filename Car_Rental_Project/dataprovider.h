#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QObject>
#include <QStringList>
#include"vehicle.h"
/*
 * This class provides all the vehicle information
 * needed by other classes in order to centrlize data
 * for ease of modification.
 */
class dataProvider:public QObject
{
    Q_OBJECT
public:
    dataProvider();
    /*
     * return list of vehicle types
     */
    QStringList vehicleTypes () const;
    /*
     * return list of car makes
     */
    QStringList carMakes() const;
    /*
     * return list of truck makes
     */
    QStringList truckMakes()const;
    /*
     * return list of motorCycle makes
     */
    QStringList motoMakes()const;
    /*
     * return list of models depending on each vehicle
     */
    QStringList getModels(QString make)const;
    /*
     * return list of colors
     */
    QStringList getColors()const;
    /*
     * return list of years starting from 2000
     */
    QStringList years() const;
public slots:
    bool saveVehicle(Vehicle &v);
private:
    /*
     * method for converting the String arrays to lists
     */
    QStringList toList(QVector<QString>&) const;

};

#endif // DATAPROVIDER_H
