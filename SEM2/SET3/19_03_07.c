// Write a program to evaluate postfix expression using a stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int evaluatePostfix(char *exp)
{
    Stack *stack = createStack(strlen(exp));
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(stack, exp[i] - '0');
        }
        else
        {
            int op1 = pop(stack);
            int op2 = pop(stack);
            switch (exp[i])
            {
            case '+':
                push(stack, op1 + op2);
                break;
            case '-':
                push(stack, op2 - op1);
                break;
            case '*':
                push(stack, op1 * op2);
                break;
            case '/':
                push(stack, op2 / op1);
                break;
            }
        }
        i++;
    }
    return pop(stack);
}

int main()
{
    char exp[] = "231*+9-";
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}