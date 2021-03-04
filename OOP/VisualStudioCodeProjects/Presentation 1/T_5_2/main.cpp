#include <iostream>
#include <string>
using namespace std;

class Form {
private:
    string color;
protected:
    string name;
    string get_color(){return this->color;};
    void set_color(string color){this->color=color;};
public:
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    };
class Rectangle:public Form {
protected:
    int width;
    int height;
public:
    void setWidth(int width){
        this->width = width;
    }
    int getWidth(){
        return this->width;
    }
    string get_form_color(){return get_color();}            
    void set_form_color(string color){set_color(color);}
};

/* 
the class rectangle can access the setter and getter if they are protected but not if they are private
the instance of class rectangle can only access the setter and getter through public functions of class rectangle
*/
int main()
{
    Form *f = new Form();
    f->setName("forma1");
    cout<<"forma: "<<f->getName()<<endl;
    Rectangle *r = new Rectangle();
    r->setWidth(23);
    r->setName("rectangle 1");
    cout<<"rectangle name: "<<r->getName()<<" width:"<<r->getWidth()<<endl;



    return 0;
}