#include <stdio.h>
#include <stdlib.h>

void create(int **arr, int *size);
void display(int *arr, int size);
int count(int size);
void reverse(int *arr, int size);
void index_of(int *arr, int size, int value);
void indexed_element(int *arr, int size, int index);
void insert(int **arr, int *size, int value);
void delete(int **arr, int *size, int index);
void merge(int **arr1, int *size1, int *arr2, int size2);
void split(int **arr1, int *size1, int **arr2, int *size2, int index);
void sort(int *arr, int size);
void search(int *arr, int size, int value);

int main()
{
    int *arr = NULL, *arr2 = NULL;
    int size = 0, size2 = 0;
    int choice = 0;

    while (1)
    {
        printf("---- MENU ----\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Reverse\n");
        printf("5. Index of\n");
        printf("6. Indexed element\n");
        printf("7. Insert\n");
        printf("8. Delete\n");
        printf("9. Merge\n");
        printf("10. Split\n");
        printf("11. Sort\n");
        printf("12. Search\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create(&arr, &size);
            break;

        case 2:
            display(arr, size);
            break;

        case 3:
            printf("Total number of elements in the list: %d\n", count(size));
            break;

        case 4:
            reverse(arr, size);
            break;

        case 5:
            printf("Enter the value to find: ");
            int value;
            scanf("%d", &value);
            index_of(arr, size, value);
            break;

        case 6:
            printf("Enter the index of the element: ");
            int index;
            scanf("%d", &index);
            indexed_element(arr, size, index);
            break;

        case 7:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert(&arr, &size, value);
            break;

        case 8:
            printf("Enter the index to delete: ");
            scanf("%d", &index);
            delete (&arr, &size, index);
            break;

        case 9:

            merge(&arr, &size, arr2, size2);
            printf("Array merged.\n");
            display(arr, size);
            free(arr2);
            break;

        case 10:
            printf("Enter the index to split at: ");
            scanf("%d", &index);
            split(&arr, &size, &arr2, &size2, index);
            printf("First array:\n");
            display(arr, size);
            printf("Second array:\n");
            display(arr2, size2);
            break;

        case 11:
            sort(arr, size);
            printf("Array sorted in ascending order.\n");
            break;

        case 12:
            printf("Enter the value to search for: ");
            scanf("%d", &value);
            search(arr, size, value);
            break;

        case 0:
            printf("Exiting...\n");
            free(arr);
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void create(int **arr, int *size)
{
    *size = 1;
    *arr = (int *)malloc(*size * sizeof(int));
    printf("Enter the element: \n");
    scanf("%d", *arr);
}

void display(int *arr, int size)
{
    printf("Array elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int count(int size)
{
    return size;
}

void reverse(int *arr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("Array reversed.\n");
}

void index_of(int *arr, int size, int value)
{
    printf("Indices of %d: ", value);
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            printf("%d ", i);
            count++;
        }
    }
    if (count == 0)
    {
        printf("None");
    }
    printf("\n");
}

void indexed_element(int *arr, int size, int index)
{
    if (index >= 0 && index < size)
    {
        printf("Element at index %d: %d\n", index, arr[index]);
    }
    else
    {
        printf("Invalid index!\n");
    }
}

void insert(int **arr, int *size, int value)
{

    *size += 1;
    *arr = (int *)realloc(*arr, *size * sizeof(int));
    (*arr)[*size - 1] = value;
    printf("Element inserted.\n");
}
void delete(int **arr, int *size, int index)
{
    if (index >= 0 && index < *size)
    {
        for (int i = index; i < *size - 1; i++)
        {
            (*arr)[i] = (*arr)[i + 1];
        }
        *size -= 1;
        *arr = (int *)realloc(*arr, *size * sizeof(int));
        printf("Element deleted.\n");
    }
    else
    {
        printf("Invalid index!\n");
    }
}
void merge(int **arr1, int *size1, int *arr2, int size2)
{
    int newSize = *size1 + size2;
    *arr1 = (int *)realloc(*arr1, newSize * sizeof(int));
    for (int i = 0; i < size2; i++)
    {
        (*arr1)[*size1 + i] = arr2[i];
    }
    *size1 = newSize;
    printf("Arrays merged.\n");
}

void split(int **arr1, int *size1, int **arr2, int *size2, int index)
{
    *size2 = *size1 - index;
    *arr2 = (int *)malloc(*size2 * sizeof(int));
    for (int i = 0; i < *size2; i++)
    {
        (*arr2)[i] = (*arr1)[index + i];
    }
    *size1 = index;
    *arr1 = (int *)realloc(*arr1, *size1 * sizeof(int));
}

void sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void search(int *arr, int size, int value)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        printf("Value %d found at index %d.\n", value, index);
    }
    else
    {
        printf("Value not found.\n");
    }
}
