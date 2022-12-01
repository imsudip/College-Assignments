// 12) Write a program to create a linked list of n integers. Write a menu driven program to do
// the following
// a) Insert a new node
// b) Delete a node specified by the user
// c) Print the list
// d) Search for an element in the list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete (int data)
{
    int isPresent = search(data);
    if (isPresent == 0)
    {
        printf("The element is not present in the list.\n");
        return;
    }
    struct node *temp = head;
    if (temp->data == data)
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        while (temp->next->data != data)
        {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

void print()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        if (temp != NULL)
            printf("-> ");
    }
    printf("\n");
}

int search(int data)
{
    struct node *temp = head;
    int location = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
            return location;
        temp = temp->next;
        location++;
    }
    return 0;
}

int main()
{
    int n, i, data, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        insert(data);
    }
    printf("The list is: ");
    print();
    do
    {
        printf("1. Insert a new node\n");
        printf("2. Delete a node specified by the user\n");
        printf("3. Print the list\n");
        printf("4. Search for an element in the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            insert(data);
            printf("The list is: ");
            print();
            break;
        case 2:
            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            delete (data);
            printf("The list is: ");
            print();
            break;
        case 3:
            printf("The list is: ");
            print();
            break;
        case 4:
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            n = search(data);
            if (n)
                printf("The element is present at location %d.\n", n);
            else
                printf("The element is not present in the list.\n");
            break;
        case 5:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}