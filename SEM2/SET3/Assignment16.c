#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(CircularQueue* q) {
    return q->front == -1;
}

bool isFull(CircularQueue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(CircularQueue* q, int item) {
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

int dequeue(CircularQueue* q) {
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

void printQueue(CircularQueue* q) {
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
    CircularQueue q;
    initQueue(&q);

    // Enqueue elements into the queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Queue after enqueue:\n");
    printQueue(&q);

    // Dequeue an element
    int dequeued = dequeue(&q);
    printf("Dequeued element: %d\n", dequeued);

    printf("Queue after dequeue:\n");
    printQueue(&q);

    return 0;
}
