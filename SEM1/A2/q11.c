// 11) Write a program to store the country names and sort them in alphabetical order. Use an
// array of pointers to store the country names and pass the array to the function sort().

#include <stdio.h>
#include <stdlib.h>

void sort(char **s, int n)
{
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(*(s + i), *(s + j)) > 0)
            {
                temp = *(s + i);
                *(s + i) = *(s + j);
                *(s + j) = temp;
            }
        }
    }
}
// I used the bubble sort algorithm to sort the array of pointers.

int main()
{
    int n, i;
    char **s;
    printf("Enter the number of countries: ");
    scanf("%d", &n);
    s = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        *(s + i) = (char *)malloc(20 * sizeof(char));
        printf("Enter the name of country %d: ", i + 1);
        scanf("%s", *(s + i));
    }
    sort(s, n);
    printf("The sorted list of countries is: ");
    for (i = 0; i < n; i++)
    {
        printf("%s ", *(s + i));
    }
    printf("\n");
    return 0;
}