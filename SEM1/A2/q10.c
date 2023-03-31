// 10) Write a function which will accept two strings and check whether the second string is
// present in the first one. If it is, it returns the starting position else returns 0. Write a
// program which dynamically allocates memory for two strings taken from the keyboard
// and uses the above function for searching one string into another.

#include <stdio.h>
#include <stdlib.h>
int check(char *s1, char *s2)
{
    int i = 0, j = 0, k = 0;
    while (*(s1 + i) != '\0')
    {
        if (*(s1 + i) == *(s2 + j))
        {
            k = i;
            while (*(s1 + i) == *(s2 + j))
            {
                i++;
                j++;
            }
            if (*(s2 + j) == '\0')
                return k;
            else
            {
                i = k;
                j = 0;
            }
        }
        i++;
    }
    return -1;
}

int main()
{
    char *s1, *s2;
    int i, j, k, l, m, n, flag = 0;
    printf("Enter the length of the first string: ");
    scanf("%d", &l);
    s1 = (char *)malloc(l * sizeof(char));
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the length of the second string: ");
    scanf("%d", &m);
    s2 = (char *)malloc(m * sizeof(char));
    printf("Enter the second string: ");
    scanf("%s", s2);
    k = check(s1, s2);
    if (k == -1)
        printf("The second string is not present in the first one.\n");
    else
        printf("The second string is present in the first one at position %d.\n", k + 1);

    return 0;
}