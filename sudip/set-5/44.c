#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MUTEX 0
#define WRT 1

#define PERMS 0666
#define RAND_RANGE 25

#define S_KEY 101
#define READ_COUNT_KEY 102
#define ITEM_KEY 103

void sem_wait(int *sem)
{
    while ((*sem) <= 0)
        ;
    (*sem)--;
}

void sem_signal(int *sem) { (*sem)++; }

int main()
{
    key_t S_key = S_KEY;
    key_t shm_read_count_key = READ_COUNT_KEY;
    key_t shm_item_key = ITEM_KEY;

    size_t S_id = shmget(S_key, sizeof(int) * 2, IPC_CREAT | PERMS);
    size_t shm_read_count_id =
        shmget(shm_read_count_key, sizeof(int), IPC_CREAT | PERMS);
    size_t shm_item_id = shmget(shm_item_key, sizeof(int), IPC_CREAT | PERMS);

    int *S = shmat(S_id, NULL, 0);
    int *shm_read_count = shmat(shm_read_count_id, NULL, 0);
    int *shm_item = shmat(shm_item_id, NULL, 0);

    pid_t pid;

    srand(time(NULL));

    S[MUTEX] = 1;
    S[WRT] = 1;

    *shm_read_count = 0;
    *shm_item = 0;

    pid = fork();

    if (pid == 0)
    {
        /* reader */
        while (1)
        {
            sem_wait(&S[MUTEX]);
            (*shm_read_count)++;

            if (*shm_read_count == 1)
                sem_wait(&S[WRT]);

            sem_signal(&S[MUTEX]);

            printf("Reader <= %d\n", *shm_item);

            sem_wait(&S[MUTEX]);
            (*shm_read_count)--;

            if (*shm_read_count == 0)
                sem_signal(&S[WRT]);

            sem_signal(&S[MUTEX]);
            sleep(1);
        }

        shmdt(S);
        shmdt(shm_read_count);
        shmdt(shm_item);

        exit(0);
    }

    /* writer */
    while (1)
    {
        sem_wait(&S[WRT]);

        *shm_item = rand() % RAND_RANGE;

        printf("\nWriter => %d\n", *shm_item);

        sem_signal(&S[WRT]);
        sleep(3);
    }

    return 0;
}