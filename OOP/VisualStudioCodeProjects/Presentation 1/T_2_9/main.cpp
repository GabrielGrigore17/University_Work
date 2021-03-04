#include <iostream>
using namespace std;

struct Student{
    string name;
    int grade;
};

template <class T>
void swap_objects (T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}



int main(){

    Student Alin;
    Alin.name="alin";
    Alin.grade=10;
    Student Dragos;
    Dragos.name="dragos";
    Dragos.grade=9;
    Student Matei;
    Matei.name="matei";
    Matei.grade=7;

    swap_objects(Alin, Dragos); // alin devine dragos si dragos devine alin

    cout << Alin.name <<" "<<Dragos.name;

    return 0;
}