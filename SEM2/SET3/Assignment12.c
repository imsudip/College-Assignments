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

bool isEqualQueues(Queue* q1, Queue* q2) {
    if (isEmpty(q1) && isEmpty(q2))
        return true;

    if (q1->front != q2->front || q1->rear != q2->rear)
        return false;

    int i = q1->front;
    int j = q2->front;

    while (i != q1->rear) {
        if (q1->data[i] != q2->data[j])
            return false;

        i = (i + 1) % MAX_SIZE;
        j = (j + 1) % MAX_SIZE;
    }

    return q1->data[i] == q2->data[j];
}

int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    // Enqueue some elements into q1
    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);

    // Enqueue the same elements into q2
    enqueue(&q2, 10);
    enqueue(&q2, 20);
    enqueue(&q2, 30);

    // Check if the queues are equal
    bool result = isEqualQueues(&q1, &q2);
    printf("Are the queues equal? %s\n", result ? "Yes" : "No");

    return 0;
}
