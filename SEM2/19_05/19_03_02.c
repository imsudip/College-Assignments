// Implement a system that can handle more than one stack (n stacks).

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 3

typedef struct
{
    int *data;
    int top;
    int size;
} Stack;

Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == stack->size - 1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

// menu driven program
int main()
{
    int size, choice, value, stackNumber;
    Stack *stacks[MAX_STACKS];
    printf("Enter the size of each stack: ");
    scanf("%d", &size);
    for (int i = 0; i < MAX_STACKS; i++)
    {
        stacks[i] = createStack(size);
    }
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 4)
        {
            break;
        }
        printf("Enter the stack number: ");
        scanf("%d", &stackNumber);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            push(stacks[stackNumber - 1], value);
            break;
        case 2:
            printf("Popped value: %d\n", pop(stacks[stackNumber - 1]));
            break;
        case 3:
            printf("Top value: %d\n", peek(stacks[stackNumber - 1]));
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}