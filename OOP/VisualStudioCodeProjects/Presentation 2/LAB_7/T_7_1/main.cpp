#include <iostream>
#include <string>
using namespace std;

class Wheel{
public:
    bool is_mounted;
    int size;
    int offset;
};

class Carriage{
public:
    Wheel wheel_1;
    Wheel wheel_2;
    Wheel wheel_3;
    Wheel wheel_4;
    void remove_wheel(int number){
        switch (number)
        {
        case 1:
            wheel_1.is_mounted = false;
            break;
        case 2:
            wheel_2.is_mounted = false;
            break;
        case 3:
            wheel_3.is_mounted = false;
            break;
        case 4:
            wheel_4.is_mounted = false;
            break;

        default:
            cout << "Wheel number is invalid" << endl;
            break;
        }
    }
    void replace_wheel(Wheel wheel, int number){
        switch (number)
        {
        case 1:
            wheel_1 = wheel;
            break;
        case 2:
            wheel_2 = wheel;
            break;
        case 3:
            wheel_3 = wheel;
            break;
        case 4:
            wheel_4 = wheel;
            break;

        default:
            cout << "Wheel number is invalid" << endl;
            break;
        }
    }
};

class Hummer{
public:
    Wheel wheel_1;
    Wheel wheel_2;
    Wheel wheel_3;
    Wheel wheel_4;
    void remove_wheel(int number){
        switch (number)
        {
        case 1:
            wheel_1.is_mounted = false;
            break;
        case 2:
            wheel_2.is_mounted = false;
            break;
        case 3:
            wheel_3.is_mounted = false;
            break;
        case 4:
            wheel_4.is_mounted = false;
            break;

        default:
            cout << "Wheel number is invalid" << endl;
            break;
        }
    }
    void replace_wheel(Wheel wheel, int number){
        switch (number)
        {
        case 1:
            wheel_1 = wheel;
            break;
        case 2:
            wheel_2 = wheel;
            break;
        case 3:
            wheel_3 = wheel;
            break;
        case 4:
            wheel_4 = wheel;
            break;

        default:
            cout << "Wheel number is invalid" << endl;
            break;
        }
    }
};