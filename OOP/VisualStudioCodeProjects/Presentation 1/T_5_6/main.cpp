#include <iostream>
using namespace std;

class Form {
private:
    string color;   
protected:
    string name;
    void setColor(string color) {
        this->color = color;
    }
public:
    Form(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    void showMessage(){
        cout<<"message from Form"<<endl;
    }
    void compute_area(){
        cout<<"Error: Can't compute area of ambiguous form"<<endl;
    }
    void compute_perimeter(){
        cout<<"Error: Can't compute perimeter of ambiguous form"<<endl;
    }
};

class Rectangle:public Form {
protected:
    int width;
    int height;
public:
    Rectangle(string name, int width, int height) :Form(name){
        this->width = width;
        this->height = height;
    }
    void setWidth(int width){
        this->width = width;
    }
    int getWidth(){
        return this->width;
    }
    void showMessage(){
        Form::showMessage(); // operator :: used to call showMessage from base class
        cout<<"message from Rectangle"<<endl;
    }
    void compute_area(){
        cout<<"The area of the rectangle is "<<width*height<<endl;
    }
    void compute_perimeter(){
        cout<<"The perimeter of the rectangle is "<<width*2+2*height<<endl;
    }
};

class Square:public Form {
protected:
    int side;
public:
    Square(string name, int side) :Form(name){
        this->side = side;
    }
    void setSide(int side){
        this->side = side;
    }
    int getSide(){
        return this->side;
    }
    void showMessage(){
        cout<<"message from Square"<<endl;
    }
    void compute_area(){
        cout<<"The area of the square is "<<side*side<<endl;
    }
    void compute_perimeter(){
        cout<<"The perimeter of the square is "<<side*4<<endl;
    }
};
int main()
{
    Form *f = new Form("forma1");
    cout<<"form: "<<f->getName()<<endl;
    f->showMessage();
    f->compute_area();
    f->compute_perimeter();
    cout<<endl;

    Rectangle *r = new Rectangle("rectangle 1", 1, 2);
    cout<<"rectangle name: "<<r->getName()<<" width:"<<r->getWidth()<<endl;
    r->showMessage();
    r->compute_area();
    r->compute_perimeter();
    cout<<endl;

    Square *s = new Square("square 1", 20);
    cout<<"square name: "<<s->getName()<<" side:"<<s->getSide()<<endl;
    s->showMessage();
    s->compute_area();
    s->compute_perimeter();
    cout<<endl;

    return 0;
}