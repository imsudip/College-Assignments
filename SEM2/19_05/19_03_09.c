// Write a program to implement queue data structure using an array.

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

void display(Queue *queue)
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

int main()
{
    // Menu driven program
    int choice, value;
    Queue *queue = NULL;
    while (1)
    {
        printf("1. Create queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Peek\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (queue != NULL)
            {
                printf("Queue already exists\n");
                break;
            }
            printf("Enter size of queue: ");
            scanf("%d", &value);
            queue = createQueue(value);
            printf("Queue created successfully\n");
            break;
        case 2:
            if (queue == NULL)
            {
                printf("Queue does not exist\n");
                break;
            }
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(queue, value);
            printf("Enqueued successfully\n");
            break;
        case 3:
            if (queue == NULL)
            {
                printf("Queue does not exist\n");
                break;
            }
            value = dequeue(queue);
            if (value != -1)
            {
                printf("Dequeued value: %d\n", value);
            }
            break;
        case 4:
            if (queue == NULL)
            {
                printf("Queue does not exist\n");
                break;
            }
            value = peek(queue);
            if (value != -1)
            {
                printf("Peeked value: %d\n", value);
            }
            break;
        case 5:
            if (queue == NULL)
            {
                printf("Queue does not exist\n");
                break;
            }
            display(queue);
            break;
        case 6:
            printf("Thank you\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
        printf("\n");
    }
}
