// Print the data from a file of integers in reverse order using a stack.

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *data;
    int top;
    int size;
} typedef Stack;

Stack *createStack(FILE *file)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(sizeof(int) * 100);
    stack->top = -1;
    stack->size = 100;
    int value;
    while (fscanf(file, "%d", &value) != EOF)
    {
        push(stack, value);
    }
    return stack;
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

int isFull(Stack *stack)
{
    return stack->top == stack->size - 1;
}

void displayText(Stack *stack)
{
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main()
{
    FILE *file = fopen("data.txt", "r");
    Stack *stack = createStack(file);
    displayText(stack);
    return 0;
}
