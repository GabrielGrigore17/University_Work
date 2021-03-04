#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Student {
private:
    int note;
    string name;
public:

    bool operator > (const Student& s) const { return this->note>s.note; }
    bool operator < (const Student& s) const { return this->note<s.note; }
    bool operator << (const Student& s) const { return this->name.compare(s.name)<0; }

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
        for(int i=0; i < studentsList.size(); i++){
            int min_index = i;
            for(int j = i+1; j<studentsList.size(); j++)
                if(studentsList[j] << studentsList[min_index])
                    min_index=j;
        
        swap(studentsList[min_index],studentsList[i]);
        }
    }
    void sort_by_grade(){
        for(int i=0; i < studentsList.size(); i++){
            int max_index = i;
            for(int j = i+1; j<studentsList.size(); j++)
                if(studentsList[j] > studentsList[max_index])
                    max_index=j;
        
        swap(studentsList[max_index],studentsList[i]);
        }
    }
    void print_student_with_maximum_grade(){    // se itereaza prin lista pentru a gasi indicele studentului cu nota cea mai mare si se afiseaza studentul
        int max_index=0;
        for(int i=0; i < studentsList.size(); i++){
            if(studentsList[i]>studentsList[max_index])
                max_index = i;
        }
        cout<<studentsList[max_index].getName()<<" "<<studentsList[max_index].getNote()<<endl;

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
    cout<<endl;
    studentsGroup->print_student_with_maximum_grade();
    return 0;
}