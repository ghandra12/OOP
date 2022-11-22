#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Student{

private:
    string name;
    int grade;
public:
    Student(string s,int g){
    name=s;
    grade=g;
    }

    int getGrade(){
        return grade;
    }

    string getName(){
        return name;
    }
};
void ListStudentsMaxGrade(vector<Student> students){
 int maxim=0;
 for(auto it=students.begin();it!=students.end();it++)
    if((*it).getGrade()>maxim)
       maxim=(*it).getGrade();
 for(auto it=students.begin();it!=students.end();it++)
    if((*it).getGrade()==maxim)
      cout<<(*it).getName()<<" "<<(*it).getGrade()<<endl;

}
int main()
{  vector<Student> students;
   Student stud1("Andra", 10), stud2("Ana",2),stud3("Maria",5),stud4("Denis",10),stud5("Ramona",1);
   students.push_back(stud1);
   students.push_back(stud2);
   students.push_back(stud3);
   students.push_back(stud4);
   students.push_back(stud5);
   ListStudentsMaxGrade(students);

   return 0;
}
