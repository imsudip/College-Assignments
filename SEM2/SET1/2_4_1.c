#include <stdio.h>
#define N 100 // maximum number of people

int main()
{
    int n, m;    // n = number of people, m = number of people to skip
    int a[N][2]; // 2D array to store the people and their status (alive or executed)
    int i, j;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the number of people to skip: ");
    scanf("%d", &m);
    for (i = 1; i <= n; i++)
    {
        a[i][0] = i; // initialize the people's numbers
        a[i][1] = 1; // initialize the people's status as alive (1)
    }
    i = 1;
    int alive = n;
    while (alive > 1)
    { // repeat until only one person remains
        for (j = 1; j <= m; j++)
        { // skip m people
            i++;
            if (i > n)
                i = 1; // if reached the end of the circle, go back to the beginning
            if (a[i][1] == 0)
                j--; // if the person is already executed, do not count them
        }
        a[i][1] = 0; // execute the next person
        alive--;
        i++;
    }
    for (i = 1; i <= N; i++)
    {
        if (a[i][1] == 1)
        { // find the remaining person
            printf("The person to be freed is: %d\n", a[i][0]);
            break;
        }
    }
    return 0;
}