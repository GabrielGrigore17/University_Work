#include <iostream>
using namespace std;

struct Student{
    string name;
    int grade;
};

Student Max(Student student_1, Student student_2){
    return student_1.grade>student_2.grade ? student_1 : student_2;  // compara notele si returneaza studentul cu nota cea mai mare
}

int main(){

    Student Alex;
    Student Matei;
    Alex.grade=7;
    Alex.name="Alex";
    Matei.grade=9;
    Matei.name="Matei";
    Student student_eminent;
    student_eminent= Max(Alex,Matei);
    cout<<"Studentul eminent are nota "<<student_eminent.grade<<" si il cheama "<<student_eminent.name<<endl;

    return 0;
}