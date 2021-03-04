#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Student {

private:
    string name;
    int grade;
    void change_student(){                    
        this->grade=8;
        this->name="None";                 
    }                           
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
};

Student::Student(string name_val, int grade_val):name{name_val}, grade{grade_val} {}
Student::Student(string name_val):Student{name_val,0} {}
Student::Student(int grade_val):Student{"None",grade_val} {}
Student::Student(){change_student();}
Student::~Student(){}
int Student::get_grade(){return grade;}
void Student::set_grade(int grade){this->grade=grade;}
string Student::get_name(){return name;}
void Student::set_name(string name){this->name=name;}


int main(){

    vector <Student> student_vector;
    student_vector.push_back(Student{"Matei",9});
    student_vector.push_back(Student{"Alex",3});
    student_vector.push_back(Student{"Denis",8});
    student_vector.push_back(Student{"Sergiu",5});
    student_vector.push_back(Student{"Catalin",7});
    student_vector.push_back(Student{"George",6});
    student_vector.push_back(Student{"Ionut",4});
    
    Student student_eminent {0};
    for(auto student : student_vector){
            if(student.get_grade()>student_eminent.get_grade())
                student_eminent = student;}

    cout<<"Studentul "<<student_eminent.get_name()<<" a luat nota "<<student_eminent.get_grade()<<" si este studentul nostru eminent"<<endl;

    Student random_student {};
    cout<<random_student.get_grade()<<" "<<random_student.get_name();
    

    return 0;
}