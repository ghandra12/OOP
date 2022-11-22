#include <iostream>

using namespace std;
class ComplexNumber{

private:
    int real_z;
    int imaginar_z;
public:
    ComplexNumber(int realV, int imagV){
     real_z=realV;
     imaginar_z=imagV;
}
 int getReal( ){
  return real_z;

}
int getImag( ){
  return imaginar_z;

}
    void addComplex( ComplexNumber z2)
    {
        real_z+= z2.getReal();
        imaginar_z+=z2.getImag();

    }
    void complexProduct( ComplexNumber z2 ){
     int x3,y3;
     x3=real_z*z2.getReal()- imaginar_z*z2.getImag();
     y3=real_z*z2.getImag()+imaginar_z*z2.getReal();
     real_z=x3;
     imaginar_z=y3;

    }


};
int main()
{
     ComplexNumber z1(3,4),z2(2,3);
     cout<<"Primul numar complex: "<<z1.getReal()<<" + i*"<<z1.getImag()<<endl;
     cout<<"Al doilea numar complex: "<<z2.getReal()<<" + i*"<<z2.getImag()<<endl;
      z1.addComplex(z2);
     cout<<"Suma este: "<<z1.getReal()<<" + i*"<<z1.getImag()<<endl;

      z1.complexProduct(z2);
      cout<<"Produsul este : "<<z1.getReal()<<" + i*"<<z1.getImag()<<endl;

    return 0;
}
