// Write a function to take two 2-D arrays, sort those two arrays, then merge them into a
// third array that will also be sorted.

#include <stdio.h>

void sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void merge(int arr1[], int arr2[], int arr3[], int n1, int n2)
{
    int i, j, k;
    i = j = k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}

void printMatrix(int arr[], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", arr[i * col + j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr1[100], arr2[100], arr3[100];
    int order, i;
    printf("Enter the order of the matrices: ");
    scanf("%d", &order);
    printf("Enter the elements of the first matrix: ");
    for (i = 0; i < order * order; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the elements of the second matrix: ");
    for (i = 0; i < order * order; i++)
    {
        scanf("%d", &arr2[i]);
    }
    sort(arr1, order * order);
    printf("Sorted matrix 1: \n");
    printMatrix(arr1, order, order);
    sort(arr2, order * order);
    printf("Sorted matrix 2: \n");
    printMatrix(arr2, order, order);

    merge(arr1, arr2, arr3, order * order, order * order);
    printf("The order of the merged matrix is: %d x %d\n", order, order * 2);
    printf("The merged matrix is: ");
    printMatrix(arr3, order * 2, order);
    return 0;
}