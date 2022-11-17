// . Write a program to generate the n-th Fibonacci number where n will be taken as input.
// There is a formula for computing the n-th Fibonacci number:

// F(n) = (1/sqrt(5)) * (((1+sqrt(5))/2)^n - ((1-sqrt(5))/2)^n)

// Compute n-th Fibonacci number without using the formula and using the formula, and
// compare these two are they same?

#include <stdio.h>
#include <math.h>
typedef long double ld;
typedef long long int ll;

ld fibFormula(int n)
{
    ld a, b, c;
    a = (1 + pow(5, 0.5));
    b = (1 - pow(5, 0.5));
    c = 1 / pow(5, 0.5);
    ld d = a / 2;
    ld e = b / 2;
    ld fib = c * (pow(d, n) - pow(e, n));

    return fib;
}

ld fib(int n)
{
    ld a = 0, b = 1, c;
    if (n == 0)
    {
        return a;
    }
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    ld fibFormulaResult = fibFormula(n);
    ld fibResult = fib(n);
    printf("Actual Fibonacci number: %0.0Lf \n", fibResult);
    printf("Fibonacci number using formula: %0.0Lf \n", fibFormulaResult);
    ld diff = fibFormulaResult - fibResult;
    if (diff < 0)
    {
        diff = -diff;
    }
    printf("Difference: %Le \n", diff);
    return 0;
}