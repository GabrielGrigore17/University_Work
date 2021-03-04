#include <iostream>
using namespace std;
#define choose_library 0

#if choose_library  // daca choose library e 0 se include b.h altfel se include a.h
#include "a.h"
#endif
#if !choose_library
#include "b.h"
#endif


int main(){  
    
    test();

    return 0;
}