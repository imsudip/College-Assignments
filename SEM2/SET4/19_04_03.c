// Implement a threaded binary tree (inorder)
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
    int lthread, rthread;
} node;

node *root = NULL;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->lthread = newNode->rthread = 1;
    return newNode;
}

void insert(int data)
{
    node *newNode = createNode(data);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    node *temp = root;
    while (1)
    {
        if (data < temp->data)
        {
            if (temp->lthread == 1)
            {
                newNode->left = temp->left;
                newNode->right = temp;
                temp->left = newNode;
                temp->lthread = 0;
                return;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->rthread == 1)
            {
                newNode->right = temp->right;
                newNode->left = temp;
                temp->right = newNode;
                temp->rthread = 0;
                return;
            }
            temp = temp->right;
        }
    }
}

void inorder()
{
    node *temp = root;
    while (temp->lthread == 0)
    {
        temp = temp->left;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        if (temp->rthread == 1)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->right;
            while (temp->lthread == 0)
            {
                temp = temp->left;
            }
        }
    }
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            inorder();
            printf("\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}