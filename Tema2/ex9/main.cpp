#include <iostream>
using namespace std;

template <typename T>

T Sum(T a, T b)
{
    return a + b;
}

int main()
{
    int x=23, y=55;
    float z=2.56, t=13.45;
    char c='m', d = 'n';
    char g[10]="merge ", h[10]="Andra";
    cout <<"ints: " << Sum(x, y) << endl;
    cout <<"floats: " << Sum(z, t) << endl;
    cout <<"chars: " << Sum(c, d);
   // cout << "strings: " << Max(g, h);
//cannot add pointers => error
//cannot add chars => nothing, as a sum of char cannot return a char
}
