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

void replace(Queue* p, int e, int x) {
    Queue temp;
    initQueue(&temp);

    while (!isEmpty(p)) {
        int item = dequeue(p);
        if (item == e)
            item = x;

        enqueue(&temp, item);
    }

    while (!isEmpty(&temp))
        enqueue(p, dequeue(&temp));
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
    enqueue(&q, 20);
    enqueue(&q, 40);

    printf("Before replacing:\n");
    printQueue(&q);

    // Replace occurrences of element 20 with 50
    replace(&q, 20, 50);

    printf("After replacing:\n");
    printQueue(&q);

    return 0;
}
