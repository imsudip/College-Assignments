// 17.Implement a Deque using a doubly linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Deque
{
    Node *front;
    Node *rear;
} Deque;

Deque *createDeque()
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

int isEmpty(Deque *deque)
{
    return deque->front == NULL;
}

void insertFront(Deque *deque, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = deque->front;
    if (isEmpty(deque))
    {
        deque->front = deque->rear = newNode;
    }
    else
    {
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void insertRear(Deque *deque, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = deque->rear;
    newNode->next = NULL;
    if (isEmpty(deque))
    {
        deque->front = deque->rear = newNode;
    }
    else
    {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int deleteFront(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty\n");
        return -1;
    }
    int value = deque->front->data;
    Node *temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front == NULL)
    {
        deque->rear = NULL;
    }
    else
    {
        deque->front->prev = NULL;
    }
    free(temp);
    return value;
}

int deleteRear(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty\n");
        return -1;
    }
    int value = deque->rear->data;
    Node *temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL)
    {
        deque->front = NULL;
    }
    else
    {
        deque->rear->next = NULL;
    }
    free(temp);
    return value;
}

void printDeque(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty\n");
        return;
    }
    Node *temp = deque->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Deque *deque = createDeque();
    int choice, value;
    while (1)
    {
        printf("1. Insert front\n");
        printf("2. Insert rear\n");
        printf("3. Delete front\n");
        printf("4. Delete rear\n");
        printf("5. Print deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertFront(deque, value);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertRear(deque, value);
            break;
        case 3:
            value = deleteFront(deque);
            if (value != -1)
            {
                printf("Deleted element: %d\n", value);
            }
            break;
        case 4:
            value = deleteRear(deque);
            if (value != -1)
            {
                printf("Deleted element: %d\n", value);
            }
            break;
        case 5:
            printDeque(deque);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
