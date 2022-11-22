#include <iostream>
using namespace std;

class Student{
private:
    string name;
    int grade;
public:
    static int number_of_students;

    Student(){
     number_of_students++;
    }

    ~Student(){
     number_of_students--;
    }
};
int Student::number_of_students=0;

int main()
{
   Student stud1,stud2,stud3,stud4;
   cout<<"Numarul de studenti: "<< Student::number_of_students<<endl;

   Student stud5;
   cout<<"Numarul de studenti dupa inca o adaugare: "<< Student::number_of_students<<endl;

   return 0;
}
