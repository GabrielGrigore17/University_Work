#include <iostream>
#include <list>
#include <string>
using namespace std;

class Group {
public:
    class Student{
    public:
        string first_name;
        string last_name;
        string groupe;
        Student(string first_name_val, string last_name_val, string groupe_val):first_name{first_name_val}, last_name{last_name_val}, groupe{groupe_val} {}
        Student(string first_name_val, string last_name_val):Student{first_name_val,last_name_val,"None"} {}
        Student(string first_name_val):Student{first_name_val,"None","None"} {}
        Student():Student{"None","None","None"} {}
        ~Student(){}
    };


    list <Student> student_list;
    void add_student(string first_name_val, string last_name_val, string groupe_val){
        student_list.push_back(Student{first_name_val, last_name_val, groupe_val});
    }

    void print_list (){
        list <Student> :: iterator it;
        for(it=student_list.begin(); it!=student_list.end(); ++it){
            cout<<(*it).first_name<<" "<<(*it).last_name<<" "<<(*it).groupe<<endl;
        }
    }   
};

int main(){

    Group group;
    group.add_student("Ciocoias","Matei","CEN_2_2");
    group.add_student("Hatzulescu","Dorian","CEN_2_2");
    group.add_student("Batcampii","Dorel","CEN_2_2");
    group.print_list();
}