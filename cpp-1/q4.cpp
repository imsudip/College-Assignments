// Print the pattern using class and objects
// *****
//  ***
//   *

#include <iostream>
using namespace std;

class Pattern
{
private:
    int n;

public:
    void getN()
    {
        cout << "Enter n: ";
        cin >> n;
    }
    void printPattern()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j >= i)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (j < n - i - 1)
                {
                    cout << "*";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Pattern p;
    p.getN();
    p.printPattern();
    return 0;
}