// Write a C++ program to overload the function calculate() as follows
// void calculate(int m, char ch) with one integer argument and one character argument. If ch
// is ‘r’ then the function reverse the digits of integer m. If ch is ‘p’, then the function will
// check whether integer m is prime or not. It should be noted that the number of digits in m
// should be greater than 1. Note: no library function should be used.

#include <iostream>
using namespace std;

class Operation
{
public:
    void calculate(int m, char ch)
    {
        if (ch == 'r')
        {
            int rev = 0;
            while (m > 0)
            {
                rev = rev * 10 + m % 10;
                m /= 10;
            }
            cout << "Reverse of number is: " << rev << endl;
        }
        else if (ch == 'p')
        {
            int flag = 0;
            for (int i = 2; i < m; i++)
            {
                if (m % i == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Number is prime" << endl;
            }
            else
            {
                cout << "Number is not prime" << endl;
            }
        }
    }
};

int main()
{
    Operation o;
    o.calculate(123, 'r');
    o.calculate(123, 'p');
    return 0;
}
