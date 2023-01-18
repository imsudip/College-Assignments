// Write a C++ program to find Square of a Number using inline function

#include <iostream>
using namespace std;

inline int square(int x)
{
    return x * x;
}

int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Square of " << x << " is " << square(x) << endl;
    return 0;
}