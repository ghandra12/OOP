#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
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

    int getAge(){
        return age;
    }

    void setAge(int value){
        age=value;
    }

    // suprascriem operatorul == pentru a putea compara doua persoane. functia remove din STL are nevoie de acest operator
    bool operator == (const Person& p) const { return name == p.name; }

};
class GroupFriends{
private:
    string group_name;

public:
    list<Person> friends;

    string getGroupName(){
        return group_name;
    }

    void setGroupName(string group_name){
        this->group_name=group_name;
    }

    void addFriend(Person newFriend){
        friends.push_back(newFriend);
    }

    void deleteFriend(Person person){
        friends.remove(person);
    }

    void update(Person person,int newAge){
        for(auto it=friends.begin();it!=friends.end();it++){
          if((*it).getName()==person.getName())
              (*it).setAge(newAge);
        }
    }
};

int main()
{
  Person person1("Andra",20),person2("Maria",19),person3("Ana",21),person4("Andrei",24);
  GroupFriends group1,group2;
   //primul grup
  group1.setGroupName("Grupul 1");
  group1.addFriend(person1);
  group1.addFriend(person4);
  cout<<group1.getGroupName()<<endl;
  for(auto it=group1.friends.begin();it!=group1.friends.end();it++)
           cout<<(*it).getName()<<" ";
 //al doilea grup

   group2.setGroupName("Grupul 2");
   group2.addFriend(person2);
   group2.addFriend(person3);

   cout<<endl<<group2.getGroupName()<<endl;
   for(auto it=group2.friends.begin();it!=group2.friends.end();it++)
      cout<<(*it).getName()<<" ";

   group2.update(person2,20);
    cout<<"\nGrupul 2 dupa ce am schimbat varsta Mariei:";
    for(auto it=group2.friends.begin();it!=group2.friends.end();it++)
      cout<<endl<<(*it).getName()<<" "<<(*it).getAge();
    cout<<endl;
    group1.deleteFriend(person1);
     for(auto it=group1.friends.begin();it!=group1.friends.end();it++)
           cout<<(*it).getName()<<" ";
    return 0;
}
