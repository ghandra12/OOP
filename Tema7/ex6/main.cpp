#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
class Grupa;
list<Grupa>Grupe;
class Person{
private:
    string nume;
    int age;
public:
    Person(){}
    Person(string nume,int age){
        this->age=age;
        this->nume=nume;
    }
    string getNume(){
        return nume;
    }

    int getAge(){
        return age;
    }


};
class Sofer:public Person{
public:
    friend class Student;
    int NumarMasini;
    string CategoriePermis;
    Sofer(string nume,int age,int NumarMasini,string CategoriePermis):Person(nume,age){
        this->CategoriePermis=CategoriePermis;
        this->NumarMasini=NumarMasini;
    }

};
class Grupa{
public:
    string nume_grupa;
    Grupa(string nume_grupa){
        this->nume_grupa=nume_grupa;
    }
    class Student:public Person{
    public:
        int an;
        Student(){
        }
        Student(string nume,int age,int an):Person(nume,age){
            this->an=an;
        }

    };
    list<Student>Studenti;
    void addStudent(Student student){
        Studenti.push_back(student);
    }
    void updateStudent(string nume_student,int noul_an){
        for(auto it=Studenti.begin();it!=Studenti.end();it++)
           if((*it).getNume()==nume_student)
               (*it).an=noul_an;
    }
    void removeStudent(string nume_stud){
            Studenti.remove_if([&nume_stud](Student &student){
                                return student.getNume()==nume_stud;
                                }
                               );
    }
    void DisplayStudenti(){
     for(auto it=Studenti.begin();it!=Studenti.end();it++)
        cout<<(*it).getNume()<<" din anul "<<(*it).an<<endl;
    }

};
void addGrupa(Grupa grupa){
    Grupe.push_back(grupa);
}
 void SchimbareGrupa(string nume,string an_superior){
        for(auto it=Grupe.begin();it!=Grupe.end();it++)
           if((*it).nume_grupa==nume)
               (*it).nume_grupa=an_superior;
}
void MutareStudent(string nume_stud,string noua_grupa){
     Grupa::Student stud();
     for(auto it=Grupe.begin();it!=Grupe.end();it++){
                stud=*find_if((*it).Studenti.begin(),(*it).Studenti.end(),[&nume_stud](Grupa::Student &s){  return s.getNume()==nume_stud;});
               (*it).removeStudent(nume_stud);
     }
      for(auto it=Grupe.begin();it!=Grupe.end();it++)
            if((*it).nume_grupa==noua_grupa)
                    (*it).addStudent(stud);

    }
void DisplayGrupe(){
     for(auto it=Grupe.begin();it!=Grupe.end();it++)
        cout<<(*it).nume_grupa<<endl;
    }
int main()
{   cout<<"1. Crearea unor grupe de studenti\n";
    cout<<"2. Adaugarea/stergerea/modificarea unui student dintr-o grupa\n";
    cout<<"3. Afisarea tuturor studentilor dintr-o grupa\n";
    cout<<"4. Schimbarea numelui grupei, considerata ca trecerea in an superior\n";
    cout<<"5. Mutarea unui student dintr-o grupa în alta\n";
    cout<<"6. Afisare grupe\n";
    int tasta;
    string nume_grupa,nume,nume_nou;
    int age,an;
    while(1){

        cout<<"\ntasta=";cin>>tasta;
        switch(tasta){
        case 1:{
            cout<<"Numele grupei:";cin>>nume_grupa;
            Grupa grupa(nume_grupa);
            addGrupa(grupa);
            break;}
        case 2:
            int optiune;
            cout<<"\nAlege 1 pentru adaugare/ 2 pentru stergere/ 3 pentru modificarea datelor unui student: ";
            cin>>optiune;
            if(optiune==1){
            cout<<"\nNumele grupei in care adaugam un nou student:";cin>>nume_grupa;
            cout<<"\nNume student:";cin>>nume;
            cout<<"\nVarsta:";cin>>age;
            cout<<"\nAn:";cin>>an;
            Grupa::Student student(nume,age,an);
             for(auto it=Grupe.begin();it!=Grupe.end();it++)
                 if((*it).nume_grupa==nume_grupa)
                    (*it).addStudent(student);}
            else
               if(optiune==2){
                cout<<"\nNumele grupei din care stergem un student:";cin>>nume_grupa;
                cout<<"\nNumele studentului pe care il stergem:";cin>>nume;
                for(auto it=Grupe.begin();it!=Grupe.end();it++)
                     if((*it).nume_grupa==nume_grupa)
                          (*it).removeStudent(nume);


            }
               else
                if(optiune==3){
                cout<<"\nNumele grupei in care modificam datele unui student:";cin>>nume_grupa;
                cout<<"\nNumele studentului pe care il modificam:";cin>>nume;
               cout<<"\Noul an al studentului:";cin>>an;
                for(auto it=Grupe.begin();it!=Grupe.end();it++)
                     if((*it).nume_grupa==nume_grupa)
                          (*it).updateStudent(nume,an);

               }

            break;
        case 3:
            cout<<"Lista studenti:\n";
            for(auto it=Grupe.begin();it!=Grupe.end();it++){
                cout<<"\nGrupa: ";cout<<(*it).nume_grupa<<endl;
                (*it).DisplayStudenti();
            }
            break;
        case 4:
                cout<<"\nNumele grupei pe care il schimbam:";cin>>nume_grupa;
                cout<<"\nNoul nume(an superior):";cin>>nume_nou;
                SchimbareGrupa(nume_grupa,nume_nou);


            break;
        case 5:
                cout<<"\nNumele grupei din care mutam studentul:";cin>>nume_grupa;
                cout<<"\nNumele studentului pe care il mutam:";cin>>nume;
                MutareStudent(nume,nume_grupa);
            break;
        case 6:
            DisplayGrupe();
            break;
        default: cout<<"tasta gresita";
                 return 0;
            break;
        }


    }
    return 0;
}
