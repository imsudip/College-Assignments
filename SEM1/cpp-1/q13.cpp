// Write a C++ program to overload the following operators
// a) ‘>>’ to accept time from user (in hours: mins:sec)
// b) ‘+’ to add two different user-given time.
// c) ‘<<’ to display the time in hours: mins: sec format.
// d) ‘==’ to check whether two user-given times are equal or not.

#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
    int hours, mins, sec;

public:
    void display()
    {
        cout << "Time is: " << hours << ":" << mins << ":" << sec << endl;
    }
    Time operator+(Time t)
    {
        Time temp;
        temp.sec = sec + t.sec;
        temp.mins = mins + t.mins;
        temp.hours = hours + t.hours;
        if (temp.sec >= 60)
        {
            temp.sec -= 60;
            temp.mins++;
        }
        if (temp.mins >= 60)
        {
            temp.mins -= 60;
            temp.hours++;
        }
        return temp;
    }
    bool operator==(Time t)
    {
        if (hours == t.hours && mins == t.mins && sec == t.sec)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend istream &operator>>(istream &in, Time &t);
    friend ostream &operator<<(ostream &out, Time &t);
};

istream &operator>>(istream &in, Time &t)
{
    cout << "Enter time in hours:mins:sec format: "; // 12:34:56
    in >> t.hours;
    in.ignore();
    in >> t.mins;
    in.ignore();
    in >> t.sec;
    return in;
}

ostream &operator<<(ostream &out, Time &t)
{
    out << "Time is: " << t.hours << ":" << t.mins << ":" << t.sec << endl;
    return out;
}

int main()
{
    Time t1, t2, t3;
    cin >> t1;
    cin >> t2;
    t3 = t1 + t2;
    cout << t3;
    if (t1 == t2)
    {
        cout << "Both times are equal" << endl;
    }
    else
    {
        cout << "Both times are not equal" << endl;
    }
    return 0;
}