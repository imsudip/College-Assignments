/* Write a program to generate the n-th Fibonacci number where n will be taken as input.
Compute n-th Fibonacci number without using the formula and using the formula, and compare these two.
Are they same?*/

#include <stdio.h>
#include <math.h>
long double fiboFormula(int n);
long long int fibonacci(int n);

int main()
{
    int n;
    printf("enter n value: ");
    scanf("%d", &n);
    long double result1 = fiboFormula(n);
    long double result2 = fibonacci(n);
    printf("n-th fibonacci number by formula:%ld", result1);
    printf("n-th fibonacci number by normal procedure:%ll", result2);
    printf("Difference: %ld", result1 - result2);
    return 0;
}

long double fiboFormula(int n)
{
    long double res;
    res = ((1 / sqrt(5)) * (pow((1 + sqrt(5)) / 2, n)) - (1 / sqrt(5)) * (pow(1 - sqrt(5) / 2, n)));
    return res;
}

long long int fibonacci(int n)
{
    int a = 0, b = 1, c;
    for (int i = 1; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}