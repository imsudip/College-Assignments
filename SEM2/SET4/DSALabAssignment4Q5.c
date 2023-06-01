#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        // Duplicate values are not allowed
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && value < root->left->data) {
        // Left Left Case
        return rotateRight(root);
    }

    if (balance < -1 && value > root->right->data) {
        // Right Right Case
        return rotateLeft(root);
    }

    if (balance > 1 && value > root->left->data) {
        // Left Right Case
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && value < root->right->data) {
        // Right Left Case
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
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
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        // Left Left Case
        return rotateRight(root);
    }

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        // Left Right Case
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        // Right Right Case
        return rotateLeft(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        // Right Left Case
        root->right = rotateRight(root->right);
        return rotateLeft(root);
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
        printf("AVL Tree Operations:\n");
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
                printf("AVL tree created.\n");
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                node = search(root, value);
                if (node != NULL) {
                    printf("Value found in the AVL tree.\n");
                } else {
                    printf("Value not found in the AVL tree.\n");
                }
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value inserted into the AVL tree.\n");
                break;

            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                printf("Value deleted from the AVL tree.\n");
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("AVL Tree: ");
        display(root);
        printf("\n\n");
    }

    return 0;
}
