#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_at_front(Node **head, int data)
{
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(Node **head, int data)
{
    Node *new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

void insert_after_kth_node(Node **head, int k, int data)
{
    Node *new_node = create_node(data);
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    while (--k && temp != NULL)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_after_value(Node **head, int value, int data)
{
    Node *new_node = create_node(data);
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Value not found in list\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_before_kth_node(Node **head, int k, int data)
{
    Node *new_node = create_node(data);
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (k == 1)
    {
        insert_at_front(head, data);
        return;
    }
    Node *temp = *head, *prev = NULL;
    while (--k && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    prev->next = new_node;
    new_node->next = temp;
}

void insert_before_value(Node **head, int value, int data)
{
    Node *new_node = create_node(data);
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->data == value)
    {
        insert_at_front(head, data);
        return;
    }
    Node *prev = NULL, *temp = *head;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value not found in list\n");
        return;
    }
    prev->next = new_node;
    new_node->next = temp;
}

void delete_first(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *del = *head;
    (*head) = (*head)->next;
    free(del);
}

void delete_last(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        delete_first(head);
        return;
    }
    Node *prev = NULL, *temp = *head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void delete_after_kth(Node **head, int k)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = *head;
    while (--k && temp != NULL)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void delete_before_kth(Node **head, int k)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (k <= 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (k == 2)
    {
        delete_first(head);
        return;
    }
    Node *prev = NULL, *temp = *head;
    while (--k > 1 && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    Node *del = prev->next;
    prev->next = del->next;
    free(del);
}

void delete_kth(Node **head, int k)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (k == 1)
    {
        delete_first(head);
        return;
    }
    Node *prev = NULL, *temp = *head;
    while (--k && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void delete_value(Node **head, int value)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->data == value)
    {
        delete_first(head);
        return;
    }
    Node *prev = NULL, *temp = *head;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value not found in list\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

Node *reverse_list(Node *head)
{
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void sort_list(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;
    Node *temp1 = *head, *temp2 = NULL;
    while (temp1 != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->data > temp2->data)
            {
                int t = temp1->data;
                temp1->data = temp2->data;
                temp2->data = t;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

bool search_element(Node *head, int data)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}

Node *merge_lists(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node *result = NULL;
    if (a->data <= b->data)
    {
        result = a;
        result->next = merge_lists(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge_lists(a, b->next);
    }
    return result;
}

Node *concatenate_lists(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node *temp = a;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = b;
    return a;
}

bool are_lists_equal(Node *a, Node *b)
{
    while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
            return false;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}

int main()
{
    Node *head = NULL;
    int choice, data, k;
    int i, n, dd;

    while (true)
    {
        printf("1. Create a linked list\n");
        printf("2. Print the content of the list\n");
        printf("3. Insert an element at the front of the list\n");
        printf("4. Insert an element at the end of the list\n");
        printf("5. Insert a node after the kth node\n");
        printf("6. Insert a node after the node containing a given value\n");
        printf("7. Insert a node before the kth node\n");
        printf("8. Insert a node before the node containing a given value\n");
        printf("9. Delete the first node\n");
        printf("10. Delete the last node\n");
        printf("11. Delete a node after the kth node\n");
        printf("12. Delete a node before the kth node\n");
        printf("13. Delete the kth node\n");
        printf("14. Delete the node containing a specified value\n");
        printf("15. Find the reverse of a list\n");
        printf("16. Sort the list\n");
        printf("17. Search a given element\n");
        printf("18. Merge two list in ascending order.\n");
        printf("19. Concatenate two list\n");
        printf("20. Find if two lists are equal(Boolean output)\n");
        printf("21. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = NULL;
            break;
        case 2:
            print_list(head);
            break;
        case 3:
            scanf("%d", &data);
            insert_at_front(&head, data);
            break;
        case 4:
            scanf("%d", &data);
            insert_at_end(&head, data);
            break;
        case 5:
            scanf("%d %d", &k, &data);
            insert_after_kth_node(&head, k, data);
            break;
        case 6:
            scanf("%d %d", &k, &data);
            insert_after_value(&head, k, data);
            break;
        case 7:
            scanf("%d %d", &k, &data);
            insert_before_kth_node(&head, k, data);
            break;
        case 8:
            scanf("%d %d", &k, &data);
            insert_before_value(&head, k, data);
            break;
        case 9:
            delete_first(&head);
            break;
        case 10:
            delete_last(&head);
            break;
        case 11:
            scanf("%d", &k);
            delete_after_kth(&head, k);
            break;
        case 12:
            scanf("%d", &k);
            delete_before_kth(&head, k);
            break;
        case 13:
            scanf("%d", &k);
            delete_kth(&head, k);
            break;
        case 14:
            scanf("%d", &k);
            delete_value(&head, k);
            break;
        case 15:
            head = reverse_list(head);
            break;
        case 16:
            sort_list(&head);
            break;
        case 17:
            scanf("%d", &k);
            if (search_element(head, k))
                printf("Element found in list\n");
            else
                printf("Element not found in list\n");
            break;
        case 18:
            Node *newHead = NULL;
            printf("Enter the number of elements in the second list\n");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &dd);
                insert_at_end(&newHead, dd);
            }
            printf("The second list is: ");
            print_list(newHead);
            head = merge_lists(head, newHead);
            printf("The merged list is: ");
            print_list(head);
            break;

        case 19:
            Node *newHead1 = NULL;
            printf("Enter the number of elements in the second list\n");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &dd);
                insert_at_end(&newHead1, dd);
            }
            printf("The second list is: ");
            print_list(newHead1);
            head = concatenate_lists(head, newHead1);
            printf("The concatenated list is: ");
            print_list(head);
            break;

        case 20:
            Node *newHead2 = NULL;
            printf("Enter the number of elements in the second list\n");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &dd);
                insert_at_end(&newHead2, dd);
            }
            printf("The second list is: ");
            print_list(newHead2);
            if (are_lists_equal(head, newHead2))
                printf("The two lists are equal\n");
            else
                printf("The two lists are not equal\n");
            break;

        case 21:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
