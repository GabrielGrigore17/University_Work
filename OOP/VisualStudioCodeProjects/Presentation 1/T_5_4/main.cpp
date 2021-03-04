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

    Form(){cout<<"Basic form constructor called"<<endl<<endl;}
    ~Form(){cout<<"Basic form destructor called"<<endl<<endl;}

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
    Rectangle(){cout<<"Basic rectangle constructor called"<<endl<<endl;}
    ~Rectangle(){cout<<"Basic rectangle destructor called"<<endl<<endl;}

    void setWidth(int width){
        this->width = width;
    }
    int getWidth(){
        return this->width;
    }
    string get_form_color(){return get_color();}            
    void set_form_color(string color){set_color(color);}
};

//from testing we can deduce that the parent constructor will always be called before the child constructor when initializing a child object
//the destructors are called in the opposite order if the objects are stored on the stack (if they are on the heap we have to delete them manually)

int main()
{
    Form *f = new Form();
    f->setName("forma1");
    cout<<"forma: "<<f->getName()<<endl<<endl;
    Rectangle *r = new Rectangle();
    r->setWidth(23);
    r->setName("rectangle 1");
    cout<<"rectangle name: "<<r->getName()<<" width:"<<r->getWidth()<<endl<<endl;
    delete r;
    delete f;
    return 0;
}