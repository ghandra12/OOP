#include <iostream>
#include <math.h>
using namespace std;
template <class T>
T GetMin (T a, T b) {
T result;
result = (a<b)? a : b;// elements a and b should be comparable using > operator.
return (result);
}
class ComplexNumbers{
private:
    int Real;
    int Imaginar;
public:
    ComplexNumbers(){}
    ComplexNumbers(int Real,int Imaginar){
        this->Real=Real;
        this->Imaginar=Imaginar;
    }
    float modul(){
         return sqrt(Real*Real+Imaginar*Imaginar);

    }
    bool operator <(ComplexNumbers z1){

            return modul()<z1.modul();

    }
};
int main () {
ComplexNumbers z1(2,3),z2(5,6);
ComplexNumbers result=GetMin<ComplexNumbers>(z1,z2);
cout<<"Modulul mai mic:\n";
cout<<result.modul();

return 0;
}
