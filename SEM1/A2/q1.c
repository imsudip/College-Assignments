// 1) Write a function to take one n elements 1-D integer array and find the third maximum,
// the fifth minimum & the middle element of the array (in any order). Special credit will be
// given if you can do it without sorting the array.

#include <stdio.h>

int find3rdMax(int arr[], int n)
{
    int max1 = arr[0], max2 = arr[0], max3 = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2)
        {
            max3 = max2;
            max2 = arr[i];
        }
        else if (arr[i] > max3)
        {
            max3 = arr[i];
        }
    }
    return max3;
}

int find5thMin(int arr[], int n)
{
    int min1 = arr[0], min2 = arr[0], min3 = arr[0], min4 = arr[0], min5 = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min1)
        {
            min5 = min4;
            min4 = min3;
            min3 = min2;
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2)
        {
            min5 = min4;
            min4 = min3;
            min3 = min2;
            min2 = arr[i];
        }
        else if (arr[i] < min3)
        {
            min5 = min4;
            min4 = min3;
            min3 = arr[i];
        }
        else if (arr[i] < min4)
        {
            min5 = min4;
            min4 = arr[i];
        }
        else if (arr[i] < min5)
        {
            min5 = arr[i];
        }
    }
    return min5;
}

int findMiddle(int arr[], int n)
{
    return arr[n / 2];
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The third maximum is: %d\n", find3rdMax(arr, n));
    printf("The fifth minimum is: %d\n", find5thMin(arr, n));
    printf("The middle element is: %d\n", findMiddle(arr, n));
    return 0;
}