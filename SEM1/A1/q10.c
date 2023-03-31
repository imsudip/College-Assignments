// 10. Write a program to find the reverse of any number & check whether the number is a
// palindrome or not.

#include <stdio.h>
void removeLeadingZeros(char *a, int *n)
{
    int i = 0, j;
    while (a[i] == '0')
    {
        i++;
    }
    for (j = 0; j < *n - i; j++)
    {
        a[j] = a[j + i];
    }
    a[j] = '\0';
    *n = *n - i;
}

int main()
{
    char str[100];
    printf("Enter a number: ");
    scanf("%s", str);
    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }
    removeLeadingZeros(str, &n);
    // reverse the string
    int j = n - 1;
    char strRev[100];
    int k = 0;
    while (j >= 0)
    {
        strRev[k] = str[j];
        j--;
        k++;
    }
    strRev[k] = '\0';
    removeLeadingZeros(strRev, &k);
    printf("Reverse of the number is %s \n", strRev);
    int flag = 0;
    j = 0;
    while (j < n)
    {
        if (str[j] != strRev[j])
        {
            flag = 1;
            break;
        }
        j++;
    }

    if (flag == 0)
    {
        printf("The number is a palindrome\n");
    }
    else
    {
        printf("The number is not a palindrome\n");
    }
}