#include <iostream>
#include <string>
using namespace std;

struct Ingredient{
    int number_of_calories;
    string name;
};

class Sweet {
protected:
    Ingredient base_ingredient_1;
    Ingredient base_ingredient_2;
public:
    Ingredient get_base_ingredient_1(){return this->base_ingredient_1;}
    void set_base_ingredient_1(int number_of_calories, string name){
        this->base_ingredient_1.number_of_calories=number_of_calories;
        this->base_ingredient_1.name=name;
    }
    Ingredient get_base_ingredient_2(){return this->base_ingredient_2;}
    void set_base_ingredient_2(int number_of_calories, string name){
        this->base_ingredient_2.number_of_calories=number_of_calories;
        this->base_ingredient_2.name=name;
    }

    void prepare(){cout<<"This is how you prepare a basic sweet"<<endl;}
    void serve(){cout<<"This is how you serve a basic sweet"<<endl;}
};

class Cake : public Sweet{
protected:
    Ingredient cake_ingredient_1;
    Ingredient cake_ingredient_2;
public:
    Ingredient get_cake_ingredient_1(){return this->cake_ingredient_1;}
    void set_cake_ingredient_1(int number_of_calories, string name){
        this->cake_ingredient_1.number_of_calories=number_of_calories;
        this->cake_ingredient_1.name=name;
    }
    Ingredient get_cake_ingredient_2(){return this->cake_ingredient_2;}
    void set_cake_ingredient_2(int number_of_calories, string name){
        this->cake_ingredient_2.number_of_calories=number_of_calories;
        this->cake_ingredient_2.name=name;
    }

    void prepare(){cout<<"This is how you prepare a cake"<<endl;}
    void serve(){cout<<"This is how you serve a cake"<<endl;}
};

class Muffin : public Sweet{
protected:
    Ingredient muffin_ingredient_1;
    Ingredient muffin_ingredient_2;
    string form;
public:
    Ingredient get_muffin_ingredient_1(){return this->muffin_ingredient_1;}
    void set_muffin_ingredient_1(int number_of_calories, string name){
        this->muffin_ingredient_1.number_of_calories=number_of_calories;
        this->muffin_ingredient_1.name=name;
    }
    Ingredient get_muffin_ingredient_2(){return this->muffin_ingredient_2;}
    void set_muffin_ingredient_2(int number_of_calories, string name){
        this->muffin_ingredient_2.number_of_calories=number_of_calories;
        this->muffin_ingredient_2.name=name;
    }
    string get_form(){return this->form;}
    void set_form(string form){this->form=form;}

    void prepare(){cout<<"This is how you prepare a muffin"<<endl;}
    void serve(){cout<<"This is how you serve a muffin"<<endl;}
};

class Chocolate_Cake : public Cake{
protected:
    Ingredient chocolate_cake_ingredient_1;
    Ingredient chocolate_cake_ingredient_2;
    bool is_served_hot;
public:
    Ingredient get_chocolate_cake_ingredient_1(){return this->chocolate_cake_ingredient_1;}
    void set_cake_ingredient_1(int number_of_calories, string name){
        this->chocolate_cake_ingredient_1.number_of_calories=number_of_calories;
        this->chocolate_cake_ingredient_1.name=name;
    }
    Ingredient get_chocolate_cake_ingredient_2(){return this->chocolate_cake_ingredient_2;}
    void set_chocolate_cake_ingredient_2(int number_of_calories, string name){
        this->chocolate_cake_ingredient_2.number_of_calories=number_of_calories;
        this->chocolate_cake_ingredient_2.name=name;
    }
    bool get_is_served_hot(){return is_served_hot;}
    void set_is_served_hot(bool value){this->is_served_hot=value;}

    void prepare(){cout<<"This is how you prepare a chocolate cake"<<endl;}
    void serve(){cout<<"This is how you serve a chocolate cake"<<endl;}
};

int main(){

    Sweet *sweet = new Sweet();
    sweet->prepare();
    sweet->serve();
    cout<<endl;

    Cake *cake = new Cake();
    cake->prepare();
    cake->serve();    
    cout<<endl;

    Muffin *muffin = new Muffin();
    muffin->prepare();
    muffin->serve();
    cout<<endl;

    Chocolate_Cake *chocolate_cake = new Chocolate_Cake();
    chocolate_cake->prepare();
    chocolate_cake->serve();
    cout<<endl;

    delete sweet;
    delete cake;
    delete muffin;
    delete chocolate_cake;

    return 0;
}