#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;


class Course{

private:
    string course_name;
    string teacher_name;
public:
    Course(string course_name, string teacher_name):course_name{course_name}, teacher_name{teacher_name} {}
    string get_course_name() {return this->course_name;}
    string get_teacher_name() {return this->teacher_name;}
};

class Student {

private:
    string first_name;
    string last_name;
    string groupe;
    list <Course> list_of_courses;

public:

    bool operator == (const Student& s) const { return first_name == s.first_name && last_name == s.last_name; }
    bool operator != (const Student& s) const { return !operator==(s); }


    Student();
    Student(string first_name);
    Student(string first_name, string last_name);
    Student(string first_name, string last_name, string groupe);
    ~Student();
    string get_first_name();
    void set_first_name(string first_name);
    string get_last_name();
    void set_last_name(string last_name);
    string get_groupe();
    void set_groupe(string groupe);
};





Student::Student(string first_name_val, string last_name_val, string groupe_val):first_name{first_name_val}, last_name{last_name_val}, groupe{groupe_val} {}
Student::Student(string first_name_val, string last_name_val):Student{first_name_val,last_name_val,"None"} {}
Student::Student(string first_name_val):Student{first_name_val,"None","None"} {}
Student::Student():Student{"None","None","None"} {}
Student::~Student(){}
string Student::get_first_name(){return first_name;}
void Student::set_first_name(string first_name){this->first_name=first_name;}
string Student::get_last_name(){return last_name;}
void Student::set_last_name(string last_name){this->last_name=last_name;}
string Student::get_groupe(){return groupe;}
void Student::set_groupe(string groupe){this->groupe=groupe;}


void print_list (list <Student> student_list){
    list <Student> :: iterator it;
    for(it=student_list.begin(); it!=student_list.end(); ++it){
        cout<<(*it).get_first_name()<<" "<<(*it).get_last_name()<<" "<<(*it).get_groupe()<<endl;
    }
}

int search_for_a_student(string first_name, string last_name, list <Student> student_list){
    list <Student> :: iterator it;
    int position=0;
    for(it=student_list.begin(); it!=student_list.end(); ++it){
        if((*it).get_first_name()==first_name&&(*it).get_last_name()==last_name)
            break;
        position++;
    }

    return position;
}

int main(){

    list <Student> list_of_students;

    list_of_students.push_back(Student{"Ciocoias","Matei","CEN_2_2"});
    list_of_students.push_back(Student{"Hatzulescu","Dorian","CEN_2_2"});
    list_of_students.push_back(Student{"Batcampii","Dorel","CEN_2_2"});
    list_of_students.push_back(Student{"Bendeac","Mihai","CEN_2_2"});
    list_of_students.push_back(Student{"Aninoaia","Adela","CEN_2_2"});
    list_of_students.push_back(Student{"Grigore","Gabriel","CEN_2_2"});
    list_of_students.push_back(Student{"Lenghel","Cosmin","CEN_2_2"});

    cout<<endl<<"This is the initial list of enrolled students"<<endl<<endl;
    print_list(list_of_students);
    cout<<endl;

    while (true){
        cout<<"Do you want to add a student? (1-yes, 0-no)"<<endl;
        int option;
        string buffer;
        cin>>option;
        if(!option)
            break;
        cout<<"First name: ";
        getline(cin,buffer);
        string first_name;
        getline(cin,first_name);  // verificam daca utilizatorul vrea sa adauge un student in lista  si daca vrea ii cerem  nume prenume si grupa si adaugam studentul in lista 
        cout<<endl;
        cout<<"Last name: ";
        string last_name;
        getline(cin,last_name);
        cout<<endl;
        cout<<"Groupe: ";
        string groupe;
        getline(cin,groupe);
        cout<<endl;
        list_of_students.push_back(Student{first_name,last_name,groupe});
    }

    while(true){
        cout<<"Do you want to search for a student? (1-yes, 0-no)"<<endl;
        int option;
        cin>>option;
        if(option){
            string buffer;
            cout<<"First name: ";
            getline(cin,buffer);   // cauti un student dupa nume
            string first_name;
            getline(cin,first_name);
            cout<<endl;
            cout<<"Last name: ";
            string last_name;
            getline(cin,last_name);
            cout<<endl;
            cout<<"Do you want to edit, to delete or to display the student? (0-edit 1-delete 2-display)"<<endl;
            //getline(cin,buffer);
            cin>>option;
            if(!option){
                string buffer;
                cout<<"New first name: ";
                getline(cin,buffer);
                string new_first_name;
                getline(cin,new_first_name);  // editezi studentul (ii schimbi numele prenumele grupa)
                cout<<endl;
                cout<<"New last name: ";
                string new_last_name;
                getline(cin,new_last_name);
                cout<<endl;
                cout<<"New groupe: ";
                string new_groupe;
                getline(cin,new_groupe);
                cout<<endl;
                int position=search_for_a_student(first_name,last_name,list_of_students);
                list <Student>::iterator it = list_of_students.begin();
                advance(it,position);
                (*it).set_first_name(new_first_name);
                (*it).set_last_name(new_last_name);
                (*it).set_groupe(new_groupe);
            }
            if(option==1){
                Student random_student {first_name,last_name};  // stergi studentul
                list_of_students.remove(random_student);
            }
            if(option==2){
                int position=search_for_a_student(first_name,last_name,list_of_students);
                list <Student>::iterator it = list_of_students.begin();  // afisezi studentul
                advance(it,position);
                cout<<(*it).get_first_name()<<" "<<(*it).get_last_name()<<" "<<(*it).get_groupe()<<endl;
            }

        }
        else
            break;
    }

    cout<<"This is the final list of enrolled students"<<endl<<endl;
    print_list(list_of_students);
    cout<<endl<<"We have "<<list_of_students.size()<<" students in total."<<endl; // se afisaza lista finala de studenti dupa modficari
    return 0;
}