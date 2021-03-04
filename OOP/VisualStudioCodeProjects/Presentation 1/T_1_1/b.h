#ifndef __HEADER_1_H__
#define __HEADER_1_H__

#include <iostream>
#include <stdio.h>
#include "a.h"
using namespace std;

void mega_test(){
    cout<<"Calling library a.h from b.h: "<<endl;
    test();
}


#endif;