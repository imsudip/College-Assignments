#include <stdio.h>
#include <stdlib.h>

int size = 0;

void create(int **arr)
{
    *arr = (int *)malloc(sizeof(int));
    size = 1;
    printf("Enter the element: ");
    scanf("%d", *arr);
}

void display(int *arr, int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void insert(int **arr)
{
    *arr = (int *)realloc(*arr, (size + 1) * sizeof(int));
    printf("Enter the element: ");
    scanf("%d", &(*arr)[size]);
    size++;
}

void delete(int *arr)
{
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
    printf("The number of elements in the array is %d\n", size);
}

void reverse(int *arr)
{
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

void split(int **arr, int **arr2, int *size2)
{
    int index;
    printf("Enter the index: ");
    scanf("%d", &index);

    if (index < size)
    {
        *size2 = size - index;
        *arr2 = (int *)malloc(*size2 * sizeof(int));

        for (int i = index; i < size; i++)
        {
            (*arr2)[i - index] = (*arr)[i];
        }

        *arr = (int *)realloc(*arr, index * sizeof(int));

        size = index;
    }
    else
    {
        printf("Index out of bounds\n");
    }
}

void merge(int **arr, int *arr2, int size2)
{
    *arr = (int *)realloc(*arr, (size + size2) * sizeof(int));
    for (int i = 0; i < size2; i++)
    {
        (*arr)[size + i] = arr2[i];
    }
    size += size2;
}

void sort(int *arr)
{
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
            create(&arr);
            break;
        case 2:
            display(arr, size);
            break;
        case 3:
            insert(&arr);
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
            split(&arr, &arr2, &size2);
            printf("Array 1: ");
            display(arr, size);
            printf("\nArray 2: ");
            display(arr2, size2);
            break;
        case 10:

            merge(&arr, arr2, size2);
            printf("Merged Array:");
            display(arr, size);
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
