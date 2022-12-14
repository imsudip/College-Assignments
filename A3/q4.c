// write a program which takes two dates (dd/mm/yyyy) as input and prints if they are equal or not.

#include <stdio.h>

int main()
{
    int d1, m1, y1, d2, m2, y2;
    printf("Enter the first date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d1, &m1, &y1);
    printf("Enter the second date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d2, &m2, &y2);
    if (d1 == d2 && m1 == m2 && y1 == y2)
        printf("The dates are equal");
    else
        printf("The dates are not equal");
    printf("\n");
    return 0;
}