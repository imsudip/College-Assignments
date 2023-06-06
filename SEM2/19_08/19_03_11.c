// 11.Append a queue x at the end of a queue y.

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

void appendQueue(Queue *queue1, Queue *queue2)
{
    if (isEmpty(queue2))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue2->front; i <= queue2->rear; i++)
    {
        enqueue(queue1, queue2->data[i]);
    }
}

int main()
{
    Queue *queue1 = createQueue(10);
    Queue *queue2 = createQueue(10);
    enqueue(queue1, 1);
    enqueue(queue1, 2);
    enqueue(queue1, 3);
    enqueue(queue2, 4);
    enqueue(queue2, 5);
    enqueue(queue2, 6);
    appendQueue(queue1, queue2);
    printQueue(queue1);
    return 0;
}