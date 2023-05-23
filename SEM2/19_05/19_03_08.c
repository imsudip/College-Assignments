// Write a program to check balanced brackets of an expression using stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *data;
    int top;
    int size;
} Stack;

Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (char *)malloc(sizeof(char) * size);
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

void push(Stack *stack, char value)
{
    if (isFull(stack))
    {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top--];
}

char peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

int isBalanced(char *exp)
{
    Stack *stack = createStack(strlen(exp));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(stack, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(stack))
            {
                return 0;
            }
            char top = pop(stack);
            if (exp[i] == ')' && top != '(')
            {
                return 0;
            }
            if (exp[i] == ']' && top != '[')
            {
                return 0;
            }
            if (exp[i] == '}' && top != '{')
            {
                return 0;
            }
        }
    }
    return isEmpty(stack);
}

int main()
{
    char *exp = "((a+b)*(c-d))";
    int result = isBalanced(exp);
    if (result)
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not balanced\n");
    }
    return 0;
}