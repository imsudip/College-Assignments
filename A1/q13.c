#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int n, p, i, j, k, rem, r;
    float M[100][100], M_p[100][100], R[100][1], new_R[100][1];
    printf("Enter the size of square matrix : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        rem = 100;
        for (j = 0; j < n - 1; j++)
        {
            r = rand() % rem;
            M[i][j] = r * 0.01;
            rem -= r;
        }
        M[i][n - 1] = rem * 0.01;
    }

    printf("\nThe matrix M is : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.2f ", M[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        R[i][0] = 1.0 / n;
    }
    printf("\nThe matrix R is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%.2f\n", R[i][0]);
    }
    printf("\nEnter the value of p : ");
    scanf("%d", &p);
    while (p--)
    {
        for (i = 0; i < n; i++)
        {
            float temp = 0;
            for (j = 0; j < n; j++)
            {
                temp += (M[i][j] * R[j][0]);
            }
            new_R[i][0] = temp;
        }
        for (i = 0; i < n; i++)
        {
            R[i][0] = new_R[i][0];
        }
    }
    printf("\nThe matrix (M^p)*R is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%.2f\n", R[i][0]);
    }
    return 0;
}