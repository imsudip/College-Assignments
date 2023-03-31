//  Write a function to read a matrix, transpose a matrix, multiply two matrices and use
// these functions in main() to check whether an input matrix is orthogonal or not.

#include <stdio.h>

void readMatrix(int arr[][100], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void transposeMatrix(int arr[][100], int row, int col)
{
    int i, j, temp;
    for (i = 0; i < row; i++)
    {
        for (j = i + 1; j < col; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

void multiplyMatrix(int arr1[][100], int arr2[][100], int row1, int col1, int row2, int col2)
{
    int i, j, k, sum;
    int arr3[100][100];
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            sum = 0;
            for (k = 0; k < col1; k++)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            arr3[i][j] = sum;
        }
    }
    printf("The product of the two matrices is: \n");
    printMatrix(arr3, row1, col2);
}

int isOrthogonal(int arr[][100], int row, int col)
{
    int i, j, k, sum;
    int arr2[100][100];
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            arr2[i][j] = arr[i][j];
        }
    }
    transposeMatrix(arr2, row, col);
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            sum = 0;
            for (k = 0; k < col; k++)
            {
                sum += arr[i][k] * arr2[k][j];
            }
            if (sum != 1 && sum != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void printMatrix(int arr[][100], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void copyMatrix(int arr1[][100], int arr2[][100], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            arr2[i][j] = arr1[i][j];
        }
    }
}

int main()
{
    int arr[100][100], arr2[100][100], row, col, row2, col2;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &row, &col);
    printf("Enter the elements of the matrix: ");
    readMatrix(arr, row, col);
    printf("The matrix is: \n");
    printMatrix(arr, row, col);
    copyMatrix(arr, arr2, row, col);
    printf("The transpose of the matrix is: \n");
    transposeMatrix(arr2, row, col);
    printMatrix(arr2, col, row);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &row2, &col2);
    if (col != row2)
    {
        printf("The matrices cannot be multiplied.\n");
        }
    else
    {
        printf("Enter the elements of the second matrix: ");
        readMatrix(arr2, row2, col2);
        printf("The second matrix is: \n");
        printMatrix(arr2, row2, col2);
        multiplyMatrix(arr, arr2, row, col, row2, col2);
    }
    if (isOrthogonal(arr, row, col))
    {
        printf("The matrix is orthogonal.\n");
    }
    else
    {
        printf("The matrix is not orthogonal.\n");
    }

    return 0;
}