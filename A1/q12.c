// 12. Write a program to compute an union of two sorted lists of integers so that the resultant
// list remains sorted.

#include <stdio.h>

int main()
{
    int m, n, a[100], b[100];

    printf("Enter the range of 1st array: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the range of 2nd array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    int c[200], j = 0, k = 0;
    int q = m + n;

    for (int i = 0; i < q; i++)
    {
        if (j == m)
        {
            c[i] = b[k];
            k++;
        }
        else if (k == n)
        {
            c[i] = a[j];
            j++;
        }
        else
        {
            if (a[j] < b[k])
            {
                c[i] = a[j];
                j++;
            }
            else
            {
                c[i] = b[k];
                k++;
            }
        }
    }

    printf("The union of the two arrays is: ");
    for (int i = 0; i < q; i++)
    {
        printf("%d ", c[i]);
    }
    return 0;
}