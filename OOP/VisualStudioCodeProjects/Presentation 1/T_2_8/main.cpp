#include <iostream>
using namespace std;

struct Student{
    string name;
    int grade;
};

template <class T>  // poate fi apelata indiferent de tipul de date 
T GetMax (T a, T b, T c) {
  return ( a>b&&a>c ? a : (b>c ? b : c) );
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


    // cout << GetMax(Alin,Dragos,Matei); doesn't work because it doesn't know what to compare

    return 0;
}