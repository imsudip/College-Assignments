#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// circular doubly linked list
void createList(Node **head, int n)
{
    Node *temp = *head;
    for (int i = 1; i <= n; i++)
    {
        Node *newNode = createNode(i);
        if (*head == NULL)
        {
            *head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    temp->next = *head;
    (*head)->prev = temp;
}

Node *moveMNode(Node *curr, int m, int dir)
{
    if (dir == 1)
    {
        for (int i = 1; i <= m; i++)
        {
            curr = curr->next;
        }
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            curr = curr->prev;
        }
    }
    return curr;
}

int main()
{
    int n, m;
    int i, j, dir;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the number of people to skip: ");
    scanf("%d", &m);
    printf("Enter the direction (1 for clockwise, -1 for anticlockwise): ");
    scanf("%d", &dir);
    printf("Enter the starting position: ");
    scanf("%d", &i);
    Node *head = NULL;
    createList(&head, n);
    Node *temp = head;
    while (temp->data != i)
    {
        temp = temp->next;
    }

    int alive = n;
    while (alive > 1)
    {
        printf("🔫%d -->", temp->data);
        temp = moveMNode(temp, m, dir);
        Node *temp2;
        if (dir == 1)
        {
            temp2 = temp->next;
            temp->next = temp2->next;
            temp2->next->prev = temp;
        }
        else
        {
            temp2 = temp->prev;
            temp->prev = temp2->prev;
            temp2->prev->next = temp;
        }
        printf(" 💀%d\n", temp2->data);
        free(temp2);
        alive--;
        temp = moveMNode(temp, 1, dir);
    }
    printf("\nThe person who survives is: ");
    printf("%d\n", temp->data);
    return 0;
}