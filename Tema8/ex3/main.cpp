#include <iostream>
#include <list>
using namespace std;
class Person;
class Car;
list<Person> listOfPersons;
list<Car> listOfCars;
template <class T>
float AverageAge(list<T> lista){
      int suma=0;
      for(auto it=lista.begin();it!=lista.end();it++)
      {
        suma+=(*it).getAge();
      }
      return (float)suma/lista.size();

}

class Person{
private:
    int age;
public:
    Person(int age){
         this->age=age;
    }
    int getAge(){
        return age;
    }

};
class Car{
private:
    int age;
public:
    Car(int age){
         this->age=age;
    }
    int getAge(){
        return age;
    }

};
void addPerson(Person person){
    listOfPersons.push_back(person);
}
void addCar(Car car){
    listOfCars.push_back(car);
}
int main()
{
    Person person1(20),person2(15),person3(35);
    addPerson(person1);
    addPerson(person2);
    addPerson(person3);
    Car car1(34),car2(40),car3(10);
    addCar(car1);
    addCar(car2);
    addCar(car3);
    float media_persons=AverageAge(listOfPersons);
    float media_cars=AverageAge(listOfCars);
    cout<<"\nMedia varstelor masinilor:\n"<<media_cars;
    cout<<"\nMedia varstelor persoanelor:\n"<<media_persons;
    return 0;
}
