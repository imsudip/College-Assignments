// 12.A Boolean function to return true if two eq(q1, q2) are equal.

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

int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->data[queue->front];
}

int isEqual(Queue *q1, Queue *q2)
{
    if (q1->size != q2->size)
    {
        return 0;
    }
    if (q1->front != q2->front)
    {
        return 0;
    }
    if (q1->rear != q2->rear)
    {
        return 0;
    }
    for (int i = 0; i < q1->size; i++)
    {
        if (q1->data[i] != q2->data[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    Queue *q1 = createQueue(5);
    Queue *q2 = createQueue(5);
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    enqueue(q2, 1);
    enqueue(q2, 2);
    enqueue(q2, 3);
    printf("%d\n", isEqual(q1, q2));
    return 0;
}