#include <iostream>

using namespace std;
class Student{
private:
    string name;
    int grade;
    Student(int g){
    grade=g;
    }
public:
    Student(){
     Student(8);
    }
int getGrade(){
return grade;
}
};
int main()
{
 Student student1,student2;
 cout<<student1.getGrade();
}
//nu am gasit o solutie care sa seteze nota cu private constructor
