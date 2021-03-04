#include <iostream>
using namespace std;

class Plant{
public:
    virtual void grow() = 0;
    virtual ~Plant(){}
};

class FoodSource{
public:
    virtual void is_processed() = 0;
    virtual ~FoodSource(){}
};

class Carrot: public Plant{
public:
    virtual void is_orange() = 0;
    virtual ~Carrot(){}
};

class Chicken: public FoodSource{
public:
    virtual void is_roasted() = 0;
    virtual ~Chicken(){}
};

class Apple: public FoodSource, public Plant{
public:
    virtual void grow() override{ cout << "Grow" << endl;}
    virtual void is_processed() override{ cout << "It's not processed!" << endl;}
};


int main(){
    Apple apple;
    apple.grow();
    apple.is_processed();

    return 0;
}