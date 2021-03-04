#include <iostream>
using namespace std;

template <typename T>
T scadere (T a, T b){
    return a-b;
}
template <typename T>
T adunare (T a, T b){
    return a+b;
}
template <typename T>
T adunare_sau_scadere (T a, char ch, T b, T (*f1)(T,T), T (*f2)(T,T)){  // primeste acces la doua numere si un caracter "+"/"-" si la cele doua functii definite mai sus
    if(ch=='-')
        return f1(a,b);
    if(ch=='+')
        return f2(a,b);
    return 0;
}

int main(){


    int (*f1)(int,int)=&scadere; // declaram pe f1 care primeste adresa functiei scadere
    int (*f2)(int,int)=&adunare;

    int a=10;
    int b=12;
    char ch='+';
    cout<<adunare_sau_scadere(a,ch,b,f1,f2);

    return 0;
}