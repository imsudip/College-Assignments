// 16.Implement a circular queue using an array.

#include <stdio.h>
#include <stdlib.h>

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
    return (queue->rear + 1) % queue->size == queue->front;
}

void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->data[queue->rear] = value;
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
        queue->front = (queue->front + 1) % queue->size;
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
    if (queue->front <= queue->rear)
    {
        for (int i = queue->front; i <= queue->rear; i++)
        {
            printf("%d ", queue->data[i]);
        }
    }
    else
    {
        for (int i = queue->front; i < queue->size; i++)
        {
            printf("%d ", queue->data[i]);
        }
        for (int i = 0; i <= queue->rear; i++)
        {
            printf("%d ", queue->data[i]);
        }
    }
    printf("\n");
}

int main()
{
    Queue *queue = createQueue(5);
    int choice, value;
    while (1)
    {
        printf("Circular Queue size 5\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(queue, value);
            break;
        case 2:
            value = dequeue(queue);
            if (value != -1)
            {
                printf("Dequeued element: %d\n", value);
            }
            break;
        case 3:
            printQueue(queue);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
