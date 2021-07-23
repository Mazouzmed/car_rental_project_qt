#include "dataprovider.h"
#include <QDebug>
#include <QDate>

dataProvider::dataProvider()
{

}

 QStringList dataProvider::vehicleTypes() const
{
   QStringList types;
   types.append("Car");
   types.append("Truck");
   types.append("MotorCycle");
   return types;
}

QStringList dataProvider::carMakes() const
{
    QStringList makes;
    QVector<QString> carMakesArray={
        "Abarth",
        "Alfa Romeo",
        "Aston Martin",
        "Audi",
        "Bentley",
        "BMW",
        "Bugatti",
        "Cadillac",
        "Chevrolet",
        "Chrysler",
        "Citroën",
        "Dacia",
        "Daewoo",
        "Daihatsu",
        "Dodge",
        "Donkervoort",
        "DS",
        "Ferrari",
        "Fiat",
        "Fisker",
        "Ford",
        "Honda",
        "Hummer",
        "Hyundai",
        "Infiniti",
        "Iveco",
        "Jaguar",
        "Jeep",
        "Kia",
        "KTM",
        "Lada",
        "Lamborghini",
        "Lancia",
        "Land Rover",
        "Landwind",
        "Lexus",
        "Lotus",
        "Maserati",
        "Maybach",
        "Mazda",
        "McLaren",
        "Mercedes-Benz",
        "MG",
        "Mini",
        "Mitsubishi",
        "Morgan",
        "Nissan",
        "Opel",
        "Peugeot",
        "Porsche",
        "Renault",
        "Rolls-Royce",
        "Rover",
        "Saab",
        "Seat",
        "Skoda",
        "Smart",
        "SsangYong",
        "Subaru",
        "Suzuki",
        "Tesla",
        "Toyota",
        "Volkswagen",
        "Volvo"
      };


    return toList(carMakesArray);
}

QStringList dataProvider::truckMakes() const
{
    QStringList makes;
    QVector<QString> truckMakes={
        "Dodge",
        "Chevrolet",
        "Ram",
        "Toyota",
        "Jeep"
    };
    return toList(truckMakes);
}

QStringList dataProvider::motoMakes() const
{
    QVector<QString> makes = {
        "Harley_Davidson",
        "Aprillia",
        "Honda",
        "Kawasaki",
        "KTM",
        "Suzuki"
    };
    return toList(makes);
}

QStringList dataProvider::getModels(QString make) const
{
     QVector<QString> models;
    if(make == "Abarth"){
        models.clear();
        models = {"500","500c","123 Spider"};
    }
    if(make =="Alfa Romeo"){
        models.clear();
        models = {"4C Spider","Giulia","Stelvio"};
    }
    if(make =="Dodge"){
        models.clear();
        models = {"RAM 1500","RAM 2500","RAM 3500"};
    }
    if(make =="Harley_Davidson"){
        models.clear();
        models = {"48","72","Iron 1883"};
    }
    return models.toList();
}

QStringList dataProvider::getColors()const
{
    QVector<QString> colors = {"Black","Green","Yellow","White","Brown","Blue"};
    return toList(colors);
}

QStringList dataProvider::years() const
{
    QVector<QString> years={"2015","2016","2017","2018","2019","2020"};
    return years.toList();
}


QStringList dataProvider::toList(QVector<QString>& makes)const
{
    QStringList list;
    for (QString make : makes){
        list.append(make);
    }
    return list;
}
