#include <iostream>
#include <string>
using namespace std;

class Shape{
public:
    virtual void draw() = 0;
    virtual double compute_area() = 0;
};

class Circle : public Shape{
public:
    double radius;
    Circle(double radius_val): radius{radius_val} {} 
    virtual void draw() override{ cout << "circle\n"; } 
    virtual double compute_area() override{
        return radius*radius*3.14;
    }
};

class Rectangle : public Shape{
public:
    double length;
    double width;
    Rectangle(double length_val, double width_val): length{length_val}, width{width_val} {}
    virtual void draw() override{ cout << "rectangle\n"; } 
    virtual double compute_area() override{
        return width*length;
    }
};

class Square : public Shape{
public:
    double side;
    Square(double side_val): side{side_val} {}
    virtual void draw() override { cout << "square\n"; }
    virtual double compute_area() override{
        return side*side;
    }
};

int main()
{
    Square square{4};
    Rectangle rectangle{3, 4};
    Circle circle{3};
    cout << square.compute_area() << " " << rectangle.compute_area() << " " << circle.compute_area();

    return 0;
}