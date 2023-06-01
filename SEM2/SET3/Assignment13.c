#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

bool isFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = item;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int item = q->data[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }

    return item;
}

void reverseQueue(Queue* q) {
    if (isEmpty(q))
        return;

    int stack[MAX_SIZE];
    int top = -1;

    while (!isEmpty(q))
        stack[++top] = dequeue(q);

    while (top >= 0)
        enqueue(q, stack[top--]);
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = q->front;
    printf("Queue: ");
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->data[i]);
}

int main() {
    Queue q;
    initQueue(&q);

    // Enqueue elements into the queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Before reversing:\n");
    printQueue(&q);

    // Reverse the queue
    reverseQueue(&q);

    printf("After reversing:\n");
    printQueue(&q);

    return 0;
}
