#include <iostream>
#include <string>
using namespace std;

class Mechanism{
public:
    int complexity;
    bool is_analog;

    void make_noise(){
        cout<<"Hurururururur"<<endl;
    }
    void speed_up(){
        cout<<"Getting the gears turning..."<<endl;
    }
};

class Computing_machine{
public:
    int number_of_tranzistors;
    bool is_turned_on;

    void compute(){
        cout<<"Currently doing maths..."<<endl;
    }
    void to_base_two(){
        cout<<"Converting stuff to binary"<<endl;
    }
};

class Computer : public Computing_machine{
public:
    int storage;
    int software_version;

    void load_operating_system(){
        cout<<"Loading up Windows..."<<endl;
    }
    void erase_data(){
        cout<<"The partition was formatted sucessfully!"<<endl;
    }
};

class Robot : public Computer , public Mechanism{
public:
    bool is_awake;
    int number_of_active_sensors;

    void take_over_the_world(){
        cout<<"Loading erase_humanity.exe"<<endl;
    }
    void talk(){
        cout<<"Hello, I am a cruel robot!"<<endl;
    }
};


int main(){

    Robot *matei = new Robot();   // apelam toate functiile din toate clasele prin intermediul instantei clasei robot

    matei->make_noise();
    matei->speed_up();
    matei->compute();
    matei->to_base_two();
    matei->load_operating_system();
    matei->erase_data();
    matei->take_over_the_world();
    matei->talk();


    return 0;
}