// 18.Implement a priority queue using
// a. A single array.
// b. A single linked list.
// c. A 2D array.
// d. Multiple single linked lists.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int priority;
    struct Node *next;
} Node;

// a. A single array.
typedef struct PriorityQueueArray
{
    int *data;
    int *priority;
    int size;
    int front;
    int rear;
} PriorityQueueArray;

PriorityQueueArray *createPriorityQueueArray(int size)
{
    PriorityQueueArray *queue = (PriorityQueueArray *)malloc(sizeof(PriorityQueueArray));
    queue->data = (int *)malloc(sizeof(int) * size);
    queue->priority = (int *)malloc(sizeof(int) * size);
    queue->size = size;
    queue->front = queue->rear = -1;
    return queue;
}

int isFullPriorityQueueArray(PriorityQueueArray *queue)
{
    return (queue->rear + 1) % queue->size == queue->front;
}

int isEmptyPriorityQueueArray(PriorityQueueArray *queue)
{
    return queue->front == -1;
}

void enqueuePriorityQueueArray(PriorityQueueArray *queue, int data, int priority)
{
    if (isFullPriorityQueueArray(queue))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmptyPriorityQueueArray(queue))
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->size;
    }
    queue->data[queue->rear] = data;
    queue->priority[queue->rear] = priority;
}

