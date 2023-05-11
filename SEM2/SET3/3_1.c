// Write a program to implement a stack data structure using an array.
// use dynamically allocated array
#include <stdio.h>
#include <stdlib.h>

void push(int **stack, int *top, int *size, int data)
{
    if (*top == *size - 1)
    {
        *size *= 2;
        *stack = (int *)realloc(*stack, *size * sizeof(int));
    }
    (*top)++;
    (*stack)[*top] = data;
}

int pop(int **stack, int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    int data = (*stack)[*top];
    (*top)--;
    return data;
}

void display(int *stack, int top)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// menu driven program
int main()
{
    int *stack = (int *)malloc(1 * sizeof(int));
    int top = -1;
    int size = 1;
    int choice;
    int data;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            push(&stack, &top, &size, data);
            break;
        case 2:
            data = pop(&stack, &top);
            if (data != -1)
            {
                printf("Popped data: %d\n", data);
            }
            break;
        case 3:
            display(stack, top);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
        }
    return 0;
}