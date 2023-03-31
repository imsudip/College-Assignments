// Write a menu-driven C++ program to calculate volume of cube, cuboid, cone, cylinder,
// and sphere using function overloading. For an incorrect choice, proper error message
// should be displayed.

#include <iostream>
using namespace std;

class Shape
{

public:
    float volume(float r) // sphere
    {
        return 4 / 3 * 3.14 * r * r * r;
    }
    float volume(float r, float h) // cone
    {
        return 3.14 / 3 * r * r * h;
    }
    float volume(float r, float h, bool s) // cylinder
    {
        return 3.14 * r * r * h;
    }
    float volume(float l, float b, float h) // cuboid
    {
        return l * b * h;
    }
    float volume(float s, int a) // cube
    {
        return s * s * s;
    }
};

int main()
{
    Shape s;
    while (1)
    {
        int choice;
        cout << "1. Volume of sphere" << endl;
        cout << "2. Volume of cone" << endl;
        cout << "3. Volume of cylinder" << endl;
        cout << "4. Volume of cuboid" << endl;
        cout << "5. Volume of cube" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            float r;
            cout << "Enter radius of sphere: ";
            cin >> r;
            cout << "Volume of sphere is: " << s.volume(r) << endl;
            break;
        case 2:
            float r1, h1;
            cout << "Enter radius of cone: ";
            cin >> r1;
            cout << "Enter height of cone: ";
            cin >> h1;
            cout << "Volume of cone is: " << s.volume(r1, h1) << endl;
            break;
        case 3:
            float r2, h2;
            cout << "Enter radius of cylinder: ";
            cin >> r2;
            cout << "Enter height of cylinder: ";
            cin >> h2;
            cout << "Volume of cylinder is: " << s.volume(r2, h2, true) << endl;
            break;
        case 4:
            float l, b, h;
            cout << "Enter length of cuboid: ";
            cin >> l;
            cout << "Enter breadth of cuboid: ";
            cin >> b;
            cout << "Enter height of cuboid: ";
            cin >> h;
            cout << "Volume of cuboid is: " << s.volume(l, b, h) << endl;
            break;
        case 5:
            float s1;
            cout << "Enter side of cube: ";
            cin >> s1;
            cout << "Volume of cube is: " << s.volume(s1, 1) << endl;
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}