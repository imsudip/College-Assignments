#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void createCircularList(Node **head, int n, int dir)
{
    Node *temp = *head;
    if (dir == 1)
    {
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
                temp = newNode;
            }
        }
        temp->next = *head;
    }
    else
    {
        for (int i = n; i >= 1; i--)
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
                temp = newNode;
            }
        }
        temp->next = *head;
    }
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
    createCircularList(&head, n, dir);
    // traverse the list to the starting position
    Node *temp = head;
    while (temp->data != i)
        temp = temp->next;
    int alive = n;
    printf("The order of execution is: \n");
    while (alive > 1)
    {
        printf("🔫%d -->", temp->data);
        // skip m people
        for (j = 1; j <= m; j++)
            temp = temp->next;
        // kill the mth person
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        printf("💀%d \n", temp2->data);
        free(temp2);
        alive--;
        // find the next alive person
        temp = temp->next;
    }
    printf("\nThe person who survives is: ");
    printf("%d\n", temp->data);
}