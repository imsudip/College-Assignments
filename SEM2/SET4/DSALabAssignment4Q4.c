#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

struct Node* findMinValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* delete(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = delete(root->left, value);
    } else if (value > root->data) {
        root->right = delete(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMinValueNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    while (1) {
        printf("Binary Search Tree Operations:\n");
        printf("1. Create\n");
        printf("2. Search\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int value;
        struct Node* node;

        switch (choice) {
            case 1:
                printf("Enter the value to create: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Binary search tree created.\n");
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                node = search(root, value);
                if (node != NULL) {
                    printf("Value found in the binary search tree.\n");
                } else {
                    printf("Value not found in the binary search tree.\n");
                }
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value inserted into the binary search tree.\n");
                break;

            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                printf("Value deleted from the binary search tree.\n");
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Binary Search Tree: ");
        display(root);
        printf("\n\n");
    }

    return 0;
}
