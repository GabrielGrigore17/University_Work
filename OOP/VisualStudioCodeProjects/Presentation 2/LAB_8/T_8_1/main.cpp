#include <iostream>
#include <string>
#include <math.h>
using namespace std;

template <class T>
class TwoValues {
    T first, second;
public:
    TwoValues(T first, T second)
    {
        this-> first = first;
        this->second = second;
    }
    T getMin() {
        T result;
        result = first < second ? first : second;
        return result;
    }
};

class ComplexNumber{
public:
    double real_part;
    double imaginary_part;
    ComplexNumber(){
        real_part = 0;
        imaginary_part = 0;
    }
    ComplexNumber(double real_part_val, double imaginary_part_val): real_part{real_part_val}, imaginary_part{imaginary_part_val} {}
    double module(){
        return sqrt(pow(real_part, 2) + pow(imaginary_part, 2));
    }
};

int main() {

    ComplexNumber number_1{4,5};
    ComplexNumber number_2{7,8};

    TwoValues <double> myobject(number_1.module(), number_2.module());
    cout << myobject.getMin() << endl;

    TwoValues <int> myobject1(100, 75);
    cout << myobject1.getMin() << endl;
    TwoValues <string> myobject2("abcd", "mnop");
    cout << myobject2.getMin() << endl;
    TwoValues <double> myobject3(34.3425, 4586.256974);
    cout << myobject3.getMin() << endl;
    return 0;
}
