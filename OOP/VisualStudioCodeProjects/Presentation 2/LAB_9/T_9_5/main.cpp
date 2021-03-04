#include <iostream>
#include <string>
using namespace std;

class Shape{
public:
    virtual void draw() = 0; 
};

class Circle : public Shape{
public:
    void draw() { cout << "circle\n"; } 
};
class Triangle : public Shape
{
public:
    void draw() { cout << "triangle\n"; } 
};

class Drawing{
public:
    Shape *pShape;
    Drawing(Shape *pShape_val): pShape{pShape_val} {}
    void drawShape(){
        pShape->draw();
    }
};

class TestDrawing{
public:
    void test(){
        Drawing* d = new Drawing(new Triangle());
        d->drawShape();
        Drawing e{new Circle()};
        e.drawShape();
    }
};


int main()
{
    TestDrawing test;
    test.test();
    // Drawing* d = new Drawing(new Triangle());
    // d->drawShape();
    // Drawing e{new Circle()};
    // e.drawShape();
    return 0;
}