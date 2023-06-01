// 13.Reverse a queue.

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

void reverseQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    int *temp = (int *)malloc(sizeof(int) * queue->size);
    int i = 0;
    while (!isEmpty(queue))
    {
        temp[i++] = dequeue(queue);
    }
    for (int j = i - 1; j >= 0; j--)
    {
        enqueue(queue, temp[j]);
    }
}

int main()
{
    Queue *queue = createQueue(3);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);
    reverseQueue(queue);
    printQueue(queue);
    return 0;
}