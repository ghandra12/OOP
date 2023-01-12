#include <iostream>
#include <list>
#include <string>
using namespace std;
class Driver;
class RaceDriver;
list<Driver>drivers;
list<RaceDriver>race_drivers;
class Person{
private:
    string name;
    int age;

public:
    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
    string getName(){
        return name;
    }


};
class Driver:public Person{
private:
    string car_category;
public:
    Driver(string name,int age):Person(name,age){
    }
    string getCarCategory(){
        return car_category;
    }
};
class RaceDriver:public Person{
private:
    int wins;
public:
    RaceDriver(string name,int age,int wins):Person(name,age){
      this->wins=wins;
    }
    int getWins(){
        return wins;
    }
};
void addDriver(Driver driver){
    drivers.push_back(driver);
}
void DisplayDrivers(){
   for(auto it=drivers.begin();it!=drivers.end();it++)
       cout<<(*it).getName()<<endl;
}
void RemoveDriver(Driver drv){

    drivers.remove_if([&drv](Driver &driver){
                       return drv.getName()==driver.getName();
                      }
                      );

}
void addRaceDriver(RaceDriver driver){
    race_drivers.push_back(driver);
}
void DisplayRaceDrivers(){
   for(auto it=race_drivers.begin();it!=race_drivers.end();it++)
       cout<<(*it).getName()<<" has "<<(*it).getWins()<<" wins"<<endl;
}
void RemoveRaceDriver(RaceDriver drv){

    race_drivers.remove_if([&drv](RaceDriver &driver){
                       return drv.getName()==driver.getName();
                      }
                      );

}
int main()
{

    Driver driver1("Andra",20);
    Driver driver2("Maria",18);
    cout<<"\nList of drivers:\n";
    addDriver(driver1);
    addDriver(driver2);
    DisplayDrivers();
    RemoveDriver(driver2);
    cout<<"\nList after we remove a driver:\n";
    DisplayDrivers();
    cout<<endl;
    RaceDriver drv1("Alin",30,3),drv2("Sara",27,5),drv3("Mihaela",31,0);
    addRaceDriver(drv1);
    addRaceDriver(drv2);
    addRaceDriver(drv3);
    DisplayRaceDrivers();
    RemoveRaceDriver(drv3);
    cout<<"\nList after we remove a race driver:\n";
    DisplayRaceDrivers();
    return 0;
}
