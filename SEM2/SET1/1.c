// Write a menu-driven program in C to perform the following operations in
// an integer array allocated memory dynamically. The list may grow or
// shrink compared to the initial allocation as and when required. Multiple
// operations may be performed on the existing list without recompiling/reexecuting the program. The individual operation should be implemented
// using a single function.
// List of operations:
// a) Create
// b) Display the entire list
// c) Count (total number of elements in the list)
// d) Reverse the list (reversed list should be stored in the same array)
// e) Index of a given element (all indices if there are duplicate entries)
// f) Indexed element
// g) Insert
// h) Delete
// i) Merge
// j) Split
// k) Sort
// l) Search

#include <stdio.h>
#include <stdlib.h>

int size = 0;

void create(int *arr)
{
    // create a single element array
    arr = (int *)malloc(sizeof(int));
    size = 1;
    printf("Enter the element: ");
    scanf("%d", arr);
}

void display(int *arr)
{
    // display the entire array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void insert(int *arr)
{
    // insert an element at the end of the array
    arr = (int *)realloc(arr, (size + 1) * sizeof(int));
    printf("Enter the element: ");
    scanf("%d", &arr[size]);
    size++;
}

void delete(int *arr)
{
    // delete an element from the array
    int index;
    printf("Enter the index of the element to be deleted: ");
    scanf("%d", &index);
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr = (int *)realloc(arr, (size - 1) * sizeof(int));
    size--;
}

void count()
{
    // count the number of elements in the array
    printf("The number of elements in the array is %d\n", size);
}

void reverse(int *arr)
{
    // reverse the array
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void indices(int *arr)
{
    // print the indices of a given element
    int element;
    printf("Enter the element: ");
    scanf("%d", &element);
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("%d ", i);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Element not found\n");
    }
    printf("\n");
}

void indexed(int *arr)
{
    // print the element at a given index
    int index;
    printf("Enter the index: ");
    scanf("%d", &index);
    if (index < size)
    {
        printf("%d\n", arr[index]);
    }
    else
    {
        printf("Index out of bounds\n");
    }
}

void split(int *arr, int *arr2, int size2)
{
    // split the array into two arrays
    int index;
    printf("Enter the index: ");
    scanf("%d", &index);
    if (index < size)
    {
        size2 = size - index;
        arr2 = (int *)malloc((size - index) * sizeof(int));
        for (int i = index; i < size; i++)
        {
            arr2[i - index] = arr[i];
        }
        arr = (int *)realloc(arr, index * sizeof(int));
        size = index;
    }
    else
    {
        printf("Index out of bounds\n");
    }
}

void merge(int *arr, int *arr2, int size2)
{
    // merge two arrays
    arr = (int *)realloc(arr, (size + size2) * sizeof(int));
    for (int i = 0; i < size2; i++)
    {
        arr[size + i] = arr2[i];
    }
    size += size2;
}

void sort(int *arr)
{
    // sort the array
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
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

void search(int *arr)
{
    // search for an element in the array
    int element;
    printf("Enter the element: ");
    scanf("%d", &element);
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("Element found at index %d\n", i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Element not found\n");
    }
}

int main()
{
    int *arr = NULL, *arr2;
    int size2 = 0;
    int choice;
    while (1)
    {
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Count\n");
        printf("6. Reverse\n");
        printf("7. Indices\n");
        printf("8. Indexed\n");
        printf("9. Split\n");
        printf("10. Merge\n");
        printf("11. Sort\n");
        printf("12. Search\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create(arr);
            break;
        case 2:
            display(arr);
            break;
        case 3:
            insert(arr);
            break;
        case 4:
            delete (arr);
            break;
        case 5:
            count();
            break;
        case 6:
            reverse(arr);
            break;
        case 7:
            indices(arr);
            break;
        case 8:
            indexed(arr);
            break;
        case 9:
            split(arr, arr2, size2);
            break;
        case 10:
            merge(arr, arr2, size2);
            break;
        case 11:
            sort(arr);
            break;
        case 12:
            search(arr);
            break;
        case 13:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
