#include <iostream>
#include <math.h>
using namespace std;

int f(double n, bool is_rounded_to_100 = false){
    if (!is_rounded_to_100)
        return round(n);
    else
        return 100*round(n/100); //returneaza cel mai apropiat numar multiplu de 100
}

int main(){

    cout<<f(2.54,false);

    return 0;
}