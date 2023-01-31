#include <iostream>
using namespace std;
const int MAX_SIZE = 1000;
class Exception
{
    const char *err;

public:
    Exception(const char *a)
    {
        err = a;
    }
    void display()
    {
        cout << err << endl;
    }
};

template <class T>
class Stack
{
private:
    T *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        arr = new T[MAX_SIZE];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void isEmpty()
    {
        if (top == -1)
        {
            throw Exception("Error: stack is empty");
        }
    }

    void isFull()
    {
        if (top == MAX_SIZE - 1)
        {
            throw Exception("Error: stack overflow");
        }
    }

    void push(T value)
    {
        isFull();
        top++;
        arr[top] = value;
    }

    T pop()
    {
        isEmpty();
        T value = arr[top];
        top--;
        return value;
    }

    T peek()
    {
        isEmpty();
        return arr[top];
    }

    void display()
    {
        isEmpty();
        cout << "Stack contents: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i];
            if (i != 0)
            {
                cout << "->";
            }
        }
        cout << endl;
    }

    void display(int depth)
    {
        isEmpty();
        cout << "value at depth " << depth << ": " << arr[top - depth] << endl;
    }
};
template <class T>
class MinStack : public Stack<T>
{
public:
    MinStack() : Stack<T>() {}
    void push(T value)
    {
        try
        {
            Stack<T>::isEmpty();
            T min = Stack<T>::peek();
            if (value < min)
            {
                Stack<T>::push(value);
            }
            else
            {
                cout << "Error: value is greater than top element" << endl;
            }
        }
        catch (Exception e)
        {
            Stack<T>::push(value);
            return;
        }
    }
};

class myDate
{
private:
    int dd, mm, yy;

public:
    myDate()
    {
        dd = 01;
        mm = 01;
        yy = 70;
    }

    friend ostream &operator<<(ostream &out, myDate &m)
    {
        out << m.dd << "/" << m.mm << "/" << m.yy;
        return out;
    }

    friend istream &operator>>(istream &in, myDate &m)
    {
        cout << "(enter in format(dd/mm/yy))";
        in >> m.dd;
        in.ignore();
        in >> m.mm;
        in.ignore();
        in >> m.yy;
        return in;
    }

    bool operator<(myDate &m)
    {
        if (yy < m.yy)
        {
            return true;
        }
        else if (yy == m.yy)
        {
            if (mm < m.mm)
            {
                return true;
            }
            else if (mm == m.mm)
            {
                if (dd < m.dd)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class height
{
private:
    int feet;
    int inches;

public:
    height()
    {
        feet = 0;
        inches = 0;
    }

    friend ostream &operator<<(ostream &out, height &h)
    {
        out << h.feet << " feet " << h.inches << " inches";
        return out;
    }

    friend istream &operator>>(istream &in, height &h)
    {
        cout << "(enter in format(feet inches))";
        in >> h.feet;
        in >> h.inches;
        return in;
    }

    bool operator<(height &h)
    {
        if (feet < h.feet)
        {
            return true;
        }
        else if (feet == h.feet)
        {
            if (inches < h.inches)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    // MinStack<myDate> s;
    MinStack<height> s;
    int choice, depth;
    height n;
    do
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Display at depth" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        try
        {
            switch (choice)
            {
            case 1:
                cout << "Enter the value to push: ";
                cin >> n;
                s.push(n);
                break;
            case 2:

                n = s.pop();
                cout << "Popped value: " << n << endl;

                break;
            case 3:
                n = s.peek();
                cout << "Peeked value: " << n << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Enter the depth: ";
                cin >> depth;
                s.display(depth);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
            }
        }
        catch (Exception e)
        {
            e.display();
        }
    } while (choice != 6);
    return 0;
}