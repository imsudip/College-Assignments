// Write a C++ program to overload operator ‘+’ to concatenate two strings and hence reverse
// the concatenated string.

#include <iostream>
using namespace std;

class String
{
    char str[100];

public:
    void getStr()
    {
        cout << "Enter string: ";
        cin.getline(str, 100);
    }

    void display()
    {
        cout << "String is: " << str << endl;
    }

    String reverse()
    {
        String temp;
        int i = 0, j = 0;
        while (str[i] != '\0')
        {
            i++;
        }
        i--;
        while (i >= 0)
        {
            temp.str[j] = str[i];
            i--;
            j++;
        }
        temp.str[j] = '\0';
        return temp;
    }

    String operator+(String s)
    {
        String temp;
        int i = 0, j = 0;
        while (str[i] != '\0')
        {
            temp.str[j] = str[i];
            i++;
            j++;
        }
        i = 0;
        while (s.str[i] != '\0')
        {
            temp.str[j] = s.str[i];
            i++;
            j++;
        }
        temp.str[j] = '\0';
        temp = temp.reverse();
        return temp;
    }
};

int main()
{
    String s1, s2, s3;
    s1.getStr();
    s2.getStr();
    s3 = s1 + s2;
    s3.display();
    return 0;
}