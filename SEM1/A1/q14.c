#include <stdio.h>
typedef long long int ll;
ll factorial(int n)
{
    ll f;

    for (f = 1; n > 1; n--)
        f *= n;

    return f;
}

ll ncr(int n, int r)
{
    return factorial(n) / (factorial(n - r) * factorial(r));
}

int main()
{
    int n, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n - i; j++)
            printf("  ");

        for (j = 0; j <= i; j++)
            printf(" %3d", ncr(i, j));

        printf("\n");
    }
    return 0;
}