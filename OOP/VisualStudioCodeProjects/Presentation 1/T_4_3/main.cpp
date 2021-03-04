#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Student {
private:
    int note;
    string name;
public:
    Student *next;

    Student(int note = 0, string name="Joe Doe"){
        this->note = note;
        this->name = name;
    }
    void setNote(int n){
        this->note = n;
    }
    int getNote(){
        return this->note;
    }
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
};
class StudentsGroup {
private:
    Student *head,*tail;
public:
    StudentsGroup(){
        head = NULL;
        tail = NULL;
    }
    void add_student(int note, string name)
    {
        Student *tmp = new Student(note,name);
        tmp->setName(name);
        tmp->setNote(note);
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void display()
    {
        Student *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->getName()<<" "<<tmp->getNote()<< endl;
            tmp = tmp->next;
        }
    }
 
};
int main()
{
    StudentsGroup *studentsGroup = new StudentsGroup();
    studentsGroup->add_student(10,"Alex");
    studentsGroup->add_student(9,"Mihai");
    studentsGroup->add_student(8,"Gabriel");
    studentsGroup->display();

    return 0;
}