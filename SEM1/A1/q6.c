// 6. Write a program to compute GCD of two numbers. Implement the program using the
// Euclid Algorithm and the factorization method.

#include <stdio.h>

int euclidGCD(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    int remainder = b % a;
    printf("%d ", remainder);
    return euclidGCD(remainder, a);
}

int factorizationGCD(int a, int b)
{
    int gcd = 1;
    // 48 = 2 x 2 x 2 x 2 x 3
    // print all the prime factors of a and b
    int tempA = a;
    int tempB = b;

    for (int i = 2; i <= a; i++)
    {
        while (a % i == 0 && b % i == 0)
        {
            printf("%d | %d , %d \n", i, a, b);
            gcd *= i;
            a /= i;
            b /= i;
        }
    }
    printf("  | %d , %d \n", a, b);
    printf("GCD of %d and %d is %d\n", tempA, tempB, gcd);
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Euclid's method: \n");
    printf("Remainder list :\n");
    printf("\nGCD of %d and %d is %d using Euclid's Algorithm \n", a, b, euclidGCD(a, b));
    printf("\nFactorization method: \n");
    factorizationGCD(a, b);
    return 0;
}