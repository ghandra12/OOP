#include <iostream>
#include <list>
using namespace std;
class Student {

private:
    string name;
    int grade;

public:
    Student(string name, int grade){
    this->name=name;

    this->grade=grade;
    }
    string getName(){
        return name;
    }

    int getGrade(){
        return grade;
    }

    void setGrade(int value){
        grade=value;
    }


};
class StudentList{
 public:
    list<Student> students;

    void addStudent(Student newStud){
        students.push_back(newStud);
    }
   Student First(){
   Student StudentNegasit("nimeni",0);
   for(auto it=students.begin();it!=students.end();it++)
       if((*it).getGrade()==5){
          return (*it);
       }

   return StudentNegasit;
   }

};
int main()
{
   Student stud1("Andra",10),stud2("Mihai",5),stud3("Ana",5),stud4("David",9);
   StudentList students;
   students.addStudent(stud1);
   students.addStudent(stud2);
   students.addStudent(stud3);
   students.addStudent(stud4);
   cout<<"Lista cu studenti:\n";
   for(auto it=students.students.begin();it!=students.students.end();it++)
     cout<<(*it).getName()<<" "<<(*it).getGrade()<<endl;
   cout<<"Primul student cu nota 5:\n";
   Student FirstStud=students.First();
   cout<<FirstStud.getName();

    return 0;
}
