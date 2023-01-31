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
    const char *name;

public:
    Stack()
    {
        top = -1;
        arr = new int[MAX_SIZE];
    }

    Stack(int size, const char *name)
    {
        top = -1;
        arr = new int[size];
        this->name = name;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void isEmpty()
    {
        if (top == -1)
        {
            throw Exception("Stack is empty");
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
        cout << "Stack contents of " << name << ": ";
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

    const char *getName()
    {
        return name;
    }
};

class MinStack : public Stack
{
public:
    MinStack() : Stack() {}
    MinStack(int size, const char *name) : Stack(size, name) {}
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

void toh(int n, MinStack *source, MinStack *destination, MinStack *auxiliary)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " from " << source->getName() << " to " << destination->getName() << endl;
        destination->push(source->pop());
        return;
    }
    toh(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source->getName() << " to " << destination->getName() << endl;
    destination->push(source->pop());
    toh(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    MinStack *source = new MinStack(n, "A");
    MinStack *destination = new MinStack(n, "B");
    MinStack *auxiliary = new MinStack(n, "C");
    for (int i = n; i > 0; i--)
    {
        source->push(i);
    }
    source->display();
    toh(n, source, destination, auxiliary);
    destination->display();
    return 0;
}