// Write a menu driven program, consisting of following functions (on string). For each of
// the following, write your own function. Use character pointers as the arguments for
// implementing the functions and do not use any library function. Strlen() , Strcpy(),
// Strcat(), Strrev(), Strcmp()

#include <stdio.h>

int Strlen(char *s)
{
    int i = 0;
    while (*s != '\0')
    {
        i++;
        s++;
    }
    return i;
}

void Strcpy(char *s1, char *s2)
{
    while (*s1 != '\0')
    {
        *s2 = *s1;
        s1++;
        s2++;
    }
    *s2 = '\0';
}

void Strcat(char *s1, char *s2)
{
    while (*s1 != '\0')
    {
        s1++;
    }
    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

void Strrev(char *s1, char *s2)
{
    int i = 0;
    while (*s1 != '\0')
    {
        s1++;
        i++;
    }
    s1--;
    while (i > 0)
    {
        *s2 = *s1;
        s1--;
        s2++;
        i--;
    }
    *s2 = '\0';
}

int Strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 > *s2)
        {
            return 1;
        }
        else if (*s1 < *s2)
        {
            return -1;
        }
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0')
    {
        return 0;
    }
    else if (*s1 == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void printString(char *s)
{
    while (*s != '\0')
    {
        printf("%c", *s);
        s++;
    }
    printf("\n");
}

int main()
{
    char s1[100], s2[100];
    int ch;
    while (1)
    {
        printf("1. Strlen()\n2. Strcpy()\n3. Strcat()\n4. Strrev()\n5. Strcmp()\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the string: ");
            scanf(" %[^\n]", s1);
            printf("Length of the string is %d\n", Strlen(s1));
            break;
        case 2:
            printf("Enter the string: ");
            scanf(" %[^\n]", s1);
            Strcpy(s1, s2);
            printf("Copied string is ");
            printString(s2);
            break;
        case 3:
            printf("Enter the string: ");
            scanf(" %[^\n]", s1);
            printf("Enter the string to be concatenated: ");
            scanf(" %[^\n]", s2);
            Strcat(s1, s2);
            printf("Concatenated string is ");
            printString(s1);
            break;
        case 4:
            printf("Enter the string: ");
            scanf(" %[^\n]", s1);
            Strrev(s1, s2);
            printf("Reversed string is ");
            printString(s2);
            break;
        case 5:
            printf("Enter the string: ");
            scanf(" %[^\n]", s1);
            printf("Enter the string: ");
            scanf(" %[^\n]", s2);
            printf("Strings are ");
            if (Strcmp(s1, s2) == 0)
            {
                printf("equal\n");
            }

            else
            {
                printf("not equal\n");
            }
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}