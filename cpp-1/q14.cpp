//  Write a C++ program to swap two numbers using friend function without using third
// variable.

#include <iostream>
using namespace std;

class Number
{
    int num;

public:
    Number()
    {
        cout << "Enter number: ";
        cin >> num;
    }
    int showNum()
    {
        return num;
    }
    friend void swap(Number &n1, Number &n2);
};

void swap(Number &n1, Number &n2)
{
    n1.num = n1.num + n2.num;
    n2.num = n1.num - n2.num;
    n1.num = n1.num - n2.num;
}

int main()
{
    Number n1, n2;
    cout << "Before swapping: " << endl;
    cout << "n1 = " << n1.showNum() << endl;
    cout << "n2 = " << n2.showNum() << endl;
    swap(n1, n2);
    cout << "After swapping: " << endl;
    cout << "n1 = " << n1.showNum() << endl;
    cout << "n2 = " << n2.showNum() << endl;
    return 0;
}