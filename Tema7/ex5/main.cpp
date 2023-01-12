#include <iostream>
#include <list>
#include <string>
using namespace std;
class Sofer;
class Angajat;
class Parinte;

list <Sofer>Soferi;
list<Angajat>Angajati;
list<Parinte>Parinti;

class Person{
private:
    string nume;
    string prenume;
    int inaltime;
    int age;
public:
    Person(string nume,string prenume,int age,int inaltime){
        this->age=age;
        this->nume=nume;
        this->prenume=prenume;
        this->inaltime=inaltime;

    }
    string getNume(){
        return nume;
    }
    string getPrenume(){
        return prenume;
    }
    int getAge(){
        return age;
    }
    int getInaltime(){
        return inaltime;
    }


};
class Sofer:public Person{
public:
    int NumarMasini;
    string CategoriePermis;
    Sofer(string nume,string prenume,int age,int inaltime,int NumarMasini,string CategoriePermis):Person(nume,prenume,age,inaltime){
        this->CategoriePermis=CategoriePermis;
        this->NumarMasini=NumarMasini;
    }

};
class Angajat:public Sofer{
public:
    string domeniu;
    string functie;
     Angajat(string nume,string prenume,int age,int inaltime,int NumarMasini,string CategoriePermis, string domeniu,string functie):Sofer(nume,prenume,age,inaltime,NumarMasini,CategoriePermis){
        this->domeniu=domeniu;
        this->functie=functie;

    }

};
class Parinte:public Angajat{
public:
    int numar_de_copii;
    bool casatorit;

    Parinte(string nume,string prenume,int age,int inaltime,int NumarMasini,string CategoriePermis,string domeniu,string functie,int numar_de_copii,bool casatorit):Angajat(nume,prenume,age,inaltime,NumarMasini,CategoriePermis,domeniu,functie)
    {
        this->numar_de_copii=numar_de_copii;
        this->casatorit=casatorit;

    }

    class Copil:public Person{
    public:
        string clasa;
        string scoala;

        Copil(string nume,string prenume,int age,int inaltime,string clasa,string scoala):Person(nume,prenume,age,inaltime){
        this->clasa=clasa;
        this->scoala=scoala;
        }
    };
    list<Copil>Copii;
    void addCopil(Copil copil)
      {
        Copii.push_back(copil);

      }
    void updateCopil(string nume_copil,string noua_clasa){

      for(auto it=Copii.begin();it!=Copii.end();it++)
      {
          if((*it).getNume()==nume_copil)
              (*it).clasa=noua_clasa;
      }
    }
      void DisplayCopii(){
           for(auto it=Copii.begin();it!=Copii.end();it++)
               cout<<(*it).getNume()<<" "<<(*it).clasa<<endl;
       }


};
void addSofer(Sofer sofer)
      {
          Soferi.push_back(sofer);

      }
void updateSofer(string nume_sofer,int noul_numar_de_masini){

      for(auto it=Soferi.begin();it!=Soferi.end();it++)
      {
          if((*it).getNume()==nume_sofer)
              (*it).NumarMasini=noul_numar_de_masini;
      }
}
void removeSofer(string nume_sofer){

    Soferi.remove_if([&nume_sofer](Sofer &sofer){
                 return sofer.getNume()==nume_sofer;
                 }
                 );
}
void DisplaySoferi(){
 for(auto it=Soferi.begin();it!=Soferi.end();it++)
    cout<<(*it).getNume()<<" "<<(*it).NumarMasini<<endl;
}
void addAngajat(Angajat angajat)
      {
          Angajati.push_back(angajat);

      }
void updateAngajat(string nume_angajat,string noua_functie){

      for(auto it=Angajati.begin();it!=Angajati.end();it++)
      {
          if((*it).getNume()==nume_angajat)
              (*it).functie=noua_functie;
      }
}
void removeAngajat(string nume_angajat){

    Angajati.remove_if([&nume_angajat](Angajat &angajat){
                 return angajat.getNume()==nume_angajat;
                 }
                 );
}
void DisplayAngajati(){
 for(auto it=Angajati.begin();it!=Angajati.end();it++)
    cout<<(*it).getNume()<<" "<<(*it).functie<<endl;
}
void addParinte(Parinte parinte)
      {
          Parinti.push_back(parinte);

      }
void updateParinte(string nume_parinte,int noul_numar_de_copii){

      for(auto it=Parinti.begin();it!=Parinti.end();it++)
      {
          if((*it).getNume()==nume_parinte)
              (*it).numar_de_copii=noul_numar_de_copii;
      }
}
void DisplayParinti(){
 for(auto it=Parinti.begin();it!=Parinti.end();it++)
    cout<<(*it).getNume()<<" "<<(*it).numar_de_copii<<endl;
}

