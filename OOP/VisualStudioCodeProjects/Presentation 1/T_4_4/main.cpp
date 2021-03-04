#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;


class Student {
private:
    int note;
    string name;
public:

    bool operator > (const Student& s) const { return this->note>s.note; }
    bool operator < (const Student& s) const { return this->name.compare(s.name)<0; }

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
    vector <Student> studentsList;
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
    void sort_by_name(){
        for(int i=0; i < studentsList.size(); i++){  // algoritm standard care sorteaza in functie de nume alfabetic
            int min_index = i;
            for(int j = i+1; j<studentsList.size(); j++)
                if(studentsList[j] < studentsList[min_index])
                    min_index=j;
        
        swap(studentsList[min_index],studentsList[i]);
        }
    }
    void sort_by_grade(){                               // algoritm standard care sorteaza in functie de nota
        for(int i=0; i < studentsList.size(); i++){
            int min_index = i;
            for(int j = i+1; j<studentsList.size(); j++)
                if(studentsList[j] > studentsList[min_index])
                    min_index=j;
        
        swap(studentsList[min_index],studentsList[i]);
        }
    }
};
int main()
{
    StudentsGroup *studentsGroup = new StudentsGroup(3);
    studentsGroup->readStudentGroup();

    studentsGroup->showStudentsInGroup();
    cout<<endl;
    studentsGroup->sort_by_name();
    studentsGroup->showStudentsInGroup();
    cout<<endl;
    studentsGroup->sort_by_grade();
    studentsGroup->showStudentsInGroup();
    return 0;
}