// take n number of integers as input and make two arrays of odd and even numbers from the input.
// make two square matrices of size m x m (where m is largest square number less than or equal to smallest of the two arrays) and fill them with the odd and even numbers respectively.
// print the resultant matrices and the sum of the two matrices.

#include <stdio.h>

int main()
{
    int n, mainArray[100], oddArray[100], evenArray[100], oddCount = 0, evenCount = 0;
    int i, j;
    printf("Enter the total number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &mainArray[i]);
        if (mainArray[i] % 2 == 0)
        {
            evenArray[evenCount] = mainArray[i];
            evenCount++;
        }
        else
        {
            oddArray[oddCount] = mainArray[i];
            oddCount++;
        }
    }
    if (oddCount == 0 || evenCount == 0)
    {
        printf("Please enter at least one odd and one even number.");
        return 0;
    }
    printf("\nThe odd array is: ");
    for (i = 0; i < oddCount; i++)
    {
        printf("%d ", oddArray[i]);
    }
    printf("\nThe even array is: ");
    for (i = 0; i < evenCount; i++)
    {
        printf("%d ", evenArray[i]);
    }

    int m = 0;
    int min = oddCount < evenCount ? oddCount : evenCount;

    for (int i = 1; i <= min; i++)
    {
        if (i * i <= min)
        {
            m = i;
        }
    }

    int oddMatrix[100][100], evenMatrix[100][100];
    int oddIndex = 0, evenIndex = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            oddMatrix[i][j] = oddArray[oddIndex];
            oddIndex++;
            evenMatrix[i][j] = evenArray[evenIndex];
            evenIndex++;
        }
    }

    printf("\nThe odd matrix is: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%3d ", oddMatrix[i][j]);
        }
        printf("\n");
    }

    printf("The even matrix is: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%3d ", evenMatrix[i][j]);
        }
        printf("\n");
    }

    // Matrix Addition
    int sumMatrix[100][100];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            sumMatrix[i][j] = oddMatrix[i][j] + evenMatrix[i][j];
        }
    }

    printf("The sum matrix is: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%3d ", sumMatrix[i][j]);
        }
        printf("\n");
    }

    printf("The difference matrix is: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%3d ", oddMatrix[i][j] - evenMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}