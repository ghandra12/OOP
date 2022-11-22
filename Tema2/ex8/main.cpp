#include <iostream>
#include <cstring>
using namespace std;

template <typename T>

T maximum(T x, T y, T z)
{
    T Max = x;
    if (y > Max)
        Max = y;
    if (z > Max)
        Max = z;
    return Max;
}

int main()
{
    int a = 5, b = 8, c = 2;
    float x = 2.75, y = 4.44, z = 2.25;
    char s[10] = "zambet", t[10] = "dragut", u[10] = "printi";

    cout << maximum(a, b, c) << "\n" << maximum(x, y, z) << "\n" << maximum(s, t, u);
    return 0;
}
