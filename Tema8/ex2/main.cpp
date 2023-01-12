#include <iostream>
#include <math.h>
using namespace std;
template <class T,class U>
float GetMin (T a, U b) {
float result;
result = (a<b)? a.modul() : b.modul();// elements a and b should be comparable using > operator.
return (result);
}
class FloatValueWrapper {
float value;
public:
    FloatValueWrapper(float value) {
        this->value = value;
    }
    float getValue() {
        return this->value;
    }
    float modul(){
        return abs(value);
    }
};
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
    bool operator <(FloatValueWrapper f){
        return modul()<f.modul();
    }
};
int main () {
ComplexNumbers z1(200,3),z2(5,6);
FloatValueWrapper a(34);
float result=GetMin<ComplexNumbers,FloatValueWrapper>(z1,a);
cout<<"Modulul mai mic:\n";
cout<<result;

return 0;
}
