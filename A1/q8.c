// Write a program to compute the following series:
// 𝑠𝑖𝑛(𝑥) = 𝑥 − 𝑥3/3! + 𝑥5/5! − 𝑥7/7! ...
// cos(x) = 1 − 𝑥2/2! + 𝑥4/4! − 𝑥6/6! ...
// log(1 + x) = x − 𝑥2/2 + 𝑥3/3 − 𝑥4/4 ...
// e =  1/1! + 2/2! + 3/3! + 4/4! + 5/5! + ...
// 2*3 + 3*5 + 5*7 + ...

#include <stdio.h>
#include <math.h>
typedef long long int ll;
typedef long double ld;
ll factorial(int n)
{
    ll fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
ll getNextPrime(ll prevPrime)
{
    ll nextPrime = prevPrime + 1;
    while (1)
    {
        int flag = 1;
        for (ll i = 2; i <= nextPrime / 2; i++)
        {
            if (nextPrime % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            return nextPrime;
        }
        nextPrime++;
    }
}

int main()
{
    while (1)
    {
        int choice;
        printf("Enter 1 for sin(x)\n");
        printf("Enter 2 for cos(x)\n");
        printf("Enter 3 for log(1+x)\n");
        printf("Enter 4 for e\n");
        printf("Enter 5 for 2*3 + 3*5 + 5*7 + ...\n");
        printf("Enter 0 to exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            float x, result = 0;
            printf("Enter the value of x: ");
            scanf("%f", &x);
            float term = x;

            for (int i = 0; i < 500; i++)
            {

                result += term;
                term *= -1 * x * x / ((2 * i + 3) * (2 * i + 2));
            }
            printf("sin(%f) = %f", x, result);
            break;
        }
        case 2:
        {
            double x, result = 0;
            printf("Enter the value of x: ");
            scanf("%lf", &x);
            double term = 1;
            for (int i = 0; i < 150; i++)
            {
                result += term;
                term *= -1 * x * x / ((2 * i + 2) * (2 * i + 1));
            }
            printf("cos(%lf) = %lf", x, result);
            break;
        }
        case 3:
        {
            float result = 0;
            double x;
            printf("Enter the value of x: ");
            scanf("%lf", &x);
            for (int i = 1; i < 100; i++)
            {
                if (i % 2 == 0)
                {
                    result -= pow(x, i) / i;
                }
                else
                {
                    result += pow(x, i) / i;
                }
            }
            printf("log(1 + %lf) = %f", x, result);
            break;
        }
        case 4:
        {
            float result = 0.0;
            int n;
            printf("Enter the total terms: ");
            scanf("%d", &n);

            for (int i = 1; i <= n; i++)
            {
                ld term = 1.0;
                for (int j = 1; j <= i - 1; j++)
                {
                    term *= j;
                }
                result += 1 / term;
            }

            printf("e = %f", result);
            break;
        }
        case 5:
        {
            int n;
            ll result = 0;
            printf("Enter the total terms: ");
            scanf("%d", &n);
            ll prevPrime = 2;
            for (int i = 1; i <= n; i++)
            {
                ll nextPrime = getNextPrime(prevPrime);
                result += prevPrime * nextPrime;
                prevPrime = nextPrime;
            }
            printf("2*3 + 3*5 + 5*7 + ... = %lld", result);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            printf("Invalid choice");
            break;
        }
        }

        printf("\n\n");
    }
    return 0;
}
