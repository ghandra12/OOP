#include <iostream>
#include <list>
#include <string>
using namespace std;

class Driver{
private:
    string name;
    int age;
public:
    Driver(string name,int age){
        this->name=name;
        this->age=age;
    }
    string getName(){
        return name;
    }

};
class Car{
private:
    string model;
    int year;
public:
    Car(string model,int year){
        this->model=model;
        this->year=year;
    }
    int getYear(){
        return year;
    }
    string getModel(){
        return model;
    }

};
class Group{
    public:
    class CarDriver{
    public:
        Car car;
        Driver driver;
        CarDriver(Car car,Driver driver):car(car),driver(driver){

        }

    };
    list<CarDriver> listOfCarDrivers;
    void addCarDriver(CarDriver car_driver){
        listOfCarDrivers.push_back(car_driver);

    }
    void DisplayList(){
        cout<<"We have "<<listOfCarDrivers.size()<<" pairs\n";
       for(auto it=listOfCarDrivers.begin();it!=listOfCarDrivers.end();it++)
          cout<<(*it).car.getModel()<<" has driver "<<(*it).driver.getName()<<endl;

    }
    void RemoveElement(Driver drv){
            listOfCarDrivers.remove_if([&drv](CarDriver &car_driver){
                                          return car_driver.driver.getName()==drv.getName();
                                       }
                                      );
    }

};
int main()
{
  Car car1("BMW",2001),car2("Audi",2005),car3("Volvo",2010);
  Driver driver1("Alex",18),driver2("Raul",20),driver3("Daria",23);
  Group::CarDriver car_driver1(car1,driver1),car_driver2(car2,driver2),car_driver3(car3,driver3);
  Group group1;
  group1.addCarDriver(car_driver1);
  group1.addCarDriver(car_driver2);
  group1.addCarDriver(car_driver3);

  group1.DisplayList();
  group1.RemoveElement(driver3);
  cout<<endl;
  cout<<"Lista dupa stergere:";
  cout<<endl;
  group1.DisplayList();
  ///da, este flexibil deoarece putem sterge si adauga oricand elemente noi.

    return 0;
}
