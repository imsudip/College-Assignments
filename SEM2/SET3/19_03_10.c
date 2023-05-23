// 10.Implement a system that can handle multiple queues (n queues).

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

int main()
{
    // Menu driven program for queue operations
    int choice, value, queueNumber;
    Queue *queues[MAX_QUEUES];
    for (int i = 0; i < MAX_QUEUES; i++)
    {
        queues[i] = createQueue(100);
    }

    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the queue number (0-%d): ", MAX_QUEUES - 1);
            scanf("%d", &queueNumber);
            printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(queues[queueNumber], value);
            break;
        case 2:
            printf("Enter the queue number (0-%d): ", MAX_QUEUES - 1);
            scanf("%d", &queueNumber);
            value = dequeue(queues[queueNumber]);
            if (value != -1)
            {
                printf("The value dequeued is %d\n", value);
            }
            break;
        case 3:
            printf("Enter the queue number (0-%d): ", MAX_QUEUES - 1);
            scanf("%d", &queueNumber);
            value = peek(queues[queueNumber]);
            if (value != -1)
            {
                printf("The value at the front is %d\n", value);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
