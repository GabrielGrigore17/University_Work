#include <iostream>
using namespace std;

class A
{
public:
    int aa;
protected:
    int ab;
private:
    int ac;
public:
    void testA(){
    aa=10;
    ab=10;
    ac=10;
    }
};
class B : public A
{
public:
    int ba;
protected:
    int bb;
private:
    int bc;
public: 
    void testB(){
    ba=10;
    bb=10;
    bc=10;
    aa=10;
    ab=10;
    // ac=10; this won't work because it's private.
    }
};
class C : public B
{
public:
    int ca;
protected:
    int cb;
private:
    int cc;
public:
void testC(){
    ba=10;
    bb=10;
    // bc=10; this won't work because it's private
    aa=10;
    ab=10;
    // ac=10; this won't work because it's private.
    ca=10;
    cb=10;
    cc=10;
    }
};


int main(){
    C test{};
    test.testA();
    test.testB();
    test.testC();

    return 0;
}