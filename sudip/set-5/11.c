#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>

#define SHM_SIZE 100 * sizeof(int) // Size of shared memory segment

// Structure for holding result
typedef struct
{
    int max;
    int min;
    double avg;
} Result;

// Function to compute the maximum, minimum, and average of an array of integers
Result compute_stats(int *numbers)
{
    Result result;
    int sum = 0;
    result.max = result.min = numbers[0];

    for (int i = 0; i < 100; i++)
    {
        int num = numbers[i];
        printf("%d ", num);
        sum += num;

        if (num > result.max)
            result.max = num;

        if (num < result.min)
            result.min = num;
    }

    result.avg = (double)sum / 100.0;

    return result;
}

int main()
{
    int shm_id;
    int *shared_memory;
    Result *result;
    pid_t pid;

    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);

    // Attach the shared memory segment
    shared_memory = (int *)shmat(shm_id, NULL, 0);

    // Fork a child process
    pid = fork();

    if (pid == 0)
    {
        // Child process

        // Wait for the parent to write data
        while (shared_memory[100] == 0)
            usleep(1000);

        // Compute statistics
        Result child_result = compute_stats(shared_memory);

        // Write the result to shared memory
        result = (Result *)(shared_memory + 101);
        *result = child_result;

        exit(0);
    }
    else
    {
        // Parent process
        srand(time(0));
        // Generate random numbers and write them to shared memory
        for (int i = 0; i < 100; i++)
        {
            int x = rand() % 1000;
            shared_memory[i] = x;
        }

        // Signal the child that the data is ready
        shared_memory[100] = 1;

        // Wait for the child to finish computing
        wait(NULL);

        // Read the result from shared memory
        result = (Result *)(shared_memory + 101);

        // Display the result
        printf("Maximum: %d\n", result->max);
        printf("Minimum: %d\n", result->min);
        printf("Average: %.2f\n", result->avg);
    }

    return 0;
}
