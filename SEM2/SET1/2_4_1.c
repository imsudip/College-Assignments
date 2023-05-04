#include <stdio.h>
#define N 100 // maximum number of people

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
    i = 1;
    int alive = n;
    while (alive > 1)
    {
        for (j = 1; j <= m; j++)
        {
            i++;
            if (i > n)
                i = 2;
            if (a[i][1] == 0)
                j--;
        }
        a[i][1] = 0;
        alive--;
        i++;
    }
    for (i = 1; i <= N; i++)
    {
        if (a[i][1] == 1)
        {
            printf("The person to be freed is: %d\n", a[i][0]);
            break;
        }
    }
    return 0;
}