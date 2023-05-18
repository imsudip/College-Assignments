// Write a Boolean function to return true if two stacks are equal.

#include <stdio.h>
#include <stdlib.h>

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

int isEqual(Stack *stack1, Stack *stack2)
{
    if (stack1->top != stack2->top)
    {
        return 0;
    }
    for (int i = 0; i <= stack1->top; i++)
    {
        if (stack1->data[i] != stack2->data[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    Stack *stack1 = createStack(5);
    Stack *stack2 = createStack(5);
    push(stack1, 1);
    push(stack1, 2);
    push(stack1, 3);
    push(stack2, 1);
    push(stack2, 2);
    push(stack2, 3);
    printf("%d\n", isEqual(stack1, stack2));
    return 0;
}