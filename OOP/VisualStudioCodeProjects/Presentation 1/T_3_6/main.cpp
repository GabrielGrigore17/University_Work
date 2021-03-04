#include <iostream>
#include <vector>
#include <string>
#include <list>
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

void print_list (list <Student> student_list){
    list <Student> :: iterator it;
    for(it=student_list.begin(); it!=student_list.end(); ++it){
        cout<<(*it).get_name()<<endl;
    }
}

int main(){
    
    list <Student> list_of_students;
    
    list_of_students.push_back(Student{"Matei"});
    list_of_students.push_back(Student{"Alex"});
    list_of_students.push_back(Student{"Dorel"});
    list_of_students.push_back(Student{"Mihai"});
    list_of_students.push_back(Student{"Andrei"});
    list_of_students.push_back(Student{"Gabriel"});
    list_of_students.push_back(Student{"Cosmin"});

    print_list(list_of_students);
    cout<<-(Student::get_no_students())<<endl; // afiseaza numarul de studenti
    
    return 0;
}