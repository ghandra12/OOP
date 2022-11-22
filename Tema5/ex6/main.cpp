#include <iostream>
#include <list>
using namespace std;
class Ingredients{
private:
    string name;
    int number_of_calories;
public:

    Ingredients(string name,int number_of_calories){
        this->name=name;
        this->number_of_calories=number_of_calories;
    }
    string getIngredientName(){
        return name;
    }
    int getIngredientCalories(){
        return number_of_calories;
    }

};
class Sweet{
private:
    string NAME;
public:
    string getNAME(){
        return NAME;
    }
    Sweet(string NAME){
        this->NAME=NAME;
    }
    list<Ingredients> ingredients;
    void prepare(){
        cout<<"Need a sweet treat that's easy to make? These simple desserts do just the trick.";
    }
    void serve(){
        cout<<"Serve the sweets with water";
    }
    void addIngredient(Ingredients ingredient){
        ingredients.push_back(ingredient);
    }
};
class Cake:public Sweet{
private:
    string type;
public:
     string getType(){
        return type;
     }
     Cake(string type,string NAME):Sweet(NAME){
        this->type=type;
     }
     void prepare(){
        cout<<endl;
        cout<<"Beat the butter and caster sugar together in a large bowl using an electric whisk until pale and fluffy. Add the eggs, one at a time, until combined.etc ";
    }
    void serve(){
        cout<<"Serve the sweets with water";
    }

};
class ChocolateCake:public Cake{
public:
    void AboutChocolateCake(){
       cout<<"You should try!!!!!!";
    }
    void prepare(){
        cout<<endl;
        cout<<"The Best Chocolate Cake Recipe – A one bowl chocolate cake recipe that is quick, easy, and delicious! Updated with gluten-free, dairy-free, and egg-free options!etc.";
    }
    void serve(){
        cout<<"Serve the sweets with water";
    }

};
class Muffin:public Sweet{
private:
    string form;
public:
    string getForm(){
        return form;
    }
    void setForm(string a_form){
        form=a_form;
    }
    Muffin(string NAME,string form):Sweet(NAME){
        this->form=form;
    }
    void prepare(){
        cout<<endl;
        cout<<"Add 125ml vegetable oil and 250ml semi-skimmed milk and beat until just combined then add 250g golden caster sugar and whisk until you have a smooth batter.etc";

    }
    void serve(){
        cout<<"Serve the sweets with someone you love";
    }

};
int main()
{   Ingredients ingredient1("egg",23),ingredient2("milk",40),ingredient3("oil",100),ingredient4("sugar",67),ingredient5("cream cheese",120),ingredient6("chocolate",200);
    Sweet sweet1("CheeseCake");
    sweet1.prepare();
    sweet1.addIngredient(ingredient1);
    sweet1.addIngredient(ingredient5);
    sweet1.addIngredient(ingredient4);
    cout<<endl;
    cout<<"For "<< sweet1.getNAME()<<" you should use:\n";
    for(auto it=sweet1.ingredients.begin();it!=sweet1.ingredients.end();it++)
    {
        cout<<(*it).getIngredientName()<<endl;
    }
    cout<<endl;
    Muffin muffin1("Muffin with chocolate","heart");
        cout<<"Look at this muffin! It looks like a "<<muffin1.getForm();
    cout<<endl;
    muffin1.serve();
    cout<<endl;
    cout<<"If you are single then...";
    ///folosim metoda din clasa de baza(nu cea suprascrisa)
    muffin1.Sweet::serve();

    return 0;
}
