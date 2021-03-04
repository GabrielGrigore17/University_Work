#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Student {
private:
    int note;
    string name;
public:
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
    int studentsNumber;
    vector <Student> studentsList; // singura modificare e de a  schimba modul de stocare dintr-un array intr-un vector deoarece vectorul este dinamic
public:
    StudentsGroup(int studentsNumber){
        this->studentsNumber = studentsNumber;
    }
    void showStudentsInGroup(){
        for(int i=0; i<this->studentsNumber;i++){
            cout<<i<<" "<<studentsList.at(i).getName()<<" "<<studentsList.at(i).getNote()<<endl;
    }
    }
    void readStudentGroup(){
        int note;
        string studentName;
        for(int i=0; i<this->studentsNumber;i++){
            cout<<"student "<<i<<" name:";
            cin>>studentName;
            cout<<"note ";
            cin>>note;
            studentsList.insert(studentsList.end(), Student(note,studentName));
        }
    }
};
int main()
{
    StudentsGroup *studentsGroup = new StudentsGroup(3);
    studentsGroup->readStudentGroup();
    studentsGroup->showStudentsInGroup();
    return 0;
}