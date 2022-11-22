#include <iostream>

using namespace std;
class rectangle
{
public:
    int lungime,latime;
    int area(){
        return lungime*latime;
    }
    int perimetru(){

    return 2*(lungime+latime);
    }
};
int main()
{
   rectangle rect1, rect2;
    cin>>rect1.lungime>>rect1.latime;
    cin>>rect2.lungime>>rect2.latime;
    if(rect1.perimetru()>rect2.perimetru())
        cout<<"primul perimetru mai mare\n";
    else
        cout<<"al doilea perimetru mai mare\n";
    if(rect1.area()>rect2.area())
        cout<<"prima are mai mare";
    else
        cout<<"a doua arie mai mare";
}
