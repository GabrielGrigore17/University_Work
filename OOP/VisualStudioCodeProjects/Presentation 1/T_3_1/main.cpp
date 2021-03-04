#include <iostream>
using namespace std;



class Student { // o clasa e un struct care pe langa variabile poate avea si functii care pot fi apelate doar printr-o variabila de tipul clasei
public:
    int grade; // =10
    Student();
    Student(int grade);
    ~Student();
    int get_grade();
    void set_grade(int grade);
};

Student::Student(int grade_val):grade{grade_val} {} // un constructor preia valori pentru parametrii clasei si ii initializeaza
Student::Student():Student{0} {}
Student::~Student(){cout << "Instance destroyed !"<<endl;}  // un destructor e apelat automat cand se termina programul. Nu trebuie sa iti bati capul cu el. Il observi ca are ~ in fata
int Student::get_grade(){return grade;} // returneaza nota lui matei
void Student::set_grade(int grade){this->grade=grade;} // preia un argument (nota lui matei) si actualizeaza nota lui matei


int main(){

    Student matei{};
    matei.set_grade(9);
    cout<<"Matei are nota "<<matei.get_grade()<<endl;

    Student *alex = new Student();
    alex->set_grade(8);
    cout<<"Alex are nota "<<alex->get_grade()<<endl;
    delete alex;

    return 0;
}