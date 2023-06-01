// 15.Write a program for dynamic implementation (using a link list) of a
// queue of the above.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->front == NULL;
}

void enqueue(Queue *queue, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    if (isEmpty(queue))
    {
        queue->front = node;
        queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return value;
}

void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = queue->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Queue *queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}