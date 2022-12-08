// Write a function to take one string then print it in the reverse order. Write a recursive and
// non-recursive versions both.

#include <stdio.h>

void reverse(char *str)
{
    if (*str)
    {
        reverse(str + 1);
        printf("%c", *str);
    }
}

void nonRecursiveReverse(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    i--;
    while (i >= 0)
    {
        printf("%c", str[i]);
        i--;
    }
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    printf("The reverse of the string is: ");
    reverse(str);
    printf("\n");
    printf("The reverse of the string is: ");
    nonRecursiveReverse(str);
    printf("\n");
    return 0;
}