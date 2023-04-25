#include <stdio.h>
#include <stdlib.h>
int size = 0;
int *create_arr();
void insert_ele(int *ptr);
void display(int *ptr);
void count_ele();
void reverse_arr(int *ptr);
void indices_print(int *ptr);
void indexed_ele(int *ptr);
void delete_ele(int *ptr);
void sort_arr(int *ptr);
void sort_arr(int *ptr);
void search_ele(int *ptr);
void merge_arr();
void split_arr();
int main()
{
    int choice;
    int *addr = NULL;
    while (1)
    {
        printf("\n1.Create\n2.Display entire array\n3.Count\n4.Reverse list\n5.Index of a given element\n6.Indexed element\n7.Insert\n8.Delete\n9.Merge\n10.Split\n11.Sort\n12.Search array element\n13.Exit\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addr = create_arr();
            break;
        case 2:
            display(addr);
            break;
        case 3:
            count_ele();
            break;
        case 4:
            reverse_arr(addr);
            break;
        case 5:
            indices_print(addr);
            break;
        case 6:
            indexed_ele(addr);
            break;
        case 7:
            insert_ele(addr);
            break;
        case 8:
            delete_ele(addr);
            break;
        case 9:
            merge_arr();
            break;
        case 10:
            split_arr();
            break;
        case 11:
            sort_arr(addr);
            break;
        case 12:
            search_ele(addr);
            break;
        case 13:
            exit(0);
            break;
        default:
            printf("Invalid input!\n");
        }
    }
    return 0;
}
int *create_arr()
{
    size++;
    int *ptr = (int *)malloc(sizeof(int));
    printf("Enter the element: ");
    scanf("%d", ptr);
    printf("Array is created successfully!\n");
    return ptr;
}
void insert_ele(int *ptr)
{

    ptr = (int *)realloc(ptr, size);
    printf("Enter the element:");
    scanf("%d", (ptr + size));
    size++;
}
void display(int *ptr)
{
    int i;
    if (ptr == NULL)
    {
        printf("You have to create the array first!\n");
    }
    else
    {
        printf("The elements are:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", *(ptr + i));
        }
        printf("\n");
    }
}
void count_ele()
{
    printf("The total no of elements are: %d\n", size);
}
void reverse_arr(int *ptr)
{
    int temp, i = 0, j = size - 1;
    while (i <= j)
    {
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + j);
        *(ptr + j) = temp;
        i++;
        j--;
    }
}
void indices_print(int *ptr)
{
    int ele, i, flag = 0;
    printf("Enter the element:");
    scanf("%d", &ele);
    printf("The indices of element %d :\n", ele);
    for (i = 0; i < size; i++)
    {
        if (ele == *(ptr + i))
        {
            printf("%d ", i);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("Element is not in array!\n");
    printf("\n");
}
void delete_ele(int *ptr)
{
    int ele, i;
    printf("Enter the element to delete: ");
    scanf("%d", &ele);
    for (i = 0; i < size; i++)
    {
        if (ele == *(ptr + i))
            break;
    }
    if (i == size)
        printf("The element is not present in the array!\n");
    else
    {
        for (; i < size - 1; i++)
        {
            *(ptr + i) = *(ptr + i + 1);
        }
        printf("Element deleted successfully!\n");
        size--;
    }
}
void sort_arr(int *ptr)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (*(ptr + i) > *(ptr + j))
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}
void search_ele(int *ptr)
{
    int ele, i, flag = 0;
    printf("Enter the element to search:");
    scanf("%d", &ele);
    for (i = 0; i < size; i++)
    {
        if (ele == *(ptr + i))
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Element is not found!\n");
    else
    {
        printf("The element %d is present at % index in array\n", ele, i);
    }
}
void indexed_ele(int *ptr)
{
    int index, i, flag = 0;
    printf("Enter the index: ");
    scanf("%d", &index);
    if (index < 0 || index >= size)
        printf("Index is not valid!");
    else
    {
        for (i = 0; i < size; i++)
        {
            if (i == index)
            {
                printf("The element at % index is: %d\n", index, *(ptr + i));
                break;
            }
        }
    }
}
void merge_arr()
{
}
void split_arr()
{
}