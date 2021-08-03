QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddEmployee.cpp \
    AdminInterface.cpp \
    Car.cpp \
    Customer.cpp \
    Employee.cpp \
    EmployeeAuthentication.cpp \
    EmployeeInterface.cpp \
    MainWindow.cpp \
    MotorCycle.cpp \
    Person.cpp \
    RentForm.cpp \
    Return_Form.cpp \
    Truck.cpp \
    addnewvehicle.cpp \
    dataprovider.cpp \
    main.cpp \
    printer.cpp \
    vehicle.cpp \
    vehicleinventoryform.cpp

HEADERS += \
    AddEmployee.h \
    AdminInterface.h \
    Car.h \
    Customer.h \
    Employee.h \
    EmployeeAuthentication.h \
    EmployeeInterface.h \
    MainWindow.h \
    MotorCycle.h \
    Person.h \
    RentForm.h \
    Return_Form.h \
    Truck.h \
    addnewvehicle.h \
    dataprovider.h \
    printer.h \
    vehicle.h \
    vehicleinventoryform.h

FORMS += \
    AddEmployee.ui \
    AdminInterface.ui \
    EmployeeInterface.ui \
    MainWindow.ui \
    RentForm.ui \
    Return_Form.ui \
    addnewvehicle.ui \
    vehicleinventoryform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

DISTFILES += \
    img/car_logo.jpg
