#include <iostream>
#include <string>
#include <list>
using namespace std;
class Group{
private:
    int Group_Number;
public:
    Group(int Group_Number){
        this->Group_Number=Group_Number;
    }
    class Student{
    private:
        string name;
        int age;
    public:


        Student(string name,int grade){
            this->name=name;
            this->age=age;
        }
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }

    };
    list<Student> Students;
   int getGroup_Number(){
        return Group_Number;
   }
   void addStudent(Student student){
          Students.push_back(student);
        }
   void DisplayStudents(){
       cout<<"Students from group "<<getGroup_Number()<<" :\n";
       for(auto it=Students.begin();it!=Students.end();it++)
           cout<<(*it).getName()<<endl;
   }

};
int main()
{
 Group group1(1),group2(2);
 Group::Student std1("Alina",20),std2("Andrei",24),std3("Miruna",21),std4("Daria",23);
 group1.addStudent(std1);
 group1.addStudent(std3);
 cout<<endl<<"Prima grupa:\n";
 group1.DisplayStudents();
 group2.addStudent(std2);
 group2.addStudent(std4);
 cout<<endl<<"A doua grupa:\n";
 group2.DisplayStudents();
}
