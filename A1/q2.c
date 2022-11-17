// In a banking system, there are the following denominations of notes: Rs. 10, Rs. 20. Rs.
// 50. Rs. 100. Write a program that will accept an amount and find the minimum number of
// each note required to pay the amount.

#include <stdio.h>

int main()
{
    int amount, note_100, note_50, note_20, note_10;

    printf("Enter amount: ");
    scanf("%d", &amount);

    note_100 = amount / 100;
    amount = amount % 100;

    note_50 = amount / 50;
    amount = amount % 50;

    note_20 = amount / 20;
    amount = amount % 20;

    note_10 = amount / 10;
    amount = amount % 10;

    if (amount != 0)
    {
        printf("NOT POSSIBLE\n");
        return 0;
    }

    printf("100 x %d \n", note_100);
    printf("50 x %d \n", note_50);
    printf("20 x %d \n", note_20);
    printf("10 x %d \n", note_10);

    return 0;
}