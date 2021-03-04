#include <iostream>
#include "a.h"
#include "b.h"

void test(){
    std::cout<<"this is a test from main!"<<std::endl;
}

int main(){

    test();
    a_namespace::test(); // daca functia este declarata intr-un namespace, atunci acesta trebuie mentionat cand se apeleaza functia
    b_namespace::test();

    return 0;
}