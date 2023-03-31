// Write a C++ program to calculate the area and perimeter of a triangle by creating a class
// named 'Triangle' with separate member functions for (i) taking input from user, (ii)
// Calculate the area, (iii) Calculate the perimeter, (iv) printing of data. Two functions must
// be defined inside the class and two functions must be defined outside the class.

#include <iostream>
using namespace std;

class Triangle
{
private:
    float base, height, side1, side2, side3;

public:
    void getTriangle()
    {
        cout << "Enter base of triangle: ";
        cin >> base;
        cout << "Enter height of triangle: ";
        cin >> height;
        cout << "Enter side1 of triangle: ";
        cin >> side1;
        cout << "Enter side2 of triangle: ";
        cin >> side2;
        cout << "Enter side3 of triangle: ";
        cin >> side3;
    }
    float area()
    {
        return 0.5 * base * height;
    }
    float perimeter();
    void printData();
};

float Triangle::perimeter()
{
    return side1 + side2 + side3;
}

void Triangle::printData()
{
    cout << "Area of triangle is: " << area() << endl;
    cout << "Perimeter of triangle is: " << perimeter() << endl;
}

int main()
{
    Triangle t;
    t.getTriangle();
    t.printData();
    return 0;
}