// Write a C++ program to add two complex numbers using friend function

#include <iostream>

using namespace std;

class Complex
{
    int real, imag;

public:
    void input()
    {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void showComplex()
    {
        cout << real << " + " << imag << "i" << endl;
    }

    friend Complex addComplex(Complex c1, Complex c2);
};

Complex addComplex(Complex c1, Complex c2)
{
    Complex c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    return c3;
}

int main()
{
    Complex c1, c2, c3;
    cout << "Enter first complex number: " << endl;
    c1.input();
    cout << "Enter second complex number: " << endl;
    c2.input();
    c3 = addComplex(c1, c2);
    cout << "Sum of complex numbers: ";
    c3.showComplex();
    return 0;
}