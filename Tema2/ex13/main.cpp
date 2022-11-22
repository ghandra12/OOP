#include <iostream>
#include <list>
using namespace std;

struct Student {
    string name;
    int age;
};

int main()
{
    Student stud1, stud2, stud3;
    list<Student> students;
    cin >> stud1.name >> stud1.age;
    cin >> stud2.name >> stud2.age;
    cin >> stud3.name >> stud3.age;
    students.push_back(stud1);
    students.push_back(stud2);
    students.push_back(stud3);

    students.sort([](Student &stud1, Student &stud2) { return stud1.age > stud2.age;});

    for(auto it=students.begin(); it!=students.end(); it++){
        cout<<(*it).name<<" ";
    }
    return 0;
}
