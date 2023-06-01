#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    struct Node* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        } else {
            struct Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("Threaded Binary Tree Menu\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 3);

    return 0;
}
