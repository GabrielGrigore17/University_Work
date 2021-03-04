#include <iostream>
#include <list>
#include <string>
using namespace std;


class Driver{
public:
    string name;
    Driver(string name_val): name{name_val} {}
    Driver(): name{"Hatz"} {}
};

class Car{
public:
    string brand;
    Car(string brand_val): brand{brand_val} {}
    Car(): brand{"Dacia"} {}
};

struct Bond
{
    Driver driver;
    Car car;
};


class Couple {
public:
    list <Bond> my_list;

    void add_couple(string name, string brand){
        Bond buff;
        buff.driver.name = name;
        buff.car.brand = brand;
        my_list.push_back(buff);
    }
    void remove_couple(string name, string brand){
        list <Bond> :: iterator it;
        int position = 0;
        for(it=my_list.begin(); it!=my_list.end(); ++it){
            if((*it).driver.name == name)
                my_list.erase(it);
            position++;
        }
    }
    void print_couples(){
        int length = my_list.size();
        cout << "The list contains " << length << " elements" << endl;
        list <Bond> :: iterator it;
        for(it=my_list.begin(); it!=my_list.end(); ++it){
            cout << (*it).driver.name << " " << (*it).car.brand << endl;
        }
    }
};

int main(){

    Couple couple;
    couple.add_couple("Matei", "Dacia");
    couple.add_couple("Dorian", "Mercedes");
    couple.add_couple("Alex", "Renault");
    couple.add_couple("Dorel", "Trabant");
    // couple.remove_couple("Dorel", "Trabant");
    couple.print_couples();

    return 0;
}