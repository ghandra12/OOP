#include <iostream>
#include <list>
using namespace std;
class Student;
list<Student> students;
template <class T>
T getMaximumGrade(list<T> elementsLists) {
int selectedelement = 0;
T student;
 for (auto i = elementsLists.begin(); i !=elementsLists.end(); i++)
  if (selectedelement < (*i).getGrade())
   {selectedelement = (*i).getGrade();
    student=(*i);}


return student;
}
class Student{
private:
    int grade;
public:
    Student(){}
    Student(int grade){
        this->grade=grade;
    }
    int getGrade(){
        return grade;
    }
};
void addStudent(Student student){
    students.push_back(student);
}
int main() {
 Student student1(1),student2(4),student3(8),student4(6);
 addStudent(student1);
 addStudent(student2);
 addStudent(student3);
 addStudent(student4);
 Student result;
 result=getMaximumGrade(students);
 cout<<"cea mai mare nota:\n"<<result.getGrade();
return 0;
}
