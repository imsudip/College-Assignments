#include <iostream>
using namespace std;

class LeapYear
{
private:
    int year;

public:
    LeapYear()
    {
        cout << "Enter year: ";
        cin >> year;
    }
    ~LeapYear()
    {
        if (year % 4 == 0)
        {
            cout << year << " is a leap year" << endl;
        }
        else
        {
            cout << year << " is not a leap year" << endl;
        }
    }
};

int main()
{
    LeapYear l;
    return 0;
}