int dequeuePriorityQueueArray(PriorityQueueArray *queue)
{
    if (isEmptyPriorityQueueArray(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int index = queue->front;
    for (int i = queue->front + 1; i != queue->rear; i = (i + 1) % queue->size)
    {
        if (queue->priority[i] < queue->priority[index])
        {
            index = i;
        }
    }
    int value = queue->data[index];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->size;
    }
    return value;
}

void printPriorityQueueArray(PriorityQueueArray *queue)
{
    if (isEmptyPriorityQueueArray(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->size)
    {
        printf("%d ", queue->data[i]);
    }
    printf("%d\n", queue->data[queue->rear]);
}

// b. A single linked list.
typedef struct PriorityQueueLinkedList
{
    Node *front;
    Node *rear;
} PriorityQueueLinkedList;

PriorityQueueLinkedList *createPriorityQueueLinkedList()
{
    PriorityQueueLinkedList *queue = (PriorityQueueLinkedList *)malloc(sizeof(PriorityQueueLinkedList));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmptyPriorityQueueLinkedList(PriorityQueueLinkedList *queue)
{
    return queue->front == NULL;
}

void enqueuePriorityQueueLinkedList(PriorityQueueLinkedList *queue, int data, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    if (isEmptyPriorityQueueLinkedList(queue))
    {
        queue->front = queue->rear = newNode;
        return;
    }
    if (priority < queue->front->priority)
    {
        newNode->next = queue->front;
        queue->front = newNode;
        return;
    }
    if (priority > queue->rear->priority)
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
        return;
    }
    Node *temp = queue->front;
    while (temp->next != NULL && temp->next->priority < priority)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int dequeuePriorityQueueLinkedList(PriorityQueueLinkedList *queue)
{
    if (isEmptyPriorityQueueLinkedList(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->front->data;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    return value;
}

void printPriorityQueueLinkedList(PriorityQueueLinkedList *queue)
{
    if (isEmptyPriorityQueueLinkedList(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = queue->front;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

// c. A 2D array.
// having 2 rows and n columns
// 1st row for data
// 2nd row for priority

typedef struct PriorityQueue2DArray
{
    int **data;
    int size;
    int front;
    int rear;
} PriorityQueue2DArray;

PriorityQueue2DArray *createPriorityQueue2DArray(int size)
{
    PriorityQueue2DArray *queue = (PriorityQueue2DArray *)malloc(sizeof(PriorityQueue2DArray));
    queue->data = (int **)malloc(sizeof(int *) * 2);
    queue->data[0] = (int *)malloc(sizeof(int) * size);
    queue->data[1] = (int *)malloc(sizeof(int) * size);
    queue->size = size;
    queue->front = queue->rear = -1;
    return queue;
}

int isFullPriorityQueue2DArray(PriorityQueue2DArray *queue)
{
    return (queue->rear + 1) % queue->size == queue->front;
}

int isEmptyPriorityQueue2DArray(PriorityQueue2DArray *queue)
{
    return queue->front == -1;
}

void enqueuePriorityQueue2DArray(PriorityQueue2DArray *queue, int data, int priority)
{
    if (isFullPriorityQueue2DArray(queue))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmptyPriorityQueue2DArray(queue))
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->size;
    }
    queue->data[0][queue->rear] = data;
    queue->data[1][queue->rear] = priority;
}

int dequeuePriorityQueue2DArray(PriorityQueue2DArray *queue)
{
    if (isEmptyPriorityQueue2DArray(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int index = queue->front;
    for (int i = queue->front + 1; i != queue->rear; i = (i + 1) % queue->size)
    {
        if (queue->data[1][i] < queue->data[1][index])
        {
            index = i;
        }
    }
    int value = queue->data[0][index];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->size;
    }
    return value;
}

void printPriorityQueue2DArray(PriorityQueue2DArray *queue)
{
    if (isEmptyPriorityQueue2DArray(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->size)
    {
        printf("%d ", queue->data[0][i]);
    }
    printf("%d\n", queue->data[0][queue->rear]);
}

// d. multiple linked list.
// 2 linked list 1 for data and 1 for priority

typedef struct PriorityQueueMultipleLinkedList
{
    Node *data;
    Node *priority;
} PriorityQueueMultipleLinkedList;

PriorityQueueMultipleLinkedList *createPriorityQueueMultipleLinkedList()
{
    PriorityQueueMultipleLinkedList *queue = (PriorityQueueMultipleLinkedList *)malloc(sizeof(PriorityQueueMultipleLinkedList));
    queue->data = queue->priority = NULL;
    return queue;
}

int isEmptyPriorityQueueMultipleLinkedList(PriorityQueueMultipleLinkedList *queue)
{
    return queue->data == NULL;
}

void enqueuePriorityQueueMultipleLinkedList(PriorityQueueMultipleLinkedList *queue, int data, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmptyPriorityQueueMultipleLinkedList(queue))
    {
        queue->data = queue->priority = newNode;
        return;
    }
    if (priority < queue->priority->data)
    {
        newNode->next = queue->data;
        queue->data = newNode;
        return;
    }
    if (priority > queue->priority->data)
    {
        queue->priority->next = newNode;
        queue->priority = newNode;
        return;
    }
    Node *temp = queue->data;
    while (temp->next != NULL && temp->next->data < priority)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int dequeuePriorityQueueMultipleLinkedList(PriorityQueueMultipleLinkedList *queue)
{
    if (isEmptyPriorityQueueMultipleLinkedList(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->data->data;
    Node *temp = queue->data;
    queue->data = queue->data->next;
    free(temp);
    if (queue->data == NULL)
    {
        queue->priority = NULL;
    }
    return value;
}

void printPriorityQueueMultipleLinkedList(PriorityQueueMultipleLinkedList *queue)
{
    if (isEmptyPriorityQueueMultipleLinkedList(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = queue->data;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main()
{
    // a. An array.
    PriorityQueueArray *queueArray = createPriorityQueueArray(5);
    enqueuePriorityQueueArray(queueArray, 1, 1);
    enqueuePriorityQueueArray(queueArray, 2, 2);
    enqueuePriorityQueueArray(queueArray, 3, 3);
    enqueuePriorityQueueArray(queueArray, 4, 4);
    enqueuePriorityQueueArray(queueArray, 5, 5);
    printPriorityQueueArray(queueArray);
    printf("%d\n", dequeuePriorityQueueArray(queueArray));
    printf("%d\n", dequeuePriorityQueueArray(queueArray));

    // b. A linked list.
    PriorityQueueLinkedList *queueLinkedList = createPriorityQueueLinkedList();
    enqueuePriorityQueueLinkedList(queueLinkedList, 1, 1);
    enqueuePriorityQueueLinkedList(queueLinkedList, 2, 2);
    enqueuePriorityQueueLinkedList(queueLinkedList, 3, 3);
    enqueuePriorityQueueLinkedList(queueLinkedList, 4, 4);
    enqueuePriorityQueueLinkedList(queueLinkedList, 5, 5);
    printPriorityQueueLinkedList(queueLinkedList);
    printf("%d\n", dequeuePriorityQueueLinkedList(queueLinkedList));
    printf("%d\n", dequeuePriorityQueueLinkedList(queueLinkedList));

    // c. A 2D array.
    PriorityQueue2DArray *queue2DArray = createPriorityQueue2DArray(5);
    enqueuePriorityQueue2DArray(queue2DArray, 1, 1);
    enqueuePriorityQueue2DArray(queue2DArray, 2, 2);
    enqueuePriorityQueue2DArray(queue2DArray, 3, 3);
    enqueuePriorityQueue2DArray(queue2DArray, 4, 4);
    enqueuePriorityQueue2DArray(queue2DArray, 5, 5);
    printPriorityQueue2DArray(queue2DArray);
    printf("%d\n", dequeuePriorityQueue2DArray(queue2DArray));
    printf("%d\n", dequeuePriorityQueue2DArray(queue2DArray));

    // d. multiple linked list.
    PriorityQueueMultipleLinkedList *queueMultipleLinkedList = createPriorityQueueMultipleLinkedList();
    enqueuePriorityQueueMultipleLinkedList(queueMultipleLinkedList, 1, 1);
    enqueuePriorityQueueMultipleLinkedList(queueMultipleLinkedList, 2, 2);
    enqueuePriorityQueueMultipleLinkedList(queueMultipleLinkedList, 3, 3);
    enqueuePriorityQueueMultipleLinkedList(queueMultipleLinkedList, 4, 4);
    enqueuePriorityQueueMultipleLinkedList(queueMultipleLinkedList, 5, 5);
    printPriorityQueueMultipleLinkedList(queueMultipleLinkedList);
    printf("%d\n", dequeuePriorityQueueMultipleLinkedList(queueMultipleLinkedList));
    printf("%d\n", dequeuePriorityQueueMultipleLinkedList(queueMultipleLinkedList));
    return 0;
}
