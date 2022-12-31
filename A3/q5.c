// Write a menu driven program that depicts the
// working of a library. The menu options should be:
// 1. Add book information
// 2. Display book information
// 3. List all books of given author
// 4. List the title of specified book
// 5. List the count of books in the library
// 6. List the books in the order of accession number
// 7. Exit
// Create a structure called library to store accession
// number, title of the book, author name, price of the
// book, and flag indicating whether book is issued or
// not. Consider that there are more than 1000
// records.

#include <stdio.h>
#include <string.h>

struct library
{
    int accession_number;
    char title[20];
    char author[20];
    float price;
    int issued;
};
typedef struct library Library;

void add_book(Library l[], int *n)
{
    printf("Enter the accession number: ");
    scanf("%d", &l[*n].accession_number);
    printf("Enter the title of the book: ");
    scanf("%s", l[*n].title);
    printf("Enter the author of the book: ");
    scanf("%s", l[*n].author);
    printf("Enter the price of the book: ");
    scanf("%f", &l[*n].price);
    printf("Enter 1 if the book is issued, 0 otherwise: ");
    scanf("%d", &l[*n].issued);
    (*n)++;
}

void display_books(Library l[], int n)
{
    int i;
    printf("%-10s|%-20s|%-20s|%-10s|%-10s\n", "Acc No.", "Title", "Author", "Price", "Issued");
    for (i = 0; i < n; i++)
    {
        printf("%-10d|%-20s|%-20s|%-10.2f|%-10d\n", l[i].accession_number, l[i].title, l[i].author, l[i].price, l[i].issued);
    }
}

void list_author(Library l[], int n, char author[])
{
    int i;
    printf("%-10s|%-20s|%-20s|%-10s|%-10s\n", "Acc No.", "Title", "Author", "Price", "Issued");
    for (i = 0; i < n; i++)
    {
        if (strcmp(l[i].author, author) == 0)
        {
            printf("%-10d|%-20s|%-20s|%-10.2f|%-10d\n", l[i].accession_number, l[i].title, l[i].author, l[i].price, l[i].issued);
        }
    }
}

void list_titles(Library l[], int n, char title[])
{
    int i;
    printf("%-10s|%-20s|%-20s|%-10s|%-10s\n", "Acc No.", "Title", "Author", "Price", "Issued");
}


void list_count(Library l[], int n)
{
    printf("The number of books in the library is %d\n", n);
}

void list_accession(Library l[], int n)
{
    int i, j;
    Library temp;
    Library arr2[n];
    for (i = 0; i < n; i++)
    {
        arr2[i] = l[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr2[i].accession_number > arr2[j].accession_number)
            {
                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }

    display_books(arr2, n);
}

int main()
{
    int n = 0, choice;
    Library arr[1000];
    char author[20], title[20];
    do
    {
        printf("Enter your choice:\n");
        printf("1. Add book information\n");
        printf("2. Display book information\n");
        printf("3. List all books of given author\n");
        printf("4. List the title of specified book\n");
        printf("5. List the count of books in the library\n");
        printf("6. List the books in the order of accession number\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_book(arr, &n);
            break;
        case 2:
            display_books(arr, n);
            break;
        case 3:
            printf("Enter the author name: ");
            scanf("%s", author);
            list_author(arr, n, author);
            break;
        case 4:
            printf("Enter the title of the book: ");
            scanf("%s", title);
            list_titles(arr, n, title);
            break;
        case 5:
            list_count(arr, n);
            break;
        case 6:
            list_accession(arr, n);
            break;
        case 7:
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 7);
    return 0;
}



