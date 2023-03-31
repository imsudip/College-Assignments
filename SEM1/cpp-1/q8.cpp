// Write a C++ program to demonstrate
// (A) Copy Constructor (B) Parameterized Constructor (C) Virtual destructor

#include <iostream>
using namespace std;

class A
{
private:
    int x;

public:
    A()
    {
        x = 0;
    }
    A(int a)
    {
        x = a;
    }
    A(A &a)
    {
        x = a.x;
    }
    void display()
    {
        cout << "x = " << x << endl;
    }
    virtual ~A()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    A a1;
    A a2(10);
    A a3(a2);
    a1.display();
    a2.display();
    a3.display();
    return 0;
}