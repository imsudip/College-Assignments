// 5. Write a program to find the value of one number raised to the power of the other number
// without using the library function pow().

#include <stdio.h>

int main()
{
    int exponent;
    float base, result = 1.0;
    printf("Enter base number: ");
    scanf("%f", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);
    // case 1
    if (base == 0 && exponent <= 0)
    {
        printf("undefined");
    }
    // case 2 : exponent is negative
    else if (exponent < 0)
    {
        exponent = -exponent;
        while (exponent != 0)
        {
            result *= base;
            --exponent;
        }
        result = 1 / result;
        printf("%.4f", result);
    }
    // case 3 : exponent is positive
    else
    {
        while (exponent != 0)
        {
            result *= base;
            --exponent;
        }
        printf("%f", result);
    }
}