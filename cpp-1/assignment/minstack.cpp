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

class Stack
{
private:
    int *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        arr = new int[MAX_SIZE];
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

    void push(int value)
    {
        isFull();
        top++;
        arr[top] = value;
    }

    int pop()
    {
        isEmpty();
        int value = arr[top];
        top--;
        return value;
    }

    int peek()
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

class MinStack : public Stack
{
public:
    MinStack() : Stack() {}
    void push(int value)
    {
        try
        {
            Stack::isEmpty();
            int min = Stack::peek();
            if (value < min)
            {
                Stack::push(value);
            }
            else
            {
                cout << "Error: value is greater than top element" << endl;
            }
        }
        catch (Exception e)
        {
            Stack::push(value);
            return;
        }
    }
};

int main()
{
    MinStack s;
    int choice;
    int n;
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
                cin >> n;
                s.display(n);
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