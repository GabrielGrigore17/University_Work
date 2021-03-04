#include <iostream>
#include <math.h>
using namespace std;

struct Nr_complex{
    int partea_reala;
    int partea_imaginara;
};

int calculeaza_modulul(int nr){
    return nr>0 ? nr : -nr;
}

double calculeaza_modulul(int partea_reala, int partea_imaginara){
    return sqrt( pow(partea_imaginara,2) + pow(partea_reala,2) );
}

int main(){
    cout<< calculeaza_modulul(-13)<<" "<<calculeaza_modulul(4,3)<<endl;

    return 0;
}