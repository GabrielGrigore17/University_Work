#include <iostream>
#include <string>
#include <list>
using namespace std;

class Person{
private:
    string name;
    int age;
public:
    Person(string name_val, int age_val): name{name_val}, age{age_val} {}
    Person(): name{"Dorian Hatz Popa"}, age{32} {}
    void set_name(string name_val){name = name_val;}
    string get_name(){return name;}
    void set_age(int age_val){age = age_val;}
    int get_age(){return age;}
};

class Employee: public Person{
public:
    string employer;
};

template <class T, class U>
class MyTemplate {
public:
    T element_1;
    U element_2;
    bool flag;

    MyTemplate(T element): element_1{element} {flag=0;}
    MyTemplate(U element): element_2{element} {flag=1;}

    T get_element_1(){
        return element_1;
    }
    U get_element_2(){
        return element_2;
    }

};



int main() {

    Person person_1{"Andi Popescu", 39};
    Person person_2{"Andrei Selaru", 19};
    Employee employee_1;
    MyTemplate <Person, Employee> individual_1{person_1};
    MyTemplate <Person, Employee> individual_2{person_2};
    MyTemplate <Person, Employee> individual_3{employee_1};
    list <MyTemplate<Person, Employee>> my_list;
    my_list.push_back(individual_1);
    my_list.push_back(individual_2);
    my_list.push_back(individual_3);
    
    list <MyTemplate<Person, Employee>> :: iterator it;

    it = my_list.begin();
    cout<<(*it).get_element_1().get_name()<<endl;
    ++it;
    cout<<(*it).get_element_1().get_name()<<endl;
    ++it;
    cout<<(*it).get_element_2().get_name()<<endl;


    return(0);
}