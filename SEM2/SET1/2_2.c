// Write a menu-driven program representing a polynomial as a data structure
// using a singly linked list and write functions to add, subtract and multiply
// two polynomials.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
} Node;

Node *create_node(int coeff, int exp)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}

void insert_end(Node **head, int coeff, int exp)
{
    Node *new_node = create_node(coeff, exp);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
}

Node *add(Node *p1, Node *p2)
{
    Node *p3 = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            insert_end(&p3, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            insert_end(&p3, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            insert_end(&p3, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        insert_end(&p3, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        insert_end(&p3, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return p3;
}

Node *subtract(Node *p1, Node *p2)
{
    Node *p3 = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            insert_end(&p3, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            insert_end(&p3, -p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            insert_end(&p3, p1->coeff - p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        insert_end(&p3, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        insert_end(&p3, -p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return p3;
}

Node *multiply(Node *p1, Node *p2)
{
    Node *p3 = NULL;
    Node *temp = p2;
    while (p1 != NULL)
    {
        p2 = temp;
        while (p2 != NULL)
        {
            insert_end(&p3, p1->coeff * p2->coeff, p1->exp + p2->exp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return p3;
}

int main()
{
    Node *p1 = NULL, *p2 = NULL, *p3 = NULL;
    int choice, coeff, exp;
    do
    {
        printf("\n1. Insert in Polynomial 1\n");
        printf("2. Insert in Polynomial 2\n");
        printf("3. Display Polynomial 1\n");
        printf("4. Display Polynomial 2\n");
        printf("5. Add Polynomials\n");
        printf("6. Subtract Polynomials\n");
        printf("7. Multiply Polynomials\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter coefficient: ");
            scanf("%d", &coeff);
            printf("Enter exponent: ");
            scanf("%d", &exp);
            insert_end(&p1, coeff, exp);
            break;
        case 2:
            printf("Enter coefficient: ");
            scanf("%d", &coeff);
            printf("Enter exponent: ");
            scanf("%d", &exp);
            insert_end(&p2, coeff, exp);
            break;
        case 3:
            display(p1);
            break;
        case 4:
            display(p2);
            break;
        case 5:
            p3 = add(p1, p2);
            display(p3);
            break;
        case 6:
            p3 = subtract(p1, p2);
            display(p3);
            break;
        case 7:
            p3 = multiply(p1, p2);
            display(p3);
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 8);
    return 0;
}