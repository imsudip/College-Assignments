#include <stdio.h>
#include <stdlib.h>

// Priority Queue using a single array
typedef struct {
    int data;
    int priority;
} PriorityQueueArray;

#define MAX_SIZE_ARRAY 100

PriorityQueueArray pqArray[MAX_SIZE_ARRAY];
int rearArray = -1;

void enqueueArray(int item, int priority);
int dequeueArray();
void printQueueArray();

// Priority Queue using a single linked list
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* frontList = NULL;

void enqueueList(int item, int priority);
int dequeueList();
void printQueueList();

// Priority Queue using a 2D array
typedef struct {
    int data;
    int priority;
} PriorityQueue2DArray;

#define MAX_ROWS 10
#define MAX_COLS 100

PriorityQueue2DArray pq2DArray[MAX_ROWS][MAX_COLS];
int rear2DArray[MAX_ROWS];

void enqueue2DArray(int item, int priority, int row);
int dequeue2DArray(int row);
void printQueue2DArray(int row);

// Priority Queue using multiple linked lists
typedef struct NodeMultiple {
    int data;
    int priority;
    struct NodeMultiple* next;
} NodeMultiple;

NodeMultiple* frontMultiple[5];

void enqueueMultiple(int item, int priority);
int dequeueMultiple();
void printQueueMultiple();

int main() {
    // Priority Queue using a single array
    enqueueArray(10, 3);
    enqueueArray(20, 2);
    enqueueArray(30, 1);
    enqueueArray(40, 2);

    printf("Priority Queue using a single array:\n");
    printQueueArray();

    dequeueArray();

    printf("After dequeue:\n");
    printQueueArray();

    printf("\n");

    // Priority Queue using a single linked list
    enqueueList(10, 3);
    enqueueList(20, 2);
    enqueueList(30, 1);
    enqueueList(40, 2);

    printf("Priority Queue using a single linked list:\n");
    printQueueList();

    dequeueList();

    printf("After dequeue:\n");
    printQueueList();

    printf("\n");

    // Priority Queue using a 2D array
    enqueue2DArray(10, 3, 0);
    enqueue2DArray(20, 2, 0);
    enqueue2DArray(30, 1, 1);
    enqueue2DArray(40, 2, 1);

    printf("Priority Queue using a 2D array:\n");
    printQueue2DArray(0);
    printQueue2DArray(1);

    dequeue2DArray(0);

    printf("After dequeue:\n");
    printQueue2DArray(0);

    printf("\n");

    // Priority Queue using multiple linked lists
    enqueueMultiple(10, 3);
    enqueueMultiple(20, 2);
    enqueueMultiple(30, 1);
    enqueueMultiple(40, 2);

    printf("Priority Queue using multiple linked lists:\n");
    printQueueMultiple();

    dequeueMultiple();

    printf("After dequeue:\n");
    printQueueMultiple();

    return 0;
}

// Priority Queue using a single array
void enqueueArray(int item, int priority) {
    int i;

    for (i = rearArray; i >= 0; i--) {
        if (pqArray[i].priority > priority) {
            pqArray[i + 1] = pqArray[i];
        } else {
            break;
        }
    }

    pqArray[i + 1].data = item;
    pqArray[i + 1].priority = priority;
    rearArray++;
}

int dequeueArray() {
    if (rearArray == -1) {
        printf("Priority Queue is empty.\n");
        return -1;
    }

    int item = pqArray[0].data;

    for (int i = 1; i <= rearArray; i++) {
        pqArray[i - 1] = pqArray[i];
    }

    rearArray--;

    return item;
}

void printQueueArray() {
    if (rearArray == -1) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i <= rearArray; i++) {
        printf("(%d, %d) ", pqArray[i].data, pqArray[i].priority);
    }
    printf("\n");
}

// Priority Queue using a single linked list
void enqueueList(int item, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = item;
    newNode->priority = priority;
    newNode->next = NULL;

    if (frontList == NULL || priority < frontList->priority) {
        newNode->next = frontList;
        frontList = newNode;
    } else {
        Node* current = frontList;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeueList() {
    if (frontList == NULL) {
        printf("Priority Queue is empty.\n");
        return -1;
    }

    int item = frontList->data;
    Node* temp = frontList;
    frontList = frontList->next;
    free(temp);

    return item;
}

void printQueueList() {
    if (frontList == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }

    Node* current = frontList;
    printf("Priority Queue: ");
    while (current != NULL) {
        printf("(%d, %d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

// Priority Queue using a 2D array
void enqueue2DArray(int item, int priority, int row) {
    int i;

    for (i = rear2DArray[row]; i >= 0; i--) {
        if (pq2DArray[row][i].priority > priority) {
            pq2DArray[row][i + 1] = pq2DArray[row][i];
        } else {
            break;
        }
    }

    pq2DArray[row][i + 1].data = item;
    pq2DArray[row][i + 1].priority = priority;
    rear2DArray[row]++;
}

int dequeue2DArray(int row) {
    if (rear2DArray[row] == -1) {
        printf("Priority Queue is empty.\n");
        return -1;
    }

    int item = pq2DArray[row][0].data;

    for (int i = 1; i <= rear2DArray[row]; i++) {
        pq2DArray[row][i - 1] = pq2DArray[row][i];
    }

    rear2DArray[row]--;

    return item;
}

void printQueue2DArray(int row) {
    if (rear2DArray[row] == -1) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue (Row %d): ", row);
    for (int i = 0; i <= rear2DArray[row]; i++) {
        printf("(%d, %d) ", pq2DArray[row][i].data, pq2DArray[row][i].priority);
    }
    printf("\n");
}

// Priority Queue using multiple linked lists
void enqueueMultiple(int item, int priority) {
    NodeMultiple* newNode = (NodeMultiple*)malloc(sizeof(NodeMultiple));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = item;
    newNode->priority = priority;
    newNode->next = NULL;

    int index = priority - 1;

    if (frontMultiple[index] == NULL || priority < frontMultiple[index]->priority) {
        newNode->next = frontMultiple[index];
        frontMultiple[index] = newNode;
    } else {
        NodeMultiple* current = frontMultiple[index];
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeueMultiple() {
    for (int i = 4; i >= 0; i--) {
        if (frontMultiple[i] != NULL) {
            int item = frontMultiple[i]->data;
            NodeMultiple* temp = frontMultiple[i];
            frontMultiple[i] = frontMultiple[i]->next;
            free(temp);
            return item;
        }
    }

    printf("Priority Queue is empty.\n");
    return -1;
}

void printQueueMultiple() {
    int empty = 1;
    for (int i = 4; i >= 0; i--) {
        if (frontMultiple[i] != NULL) {
            empty = 0;
            printf("Priority Queue (Priority %d): ", i + 1);
            NodeMultiple* current = frontMultiple[i];
            while (current != NULL) {
                printf("(%d, %d) ", current->data, current->priority);
                current = current->next;
            }
            printf("\n");
        }
    }

    if (empty) {
        printf("Priority Queue is empty.\n");
    }
}
