// Write a function named random partition() which will accept an 1-D array as input and
// randomly choose one of the array elements as X and partition the array into two parts
// where one part contains all elements less than X and another parts contain all elements
// greater than X. Do it without sorting the list.

#include <stdio.h>
#include <stdlib.h>

void randomPartition(int arr[], int n)
{
    int i, j, temp, x;
    x = arr[rand() % n];
    i = -1;
    j = n;
    printf("X = %d\n", x);
    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < x);
        do
        {
            j--;
        } while (arr[j] > x);
        if (i >= j)
            break;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int arr[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    randomPartition(arr, n);
    printf("The array after partitioning is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}