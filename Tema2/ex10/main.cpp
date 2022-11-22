#include <iostream>
using namespace std;

struct Student {
    string name;
    int grade;
};

template <typename T>

void interch(T* a, T* b)
{
    T aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int x=5, y=18;
    float z=4.67, t=123.43;
    double m=234.56, n=564.00;
    char c='a', d='b';
    Student student1, student2;
    student1.name = "Andra";
    student1.grade = 10;
    student2.name = "Andrei";
    student2.grade = 6;

    interch(&x, &y);
    interch(&z, &t);
    interch(&m, &n);
    interch(&c, &d);
    interch(&student1, &student2);

    cout << "Int: " << x << ' ' << y;
    cout << "\n";
    cout << "Float: " << z << ' ' <<t;
    cout << "\n";
    cout << "Double: " << m << ' ' << n;
    cout << "\n";
    cout << "Char: " << c << ' ' << d;
    cout << "\n";
    cout << "Student 1: " << student1.name << ' ' << student1.grade;
    cout << "\n";
    cout << "Student 2: " << student2.name << ' ' << student2.grade;

    return 0;

}
