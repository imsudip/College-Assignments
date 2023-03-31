// Q3. In a hotel, a professor lives in room no. X. The room numbers are sequentially numbered
//  from 1 to n (n can be any integer). The sum of the room numbers left to X is equal to the
//  sum of the room numbers to the right of X. Write a program to find X

#include <stdio.h>

int findRoom(int curr, int lastSum)
{
    if (curr == -1)
    {
        return -1;
    }
    int leftSum = (curr * (curr - 1)) / 2;
    if (leftSum == lastSum)
    {
        return curr;
    }
    return findRoom(curr - 1, lastSum + curr);
}

int main()
{
    int n;
    printf("Enter the number of rooms: ");
    scanf("%d", &n);
    int room = findRoom(n, 0);
    if (room == -1)
    {
        printf("No such room exists");
    }
    else
    {
        printf("Room number is %d", room);
    }
    printf("\n");
    return 0;
}
