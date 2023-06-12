#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define MAX_ITERATIONS 10

#define P1_INDEX 0
#define P2_INDEX 1
#define P3_INDEX 2

// Semaphore operations
void sem_wait(int semid, int sem_num)
{
    struct sembuf sops = {sem_num, -1, 0};
    semop(semid, &sops, 1);
}

void sem_signal(int semid, int sem_num)
{
    struct sembuf sops = {sem_num, 1, 0};
    semop(semid, &sops, 1);
}

// Process functions
void P1(int semid, int *counter)
{
    while (*counter > 0)
    {
        sem_wait(semid, P1_INDEX);
        if (*counter <= 0)
            break;
        printf("A ");
        fflush(stdout);
        sem_signal(semid, P2_INDEX);
    }
    exit(0);
}

void P2(int semid, int *counter, int *turn)
{
    while (*counter > 0)
    {
        sem_wait(semid, P2_INDEX);
        if (*counter <= 0)
            break;
        if (*turn == 0)
        {
            printf("B ");
            fflush(stdout);
            sem_signal(semid, P3_INDEX);
        }
        else
        {
            printf("B\n");
            (*counter)--;
            *turn = 0;
            sem_signal(semid, P1_INDEX);
        }
    }
    exit(0);
}

void P3(int semid, int *counter, int *turn)
{
    while (*counter > 0)
    {
        sem_wait(semid, P3_INDEX);
        if (*counter <= 0)
            break;
        printf("C ");
        fflush(stdout);
        if (*turn == 0)
        {
            *turn = 1;
            sem_signal(semid, P3_INDEX);
        }
        else
        {
            sem_signal(semid, P1_INDEX);
        }
    }
    exit(0);
}

int main()
{
    int semid, shmid;
    int *counter;
    int *turn;

    // Create and initialize semaphores
    semid = semget(IPC_PRIVATE, 3, IPC_CREAT | 0666);
    semctl(semid, P1_INDEX, SETVAL, 1);
    semctl(semid, P2_INDEX, SETVAL, 0);
    semctl(semid, P3_INDEX, SETVAL, 0);

    // Create and attach shared memory for counter and turn
    shmid = shmget(IPC_PRIVATE, sizeof(int) * 2, IPC_CREAT | 0666);
    counter = (int *)shmat(shmid, NULL, 0);
    turn = counter + 1;

    *counter = MAX_ITERATIONS;
    *turn = 0;

    // Fork child processes
    pid_t pid;
    int i;
    for (i = 0; i < 2; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            if (i == 0)
            {
                P2(semid, counter, turn);
            }
            else if (i == 1)
            {
                P3(semid, counter, turn);
            }
        }
    }

    P1(semid, counter);

    // Wait for child processes to finish
    for (i = 0; i < 2; i++)
    {
        wait(NULL);
    }

    // Detach shared memory and remove semaphore
    shmdt(counter);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    return 0;
}
