#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Student {

private:
    static int number_of_students;
    string name;
    int grade;

public:
    Student();
    Student(string name);
    Student(int grade);
    Student(string name, int grade);
    ~Student();
    int get_grade();
    void set_grade(int grade);
    string get_name();
    void set_name(string name);
    static int get_no_students(){return number_of_students;}
};

int Student::number_of_students{0};

Student::Student(string name_val, int grade_val):name{name_val}, grade{grade_val} {number_of_students++;}
Student::Student(string name_val):Student{name_val,0} {}
Student::Student(int grade_val):Student{"None",grade_val} {}
Student::Student():Student{"None",0} {}
Student::~Student(){number_of_students--;}
int Student::get_grade(){return grade;}
void Student::set_grade(int grade){this->grade=grade;}
string Student::get_name(){return name;}
void Student::set_name(string name){this->name=name;}


int main(){
    cout<<Student::get_no_students()<<endl;

    Student matei{};

    cout<<Student::get_no_students()<<endl;

    Student alex{};

    cout<<Student::get_no_students()<<endl;

    Student *student_oarecare = new Student();

    cout<<Student::get_no_students()<<endl;

    delete student_oarecare;

    cout<<Student::get_no_students()<<endl;

    return 0;
}