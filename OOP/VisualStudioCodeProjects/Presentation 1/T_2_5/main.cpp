#include <iostream>
#include <string.h>
using namespace std;


struct Student{
    string name;
    int grade;
};


int f(int x){
    return sizeof(x);
}
int f(double x){
    return sizeof(x);
}
int f(char *x){
    return strlen(x);
}
int f(Student x){
    return sizeof(x);
}

int main(){
    int x =10;
    double y = 10.2;
    char z[10] = "abcdef";
    Student student;
    cout<<f(x)<<endl;  //in functie de tipul argumentului inclus in f, compilerul isi da seama ce varianta a functiei trebuie apelata
    cout<<f(y)<<endl;
    cout<<f(z)<<endl;
    cout<<f(student)<<endl;

}
