#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate and print 100 random integers
    for (int i = 0; i < 100; i++)
    {
        int randomNum = rand();
        printf("%d\n", randomNum);
    }

    return 0;
}
