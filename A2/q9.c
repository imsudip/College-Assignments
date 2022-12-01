// 9) Write a function to convert a decimal number to any other base given by the user

#include <stdio.h>
void decToBase(int n, int b)
{
    if (n == 0)
        return;

    decToBase(n / b, b);
    if (n % b < 10)
        printf("%d", n % b);
    else
        printf("%c", n % b + 55);
}

void floatPartToBase(double n, int b)
{
    if (n == 0)
        return;

    if ((int)(n * b) < 10)
        printf("%d", (int)(n * b));
    else
        printf("%c", (int)(n * b) + 55);
    floatPartToBase(n * b - (int)(n * b), b);
}
int main()
{
    int b;
    double n;
    printf("Enter the number: ");
    scanf("%lf", &n);

    printf("Enter the base: ");
    scanf("%d", &b);
    printf("The number in base %d is: ", b);
    int intPart = (int)n;
    double floatPart = (n - intPart);

    decToBase(intPart, b);
    if (floatPart != 0)
    {
        printf(".");
        floatPartToBase(floatPart, b);
    }

    printf("\n");
    return 0;
}
