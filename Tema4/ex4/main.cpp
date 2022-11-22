#include <iostream>
#include <string>
using namespace std;

class Driver {
public:
    string name;
    Driver() {}
    Driver(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
};

class Car {
public:
    int age;
    Driver driver;
    Car(int age, string driverName) {
        this->age = age;
        this->driver = Driver(driverName); // use the constructor Driver(name)
    }
    //NOUL CONSTRUCTOR:
    Car(int age,Driver driver){

    this->age=age;
    this->driver=driver;
    }
    int getAge() {
        return this->age;
    }
    Driver getDriver() {
        return this->driver;
    }

};
void interchangeVehicleDrivers(Car &car1,Car &car2){
    Driver driver3;
    driver3=car1.driver;
    car1.driver=car2.driver;
    car2.driver=driver3;
}
int  main() {
    //Car *car = new Car(23, "Ionel");
    Driver driver1("Andra"),driver2("Ana");
    Car car1(20,driver1),car2(23,driver2);
    interchangeVehicleDrivers(car1,car2);
    cout<<"Soferul   masinii 1 este:"<<car1.getDriver().getName()<<endl;
    cout<<"Soferul   masinii 2 este:"<<car2.getDriver().getName()<<endl;

}
