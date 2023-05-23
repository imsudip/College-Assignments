// Write a program for dynamic implementation (using a link list) of stacks
// (n stacks).

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    Node *temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

int main()
{
    int choice, value;
    Stack *stack = createStack();
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(stack, value);
            break;
        case 2:
            value = pop(stack);
            if (value != -1)
                printf("Popped value is %d\n", value);
            break;
        case 3:
            value = peek(stack);
            if (value != -1)
                printf("Topmost value is %d\n", value);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
        printf("\n");
    }
    return 0;
}