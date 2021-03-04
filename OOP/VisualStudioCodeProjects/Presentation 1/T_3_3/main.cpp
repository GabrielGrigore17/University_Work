#include <iostream>
using namespace std;

class Complex_number {
private:
    double real_part;
    double irrational_part;
public:
    Complex_number();
    Complex_number(double number, char ch);
    Complex_number(double real_part, double irrational_part);
    void set_real_part(double real_part);
    double get_real_part();
    void set_irrational_part(double irrational_part);
    double get_irrational_part();
    void get_sum(Complex_number first, Complex_number second);
};

Complex_number::Complex_number(double real_part_val, double irrational_part_val): real_part {real_part_val}, irrational_part {irrational_part_val} {} 
Complex_number::Complex_number(double number, char ch){
    if(ch=='r'||ch=='R'){
        real_part=number;
        irrational_part=0;
    }
    else
        if(ch=='i'||ch=='I'){
            irrational_part=number;
            real_part=0;
        }
        else
            {cout<<"Invalid input"<<endl;
            real_part=0;
            irrational_part=0;
            }

}
Complex_number::Complex_number(): real_part{0}, irrational_part{0} {}

void Complex_number::set_real_part(double number){ this->real_part = number;}
double Complex_number::get_real_part(){return this->real_part;}
void Complex_number::set_irrational_part(double number){this->irrational_part = number;}
double Complex_number::get_irrational_part(){return this->irrational_part;}
void Complex_number::get_sum(Complex_number first, Complex_number second){
    this->real_part=first.get_real_part()+second.get_real_part();
    this->irrational_part=first.get_irrational_part()+second.get_irrational_part(); 
}


int main(){

    Complex_number first_number(12,'r');
    Complex_number second_number(13,'i');
    Complex_number sum{};
    sum.get_sum(first_number,second_number);
    cout<<"The sum is "<<sum.get_real_part()<<" + "<<sum.get_irrational_part()<<"i"<<endl;

    return 0;
}