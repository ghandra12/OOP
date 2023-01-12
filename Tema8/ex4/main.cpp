#include <iostream>
#include <list>
#include <typeinfo>
#include <variant>
using namespace std;
class Person{
private:
    int age;
    string name;
public:
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    void setName(string new_name){
        name=new_name;
    }
    void setAge(int new_age){
        age=new_age;
    }
    int getAge(){
       return age;
    }
    string getName(){
        return name;
    }

};
class Employee:public Person{
private:
    int experience;
public:
    Employee(string name,int age,int experience):Person(name,age){
        this->experience=experience;
    }

};
int main()
{
    Person person("Andrei", 14), person2("Mihnea", 16);
    Employee employee("Andra", 18, 2), employee2("Cristi", 20, 4);
    //list<Person> persons;
    list<variant<Person, Employee>> persons;
    persons.push_back(person);
    persons.push_back(person2);
    persons.push_back(employee);
    persons.push_back(employee2);
    for(auto it: persons){
        if(holds_alternative<Person>(it)){
            Person p = get<Person>(it);
            cout<<p.getName()<<" este de tipul Person"<<endl;
        } else if(holds_alternative<Employee>(it))
        {
            Employee e = get<Employee>(it);
            cout<<e.getName()<<" este de tipul Employee"<<endl;
        }
    }
    return 0;
}