int main()
{
    cout<<"1. Adaugarea si modificarea datelor unui sofer\n"
        <<"2. Stergerea unui sofer\n"
        <<"3. Adaugarea si modificarea datelor unui angajat\n"
        <<"4. Stergerea unui angajat\n"
        <<"5. Adaugarea si modificarea datelor unui parinte\n"
        <<"6. Adaugarea si modificarea datelor unui copil\n"
        <<"7. Afisarea tuturor soferilor\n"
        <<"8. Afisarea tuturor angajatilor\n"
        <<"9. Afisarea tuturor parintilor\n"
        <<"10. Afisarea tuturor copiilor\n";

     cout<<endl<<"Alege ce actiune doresti sa faci:\n";
     int tasta,optiune,numar_de_copii;
     int age,inaltime,nr_masini;
     string nume,prenume,cat_permis,functie,domeniu,scoala,clasa,nume_parinte;
     bool casatorit;
     while(1){
        cout<<"Tasta=";
        cin>>tasta;
        switch(tasta){
    case 1:
        cout<<"\n1 pentru adaugare, 2 pentru modificare: ";
         cin>>optiune;
         if(optiune==1)
         {   cout<<"\nNume:";cin>>nume;
             cout<<"\nPrenume:";cin>>prenume;
             cout<<"\nAge:";cin>>age;
             cout<<"\nInaltime:";cin>>inaltime;
             cout<<"\nNumar de masini";cin>>nr_masini;
             cout<<"\nCategoria permisului:";cin>>cat_permis;
             Sofer sofer(nume,prenume,age,inaltime,nr_masini,cat_permis);
             addSofer(sofer);
         }
         else{
            if(optiune==2){
                cout<<"\nNumele soferului caruia dorim sa-i modificam numarul de masini detinute:";cin>>nume;
                int noul_numar;
                cout<<"noul numar de masini:";cin>>noul_numar;
                updateSofer(nume,noul_numar);}}
        break;
    case 2:
          cout<<"\nNumele soferului pe care dorim sa-l stergem:";cin>>nume;
           removeSofer(nume);
        break;
    case 3:
        cout<<"\n1 pentru adaugare, 2 pentru modificare: ";
         cin>>optiune;
         if(optiune==1)
         {   cout<<"\nNume:";cin>>nume;
             cout<<"\nPrenume:";cin>>prenume;
             cout<<"\nAge:";cin>>age;
             cout<<"\nInaltime:";cin>>inaltime;
             cout<<"\nNumar de masini";cin>>nr_masini;
             cout<<"\nCategoria permisului:";cin>>cat_permis;
             cout<<"\nDomeniul in care lucreaza:";cin>>domeniu;
             cout<<"\Functia pe care o ocupa angajatul:";cin>>functie;
             Angajat angajat(nume,prenume,age,inaltime,nr_masini,cat_permis,domeniu,functie);
             addAngajat(angajat);
         }
         else{
            if(optiune==2){
                cout<<"\nNumele angajatului caruia dorim sa-i modificam functia:";cin>>nume;
                string noua_functie;
                cout<<"noua functie:";cin>>noua_functie;
                updateAngajat(nume,noua_functie);}}
        break;
    case 4:
         cout<<"\nNumele angajatului pe care dorim sa-l stergem:";cin>>nume;
           removeAngajat(nume);
        break;
    case 5:
        cout<<"\n1 pentru adaugare, 2 pentru modificare: ";
         cin>>optiune;
         if(optiune==1)
         {   cout<<"\nNume:";cin>>nume;
             cout<<"\nPrenume:";cin>>prenume;
             cout<<"\nAge:";cin>>age;
             cout<<"\nInaltime:";cin>>inaltime;
             cout<<"\nNumar de masini";cin>>nr_masini;
             cout<<"\nCategoria permisului:";cin>>cat_permis;
             cout<<"\nDomeniul in care lucreaza:";cin>>domeniu;
             cout<<"\Functia pe care o ocupa angajatul:";cin>>functie;
             cout<<"\nNumar de copii: ";cin>>numar_de_copii;
             cout<<"\nCasatorit:";cin>>casatorit;
             Parinte parinte(nume,prenume,age,inaltime,nr_masini,cat_permis,domeniu,functie,numar_de_copii,casatorit);
             addParinte(parinte);
         }
         else{
            if(optiune==2){
                cout<<"\nNumele parintelui caruia dorim sa-i modificam numarul de copii:";cin>>nume;
                int noul_numar_de_copii;
                cout<<"noul numar de copii: ";cin>>noul_numar_de_copii;
                updateParinte(nume,noul_numar_de_copii);}}
        break;
    case 6:
        cout<<"\n1 pentru adaugare, 2 pentru modificare: ";
         cin>>optiune;
         if(optiune==1)

         {   cout<<"Numele parintelui caruia ii adaugam un copil nou:";cin>>nume_parinte;
             cout<<"\nNume:";cin>>nume;
             cout<<"\nPrenume:";cin>>prenume;
             cout<<"\nAge:";cin>>age;
             cout<<"\nInaltime:";cin>>inaltime;
             cout<<"\nScoala:";cin>>scoala;
             cout<<"\nClasa: ";cin>>clasa;
             for(auto it=Parinti.begin();it!=Parinti.end();it++)
             if((*it).getNume()==nume_parinte){
                       Parinte::Copil copil(nume,prenume,age,inaltime,scoala,clasa);
                      (*it).addCopil(copil);
                  }

         }
         else{
            if(optiune==2){
                cout<<"\nNumele COPILULUI caruia dorim sa-i modificam clasa:";cin>>nume;
                string noua_clasa;
                cout<<"noua clasa: ";cin>>noua_clasa;
                cout<<"Numele parintelui caruia ii modificam clasa copilului:";cin>>nume_parinte;
                 for(auto it=Parinti.begin();it!=Parinti.end();it++)
                      if((*it).getNume()==nume_parinte){

                            (*it).updateCopil(nume,noua_clasa);
                  }
                }
            }
        break;
    case 7:
        "Lista de soferi:\n";
        DisplaySoferi();
        break;
     case 8:
          "Lista de angajati:\n";
        DisplayAngajati();
        break;
    case 9:
         "Lista de parinti:\n";
        DisplayParinti();
        break;
    case 10:
         "Lista de copii:\n";
         for(auto it=Parinti.begin();it!=Parinti.end();it++){
            cout<<(*it).getNume()<<"are urmatorii copii: ";
              (*it).DisplayCopii();
              cout<<endl;}

        break;
    default:cout<<"Tasta gresita, foloseste un numar intre 1 si 10";
     break;
        }
     }
}
