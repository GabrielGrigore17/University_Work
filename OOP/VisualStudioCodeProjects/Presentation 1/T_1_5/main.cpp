#include <iostream>
#include "a.h"
#include "b.h"
using namespace std;

int main(){
    
    #ifndef __A_H__  // verifica daca a fost definita inainte libaria a in functie de cheia "__A_H__"
    a_namespace::test();
    #else
    b_namespace::test();
    #endif
    
    return 0;
}