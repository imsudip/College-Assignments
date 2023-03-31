// Write a C++ program to create a class complex having two integers real and imaginary.
// Create a three constructors function taking no argument, one argument and two arguments
// for three constructors. Show () and sum() functions are member functions, displaying and
// finding the addition of two objects respectively.

#include <iostream>
using namespace std;

class complex
{
private:
    int real, imaginary;

public:
    complex()
    {
        real = 0;
        imaginary = 0;
    }
    complex(int r)
    {
        real = r;
        imaginary = 0;
    }
    complex(int r, int i)
    {
        real = r;
        imaginary = i;
    }
    void show()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }
    complex sum(complex c)
    {
        complex temp;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }
};

int main()
{
    complex c1, c2(5), c3(2, 3), c4;
    c1.show();
    c2.show();
    c3.show();
    c4 = c2.sum(c3);
    c4.show();
    return 0;
}