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
    double real_number = 0;
    ComplexNumber complex_number;
    bool flag;
public:
    Operations(double real_number_val): real_number{real_number_val} {flag = 0;}
    Operations(ComplexNumber complex){
        complex_number.real_part = complex.real_part;
        complex_number.imaginary_part = complex.imaginary_part;
        flag = 1;
    }
    double module(){
        if (!flag)
            if(real_number > 0)
                return real_number;
            else
                return -real_number;
        return sqrt(pow(complex_number.real_part, 2) + pow(complex_number.imaginary_part, 2));
    }
    void display(){
        if(!flag)
            cout << real_number << endl;
        if(flag)
            cout << complex_number.real_part << " + " << complex_number.imaginary_part << "*i" << endl;
    }
};


int main (){
    ComplexNumber complex_number{4, 5};
    Operations operation_1{10};
    Operations operation_2{complex_number};

    cout << operation_1.module() << endl;
    cout << operation_2.module() << endl;
    operation_1.display();
    operation_2.display();

}