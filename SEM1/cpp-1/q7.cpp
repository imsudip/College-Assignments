// Write a C++ program to create a class String, which stores String with constructor, displays
// the String and joins two Strings with join user defined function taking two arguments of
// String object.

#include <iostream>
using namespace std;

class String
{
private:
    char str[100];

public:
    String()
    {
        cout << "Enter String: ";
        cin.getline(str, 100);
    }
    String(const char *s)
    {
        int i = 0;
        while (s[i] != '\0')
        {
            str[i] = s[i];
            i++;
        }
        str[i] = '\0';
    }
    void display()
    {
        cout << "String is: " << str << endl;
    }
    String friend join(String s1, String s2)
    {
        String temp("");
        int i = 0;
        while (s1.str[i] != '\0')
        {
            temp.str[i] = s1.str[i];
            i++;
        }
        int j = 0;
        while (s2.str[j] != '\0')
        {
            temp.str[i] = s2.str[j];
            i++;
            j++;
        }
        temp.str[i] = '\0';
        return temp;
    }
};

int main()
{
    String s1, s2, s3("");
    s1.display();
    s2.display();
    s3 = join(s1, s2);
    s3.display();
    return 0;
}