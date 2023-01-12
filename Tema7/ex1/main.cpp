#include<iostream>
#include <string>
using namespace std;

class Hummer{
public:

    int power;
    int mileage;
    Hummer(int power,int mileage){
        this->power=power;
        this->mileage=mileage;
    }
    class Wheel{
    public:
        int air_presure;
        string wheel_season;
        string position;


        void changeWheel(string new_wheel_season){
            wheel_season=new_wheel_season;
            cout<<"Wheel "<<position<<"is changed";

        }
        void removeWheel(){
          cout<<"Wheel "<<position<<" is removed";
        }
    };
   Wheel roata1;
   Wheel roata2;
   Wheel roata3;
   Wheel roata4;
};
class Carriage{
public:
    int NumberOfHorses;
    Carriage(int NumberOfHorses){
        this->NumberOfHorses=NumberOfHorses;
    }
    class Wheel{
        public:
        string material;
        string position;

        void changeWheel(string new_material){
            material=new_material;
            cout<<"Wheel "<<position<<" is changed";
        }

        void removeWheel(){
          cout<<"Wheel "<<position<<" is removed";
        }
    };
   Wheel roata1;
   Wheel roata2;
   Wheel roata3;
   Wheel roata4;
};

int main() {
    Hummer hummer(200,234);

    hummer.roata1.wheel_season="vara";
    hummer.roata2.wheel_season="vara";
    hummer.roata3.wheel_season="vara";
    hummer.roata4.wheel_season="vara";

    hummer.roata1.position="stanga_fata";
    hummer.roata3.position="dreapta_spate";
    hummer.roata4.position="dreapta_fata";
    hummer.roata2.position="stanga_spate";

    Carriage carriage(2);

    carriage.roata1.material="lemn";
    carriage.roata2.material="lemn";
    carriage.roata3.material="lemn";
    carriage.roata4.material="lemn";

    carriage.roata1.position="stanga_fata";
    carriage.roata3.position="dreapta_spate";
    carriage.roata4.position="dreapta_fata";
    carriage.roata2.position="stanga_spate";

    cout<<endl;
    cout<<"Schimbam o roata din fata pentru Hummer:\n";
    hummer.roata1.changeWheel("iarna");
    cout<<"\nRoata din "<<hummer.roata1.position<<" are acum cauciuc de.."<<hummer.roata1.wheel_season;
    cout<<endl;
    cout<<"Eliminam o roata pentru Carriage:\n";
    carriage.roata4.removeWheel();

    return 0;
}
