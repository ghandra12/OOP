#include <iostream>
#include <math.h>
using namespace std;

class complexNumber{
private:
    int ReX,ImX;
public:

    complexNumber(int ReX,int ImX){
        this->ReX=ReX;
        this->ImX=ImX;
    }

    int getReX(){
        return ReX;
    }

    int getImX(){
        return ImX;
    }

   float operator ~(){
       return sqrt(ReX*ReX + ImX*ImX);
   }

    void operator ^(int power){
        int produs_ParteReala=1;
        int produs_ParteImaginara=1;
        for(int i=1;i<=power;i++)
            produs_ParteReala=produs_ParteReala*ReX;
        for(int i=1;i<=power;i++)
            produs_ParteImaginara=produs_ParteImaginara*ImX;
        //i la puterea a doua este -1
        produs_ParteImaginara*=-1;
        //vreau sa afisez un numar sub forma: (a +bi)^2= a^2-b^2 +2*a*bi;
        cout<<(produs_ParteReala+produs_ParteImaginara)<<"+("<<2*ImX*ReX<<")i";
    }
   int operator +(complexNumber y){
       return ReX + y.ReX;
   }
};

int main()
{

    complexNumber x(-4,3),y(-20,1);

    cout<<"\nModul:"<<~x<<endl;

    //!!!! NU AM PUTUT FOLOSI OPERATORUL ^ !!!!!!!

   cout<<"Numarul complex x ridicat la puterea a doua:";
   (x^2);
   //<<"+("<<2*x.getImX()*x.getReX()<<")i";

   cout<<"\nSuma partilor reale a doua numere complexe:"<<x+y<<endl;
    return 0;
}
