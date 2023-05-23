// Using a stack, write a program to convert an infix expression into its
// equivalent postfix expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

void infixToPostfix(char *exp)
{
    int i, k;
    Stack *stack = createStack(strlen(exp));
    char *output = (char *)malloc(sizeof(char) * (strlen(exp) + 1));
    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
            output[++k] = exp[i];
        else if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                output[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return;
            else
                pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                output[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
}

int main()
{
    char exp[] = "A*(B+C)/D";
    infixToPostfix(exp);
    return 0;
}