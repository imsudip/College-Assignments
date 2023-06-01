#include <stdio.h>

#define MAX_SIZE 100

int binaryTree[MAX_SIZE];
int size = 0;

int leftChild(int index) {
    return 2 * index + 1;
}

int rightChild(int index) {
    return 2 * index + 2;
}

void createBinaryTree() {
    int i;
    printf("Enter the number of elements in the binary tree: ");
    scanf("%d", &size);
    printf("Enter the elements of the binary tree:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &binaryTree[i]);
    }
}

void preorderTraversal(int index) {
    if (index < size && binaryTree[index] != -1) {
        printf("%d ", binaryTree[index]);
        preorderTraversal(leftChild(index));
        preorderTraversal(rightChild(index));
    }
}

void inorderTraversal(int index) {
    if (index < size && binaryTree[index] != -1) {
        inorderTraversal(leftChild(index));
        printf("%d ", binaryTree[index]);
        inorderTraversal(rightChild(index));
    }
}

void postorderTraversal(int index) {
    if (index < size && binaryTree[index] != -1) {
        postorderTraversal(leftChild(index));
        postorderTraversal(rightChild(index));
        printf("%d ", binaryTree[index]);
    }
}

int main() {
    int choice;

    do {
        printf("Binary Tree Menu\n");
        printf("1. Create Binary Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createBinaryTree();
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(0);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(0);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(0);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}
