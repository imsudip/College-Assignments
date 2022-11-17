// 9. W.A.P. to print all prime numbers between 1 and n. (n will be given as input).

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int flag = 1;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d ", i);
        }
    }
    return 0;
}