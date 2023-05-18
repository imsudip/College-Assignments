#include <stdio.h>
#define N 1000

int findNextAlive(int a[][2], int n, int i, int dir)
{
    int j;
    while (1)
    {
        i += dir;
        if (i > n) // clockwise
            i = 1;
        if (i < 1) // anticlockwise
            i = n;
        if (a[i][1] == 1)
            return i;
    }
    return -1;
}

int main()
{
    int n, m;
    int a[N][2];
    int i, j;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the number of people to skip: ");
    scanf("%d", &m);
    for (i = 1; i <= n; i++)
    {
        a[i][0] = i;
        a[i][1] = 1;
    }
    int dir;
    printf("Enter the direction (1 for clockwise, -1 for anticlockwise): ");
    scanf("%d", &dir);
    printf("Enter the starting position: ");
    scanf("%d", &i);
    int alive = n;
    printf("The order of execution is: \n");
    while (alive > 1)
    {
        printf("🔫%d -->", i);
        // skip m people
        for (j = 1; j <= m + 1; j++)
            i = findNextAlive(a, n, i, dir);
        // kill the mth person
        a[i][1] = 0;
        alive--;
        printf("💀%d \n", a[i][0]);
        // find the next alive person
        i = findNextAlive(a, n, i, dir);
    }
    printf("\nThe person who survives is: ");
    for (i = 1; i <= n; i++)
        if (a[i][1] == 1)
            printf("%d\n", a[i][0]);
    return 0;
}