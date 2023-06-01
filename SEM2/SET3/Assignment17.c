#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Deque;

void initDeque(Deque* dq) {
    dq->front = NULL;
    dq->rear = NULL;
}

bool isEmpty(Deque* dq) {
    return dq->front == NULL;
}

Node* createNode(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFront(Deque* dq, int item) {
    Node* newNode = createNode(item);

    if (isEmpty(dq)) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

void insertRear(Deque* dq, int item) {
    Node* newNode = createNode(item);

    if (isEmpty(dq)) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

int deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return -1;
    }

    Node* temp = dq->front;
    int item = temp->data;

    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    free(temp);
    return item;
}

int deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return -1;
    }

    Node* temp = dq->rear;
    int item = temp->data;

    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }

    free(temp);
    return item;
}

void printDeque(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    Node* current = dq->front;
    printf("Deque: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    // Insert elements at the front
    insertFront(&dq, 10);
    insertFront(&dq, 20);
    insertFront(&dq, 30);

    // Insert elements at the rear
    insertRear(&dq, 40);
    insertRear(&dq, 50);

    printf("Deque after insertions:\n");
    printDeque(&dq);

    // Delete elements from the front and rear
    int frontDeleted = deleteFront(&dq);
    int rearDeleted = deleteRear(&dq);

    printf("Deleted front element: %d\n", frontDeleted);
    printf("Deleted rear element: %d\n", rearDeleted);

    printf("Deque after deletions:\n");
    printDeque(&dq);

    return 0;
}
