// Write a C++ program to create a class ‘Number_List’, which has separate member
// functions to create an integer array at run time, to sort given Integer and to find the
// minimum and maximum of the array

#include <iostream>
using namespace std;

class Number_List
{
private:
    int *arr;
    int size;

public:
    void createArray()
    {
        cout << "Enter size of array: ";
        cin >> size;
        arr = new int[size];
        cout << "Enter elements of array: ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    void sortArray()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    void printArray()
    {
        cout << "Sorted array is: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void minMax()
    {
        cout << "Minimum element of array is: " << arr[0] << endl;
        cout << "Maximum element of array is: " << arr[size - 1] << endl;
    }
};

int main()
{
    Number_List n;
    n.createArray();
    n.sortArray();
    n.printArray();
    n.minMax();
    return 0;
}