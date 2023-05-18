// Write a program to implement a stack data structure using an array.
// use dynamically allocated array
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int top;
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(sizeof(int));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int value)
{
    // resize array
    if (stack->top == -1)
    {
        stack->data = (int *)realloc(stack->data, sizeof(int));
    }
    else
    {
        stack->data = (int *)realloc(stack->data, sizeof(int) * (stack->top + 2));
    }
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

// menu driven
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
            {
                printf("Popped value is %d\n", value);
            }
            break;
        case 3:
            value = peek(stack);
            if (value != -1)
            {
                printf("Topmost element is %d\n", value);
            }
            break;
        case 4:
            exit(0);
        }
        printf("\n");
    }
    return 0;
}