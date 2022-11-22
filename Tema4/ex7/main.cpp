#include <iostream>
#include <list>
using namespace std;

class Address{
private:
    string city;
    string street;
public:

    Address(string city,string street){
        this->city=city;
        this->street=street;
    }
    string getCity(){
        return city;
    }
    string getStreet(){
        return street;
    }

};

class Driver{
private:
    string name;
    int age;
public:
    Address address;
    Driver(string name,int age, Address a):address(a){
       this->name=name;
       this->age=age;
    }
     string getName(){
     return name;
     }
};
class Bus{
private:
        string model;
public:
        Driver driver;
        string getModel(){
           return model;
        }
        Bus(string model,Driver d): driver(d){
           this->model=model;
        }

};

class BusStation{
private:
       string name;
public:
       list<Bus> busses;
       BusStation(string name){
          this->name=name;
       }
       void addBus(Bus bus){
        busses.push_back(bus);

       }
       string getName(){
          return name;
       }
};


class Commuter{
private:
    string name;
    Address address;
public:
    int static noCommuters;

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }
    Address getAddress()
    {
        return address;
    }

    Commuter(Address a,string name = "UNKNOWN"): address(a)
    {
        this->name = name;
        noCommuters++;
    }

};

class Mosquito{
private:
    int mosquitonumber;
public:

    Mosquito(int mosquitonumber){
        this->mosquitonumber=mosquitonumber;
    }
    void Fly(){
        for(int i=1;i<=mosquitonumber;i++)
          cout<< "BZZZZZZZZ BZZZZZZZZZ"<<endl;
    }
    int getMosquitoNumber(){
        return mosquitonumber;
    }

};

class Engine{
protected:
    string type;
    int number;
public:
    void setType(string type)
    {
        this->type = type;
    }
    void setNumber(int number)
    {
        this->number = number;
    }

    string getType()
    {
        return type;
    }
    int getNumber()
    {
        return number;
    }

    Engine(string type = "UNKNOWN", int number = 0)
    {
        this->type = type;
        this->number = number;
    }
};

class Car:Engine{
private:
    string year;
    string model;
public:
    Driver driver;
    Car(string year,string model,Driver d, string type, int number): Engine(type, number), driver(d){
      this->year=year;
      this->model=model;
    }
    string getModel(){
       return model;
    }
    string getYear(){
       return year;
    }

};
int Commuter::noCommuters=0;
int main(){
Address address1("Craiova","Emil Garleanu"),address2("Brasov","O strada din Brasov"),address3("Iasi","O strada din Iasi");

Driver driver1("Andra",20,address1),driver2("Ana",35,address2),driver3("Andrei",24,address3);

Bus bus1("Solaris",driver1),bus2("SchoolBus",driver2),bus3("Mercedes",driver3);

Car car1("2010","BMW",driver1,"diesel",200), car2("2005","Skoda",driver2,"diesel",250), car3("2006","Volkswagen",driver3,"gasoline",250);

BusStation station("Statia 30");

station.addBus(bus1);
station.addBus(bus2);
station.addBus(bus3);

cout<<"In "<<station.getName()<<" Opresc urmatoarele autobuze:\n";
for(auto it=station.busses.begin();it!=station.busses.end();it++)
     cout<<(*it).getModel()<<" ";
cout<<endl;
cout<<"Modelul de masina "<<car1.getModel()<<" este condus de: "<<car1.driver.getName()<<endl;
cout<<"Modelul de masina "<<car2.getModel()<<" este condus de: "<<car2.driver.getName()<<endl;
cout<<car3.driver.getName()<<" nu are "<<car1.getModel()<<endl;
cout<<"Daca uiti geamul masinii coborat, poate intra un Mosquito. Sunetul specific este:\n";
Mosquito mosquito(2);
mosquito.Fly();
Address address4("Filiasi","Str.Filiasi"),address5("Isalnita","Str.Aurel Vlaicu");
Commuter commuter1(address4,"Denis"),commuter2(address5,"Vlad");
cout<<"Din pacate,acesti "<<Commuter::noCommuters<< " nu au masina:\n";
cout<<commuter1.getName()<<", "<<commuter2.getName();

return 0;

}
