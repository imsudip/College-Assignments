// 7. Write a program to compute LCM of n integers.

#include <stdio.h>

int euclidGCD(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return euclidGCD(b % a, a);
}

int lcm(int a, int b)
{
    return (a * b) / euclidGCD(a, b);
}
int main()
{
    int n, a[100], result = 1;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    printf("Enter the integers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        }
    result = a[0];
    for (int i = 1; i < n; i++)
    {
        result = lcm(result, a[i]);
    }
    printf("LCM of the given integers is %d", result);
    return 0;
}