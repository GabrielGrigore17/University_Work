#ifndef __CLASS_H__
#define __CLASS_H__

#include <string>

class Form {
private:
    std::string color;
protected:
    std::string name;
    std::string get_color(){return this->color;};
    void set_color(std::string color){this->color=color;};
public:
    std::string getName(){
        return this->name;
    }
    void setName(std::string name){
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
    std::string get_form_color(){return get_color();}            
    void set_form_color(std::string color){set_color(color);}
};

#endif