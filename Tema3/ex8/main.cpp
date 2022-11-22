#include <iostream>

using namespace std;
class Student{

public:
    static int nrStudents;
    string nume;
    int group;
    int grade;
    int age;
    Student *next;

    Student(string inputName, int inputAge, int inputGroup)
	{
		nrStudents++;
		nume = inputName;
		age = inputAge;
		group = inputGroup;
		grade = 0;
	}

    void addStudent(Student *student, Student *root){
        Student *aux=root;
        for(int i=0 ;i<nrStudents-2;i++)
            aux = aux->next;

        aux->next = student;
        aux->next->next = root; //we link the next element to the root so we can have all the elements linked to each other in order to access the entire list from any node
    }
};
int Student::nrStudents=0;

int main()
{
	Student* root, *student;
	root = new Student("Anca", 17, 3);
	student = root;
	student = student->next;

	student = new Student("Vasile", 16, 2);
	student->addStudent(student, root);
	student = student->next;

	student = new Student("Elena", 16, 1);
	student->addStudent(student, root);
	student = student->next;

	student = new Student("Cristian", 17, 2);
	student->addStudent(student, root);
	student = student->next;

	student = new Student("Monica", 16, 3);
	student->addStudent(student, root);
	student = student->next;

	student = root;
	for (int i = 0; i < Student::nrStudents; i++) //show the list
	{
		cout << "Name: " << student->nume;
		cout << "  Age: " << student->age;
		cout << "  Group: " << student->group<<"\n";
		student = student->next;
	}

	cout << "\n";
	student = root;
	for (int i = 0; i < 3; i++)
		student = student->next;

	for (int i = 0; i < Student::nrStudents; i++) //show the list starting from the 3rd element
	{
		cout << "Name: " << student->nume;
		cout << "  Age: " << student->age;
		cout << "  Group: " << student->group << "\n";
		student = student->next;
	}
}
