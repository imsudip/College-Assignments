#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// Function to check if a number is prime or not
int isPrime(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void display(int start, int end)
{
    for (int j = start; j <= end; j++)
    {
        if (isPrime(j))
        {
            printf("%d ", j);
        }
    }
}

int main()
{
    int start = 1;
    int end = 1000000;
    int num_processes = 10;
    int chunk_size = (end - start + 1) / num_processes;
    pid_t wpid;
    int status = 0;

    for (int i = 0; i < num_processes; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            int child_start = start + i * chunk_size;
            int child_end = child_start + chunk_size - 1;
            display(child_start,child_end);
            exit(0);
        }
    }

    for (int i = 0; i < num_processes; ++i)
    {
        wait(NULL);
    }

    return 0;
}