#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

void insertAtFront(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void createLinkedList()
{
    int n, x;
    printf("enter the number nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertAtEnd(x);
    }
}

void insertAfterKthNode(int data, int k)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < k - 1; i++)
    {
        if (temp == NULL)
            return;
        temp = temp->next;
    }
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfterValue(int data, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL)
        return; // value not found in the list
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode; // if value is not the last node
    temp->next = newNode;
    newNode->prev = temp;
}

void insertBeforeKthNode(int data, int k)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL || k == 1)
    {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < k - 2; i++)
    {
        if (temp == NULL)
            return; // k is greater than the number of nodes in the list
        temp = temp->next;
    }
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode; // if k is not the last node
    temp->next = newNode;
    newNode->prev = temp;
}

void insertBeforeValue(int data, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL || head->data == value)
    {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next; // find the first node with the given value
    if (temp == NULL)
        return; // value not found in the list
    newNode->next = temp;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode;
}

void deleteFirstNode()
{
    if (head == NULL)
        return; // list is empty
    Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL; // list has more than one node
    free(temp);
}

void deleteLastNode()
{
    if (head == NULL)
        return; // list is empty
    if (head->next == NULL)
    { // list has only one node
        free(head);
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next; // find the last node
    temp->prev->next = NULL;
    free(temp);
}

void deleteAfterKthNode(int k)
{
    if (head == NULL)
        return; // list is empty
    Node *temp = head;
    for (int i = 0; i < k - 1; i++)
    {
        if (temp == NULL)
            return; // k is greater than the number of nodes in the list
        temp = temp->next;
    }
    if (temp->next == NULL)
        return; // k is the last node
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    if (temp2->next != NULL)
        temp2->next->prev = temp; // if k+1 is not the last node
    free(temp2);
}

void deleteBeforeKthNode(int k)
{
    if (head == NULL || k == 1)
        return; // list is empty or k is the first node
    if (k == 2)
    { // k is the second node
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return;
    }
    Node *temp = head;
    for (int i = 0; i < k - 3; i++)
    {
        if (temp == NULL)
            return; // k is greater than the number of nodes in the list
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next->prev = temp;
    free(temp2);
}

void deleteKthNode(int k)
{
    if (head == NULL)
        return; // list is empty
    if (k == 1)
    { // k is the first node
        Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL; // list has more than one node
        free(temp);
        return;
    }
    Node *temp = head;
    for (int i = 0; i < k - 2; i++)
    {
        if (temp == NULL)
            return; // k is greater than the number of nodes in the list
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    if (temp2->next != NULL)
        temp2->next->prev = temp; // if k is not the last node
    free(temp2);
}

void deleteValue(int value)
{
    if (head == NULL)
        return; // list is empty
    if (head->data == value)
    { // value is in the first node
        Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL; // list has more than one node
        free(temp);
        return;
    }
    Node *temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next; // find the first node with the given value
    if (temp == NULL)
        return; // value not found in the list
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev; // if value is not in the last node
    free(temp);
}

Node *reverseList()
{
    Node *temp = NULL;
    Node *current = head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    return head;
}

void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, data, k, value;
    while (1)
    {
        printf("\nDoubly Linked List Operations:\n");
        printf("0. Create LinkedList\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert after kth node\n");
        printf("4. Insert after value\n");
        printf("5. Insert before kth node\n");
        printf("6. Insert before value\n");
        printf("7. Delete first node\n");
        printf("8. Delete last node\n");
        printf("9. Delete after kth node\n");
        printf("10. Delete before kth node\n");
        printf("11. Delete kth node\n");
        printf("12. Delete value\n");
        printf("13. Reverse list\n");
        printf("14. Print list\n");
        printf("15. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            createLinkedList();
            break;
        case 1:
            printf("\nEnter data: ");
            scanf("%d", &data);
            insertAtFront(data);
            break;
        case 2:
            printf("\nEnter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("\nEnter data: ");
            scanf("%d", &data);
            printf("\nEnter k: ");
            scanf("%d", &k);
            insertAfterKthNode(data, k);
            break;
        case 4:
            printf("\nEnter data: ");
            scanf("%d", &data);
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertAfterValue(data, value);
            break;
        case 5:
            printf("\nEnter data: ");
            scanf("%d", &data);
            printf("\nEnter k: ");
            scanf("%d", &k);
            insertBeforeKthNode(data, k);
            break;
        case 6:
            printf("\nEnter data: ");
            scanf("%d", &data);
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertBeforeValue(data, value);
            break;
        case 7:
            deleteFirstNode();
            break;
        case 8:
            deleteLastNode();
            break;
        case 9:
            printf("\nEnter k: ");
            scanf("%d", &k);
            deleteAfterKthNode(k);
            break;
        case 10:
            printf("\nEnter k: ");
            scanf("%d", &k);
            deleteBeforeKthNode(k);
            break;
        case 11:
            printf("\nEnter k: ");
            scanf("%d", &k);
            deleteKthNode(k);
            break;
        case 12:
            printf("\nEnter value: ");
            scanf("%d", &value);
            deleteValue(value);
            break;
        case 13:
            reverseList();
            break;
        case 14:
            printf("\nList: ");
            printList();
            break;
        case 15:
            exit(0);
        default:
            printf("\nInvalid choice!\n");
        }
    }
    return 0;
}