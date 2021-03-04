#include <iostream>
#include <math.h>
using namespace std;

class ComplexNumber{
public:
    double real_part;
    double imaginary_part;
    ComplexNumber(){
        real_part = 0;
        imaginary_part = 0;
    }
    ComplexNumber(double real_part_val, double imaginary_part_val): real_part{real_part_val}, imaginary_part{imaginary_part_val} {}
};

class Operations{
private:
    double real_number_1 = 0;
    double real_number_2 = 0;
    ComplexNumber complex_number_1;
    ComplexNumber complex_number_2;
    bool flag;
public:
    Operations(double real_number_val_1, double real_number_val_2): real_number_1{real_number_val_1}, real_number_2{real_number_val_2} {flag = 0;}
    Operations(ComplexNumber complex_1, ComplexNumber complex_2){
        complex_number_1.real_part = complex_1.real_part;
        complex_number_1.imaginary_part = complex_1.imaginary_part;
        complex_number_2.real_part = complex_2.real_part;
        complex_number_2.imaginary_part = complex_2.imaginary_part;
        flag = 1;
    }
    void sum (){
        if(!flag)
            cout << real_number_1 + real_number_2 << endl;
        if(flag){
            cout << complex_number_1.real_part + complex_number_2.real_part;
            cout << " + " << complex_number_1.imaginary_part + complex_number_2.imaginary_part << "*i" << endl;
        }
    }
};


int main (){
    ComplexNumber complex_number_1{4, 5};
    ComplexNumber complex_number_2{6, 7};
    Operations operation_1{10, 12};
    Operations operation_2{complex_number_1, complex_number_2};

    operation_1.sum();
    operation_2.sum();

}