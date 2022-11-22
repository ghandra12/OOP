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
   Student MaxGrade(){
   Student maxGradeStudent("minimumGradeStudent",0);
   for(auto it=students.begin();it!=students.end();it++)
       if((*it).getGrade()>maxGradeStudent.getGrade()){
         maxGradeStudent=(*it);
       }
    return maxGradeStudent;
   }

};
int main()
{
   Student stud1("Andra",10),stud2("Mihai",8),stud3("Ana",5),stud4("David",9);
   StudentList students;
   students.addStudent(stud1);
   students.addStudent(stud2);
   students.addStudent(stud3);
   students.addStudent(stud4);
   cout<<"Lista cu studenti:\n";
   for(auto it=students.students.begin();it!=students.students.end();it++)
     cout<<(*it).getName()<<" "<<(*it).getGrade()<<endl;
   cout<<"Studentul cu nota maxima:\n";
   Student maxGradeStud=students.MaxGrade();
   cout<<maxGradeStud.getName();

    return 0;
}
