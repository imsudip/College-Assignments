// Write a C++ Program to calculate area of a circle to demonstrate the access modifier (A)
// public (B) private (C) protected.

#include <iostream>
using namespace std;

class Circle
{
private:
    float radius;

protected:
    void getRadius()
    {
        cout << "Enter radius of circle: ";
        cin >> radius;
    }
    float area()
    {
        return 3.14 * radius * radius;
    }
};

class Area : public Circle
{
public:
    void display()
    {
        getRadius();
        cout << "Area of circle is: " << area() << endl;
    }
};

int main()
{
    Area a;
    // a.getRadius();
    a.display();
    return 0;
}