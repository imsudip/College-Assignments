// 14.Procedure replace(p, e, x) to replace every occurrence of element e in
// queue p with the value of x.

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUES 3

typedef struct
{
    int *data;
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (int *)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->front == -1;
}

int isFull(Queue *queue)
{
    return queue->rear == queue->size - 1;
}

void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }
    queue->data[++queue->rear] = value;
    if (queue->front == -1)
    {
        queue->front = 0;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    return value;
}

void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

void replace(Queue *queue, int e, int x)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    Queue *temp = createQueue(queue->size);
    while (!isEmpty(queue))
    {
        int value = dequeue(queue);
        if (value == e)
        {
            enqueue(temp, x);
        }
        else
        {
            enqueue(temp, value);
        }
    }
    while (!isEmpty(temp))
    {
        enqueue(queue, dequeue(temp));
    }
}

int main()
{
    Queue *queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 2);
    enqueue(queue, 4);
    printQueue(queue);
    replace(queue, 2, 5);
    printQueue(queue);
    return 0;
}