#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "enter the length of the string: ";
    cin >> n;
    int a = 0, b = 2;
    if (n <= 1)
    {
        cout << 0;
    }
    else if (n <= 2)
    {
        cout << 2;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            int c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        cout << "Number of binary strings of length " << n << " is:";
        cout << b << endl;
    }
    return 0;
}