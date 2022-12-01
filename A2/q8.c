// Write a recursive function for each of the following problems
// a) to generate Fibonacci numbers.
// b) to find the GCD of two numbers.
// c) to generate permutations of n numbers
// d) to find the sum of the digits of any number.
// e) to convert from decimal to binary representation
// f) To compute Cos series up to n terms.

#include <stdio.h>
typedef long long int ll;
// a )
void fib(int n)
{
    static ll a = 0, b = 1, c;
    if (n > 0)
    {
        c = a + b;
        a = b;
        b = c;
        printf("%lld ", c);
        fib(n - 1);
    }
}

// b )
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
// c)
void permute(int *a, int i, int n)
{
    int j, temp;
    if (i == n)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%d", a[j]);
        }
        printf("\n");
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            permute(a, i + 1, n);
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

// d)
int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 10 + sum(n / 10));
}

// e)
void decToBin(int n)
{
    if (n == 0)
        return;
    else
    {
        decToBin(n / 2);
        printf("%d", n % 2);
    }
}

// f)
double cos(int n, int x)
{
    static int i = 1;
    double s;
    if (n == 0)
        return 1;
    else
    {
        s = cos(n - 1, x);
        i += 2;
        return (-s * x * x) / i * (i - 1);
    }
}

int main()
{
    // menu driven program
    while (1)
    {
        int ch, n, a, b, x, arr[200];
        printf("1. Fibonacci series\n");
        printf("2. GCD of two numbers\n");
        printf("3. Permutations of n numbers\n");
        printf("4. Sum of digits of a number\n");
        printf("5. Decimal to binary\n");
        printf("6. Cos series\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of terms: ");
            scanf("%d", &n);
            printf("Fibonacci series: ");
            fib(n);
            printf("\n");
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("GCD of %d and %d is %d", a, b, gcd(a, b));
            printf("\n");
            break;
        case 3:
            printf("Enter the number of elements: ");
            scanf("%d", &n);

            printf("Enter the elements: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("Permutations are: \n");
            permute(arr, 0, n - 1);
            break;

        case 4:
            printf("Enter the number: ");
            scanf("%d", &n);
            printf("Sum of digits of %d is %d", n, sum(n));
            printf("\n");
            break;
        case 5:
            printf("Enter the number: ");
            scanf("%d", &n);
            printf("Binary representation of %d is ", n);
            decToBin(n);
            printf("\n");
            break;
        case 6:
            printf("Enter the number of terms: ");
            scanf("%d", &n);
            printf("Enter the value of x: ");
            scanf("%d", &x);
            printf("Cos series: ");
            for (int i = 0; i < n; i++)
            {
                printf("%lf ", cos(i, x));
            }
            printf("\n");
            break;
        case 7:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
