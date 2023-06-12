
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MUTEX 0
#define FULL 1
#define EMPTY 2

#define BUFFER_SZ 5
#define PERMS 0666
#define RAND_RANGE 50

#define BUFF_KEY 101
#define S_KEY 102
#define BUFF_IDX_KEY 103

void sem_wait(int *sem)
{
  while ((*sem) <= 0)
    ;
  (*sem)--;
}

void sem_signal(int *sem) { (*sem)++; }

int main()
{
  key_t shm_buffer_key = BUFF_KEY;
  key_t S_key = S_KEY;
  key_t shm_buff_idx_key = BUFF_IDX_KEY;

  size_t shm_buffer_id =
      shmget(shm_buffer_key, sizeof(int) * 3, IPC_CREAT | PERMS);
  size_t S_id = shmget(S_key, sizeof(int) * BUFFER_SZ, IPC_CREAT | PERMS);
  size_t shm_buff_idx_id =
      shmget(shm_buff_idx_key, sizeof(int), IPC_CREAT | PERMS);

  int *shm_buffer = shmat(S_id, NULL, 0);
  int *S = shmat(shm_buffer_id, NULL, 0);
  int *shm_buff_idx = shmat(shm_buff_idx_id, NULL, 0);

  pid_t pid;
  int item;

  srand(time(NULL));

  S[MUTEX] = 1;
  S[FULL] = 0;
  S[EMPTY] = BUFFER_SZ;

  *shm_buff_idx = 0;

  pid = fork();

  if (pid == 0)
  {
    /* consumer */

    while (1)
    {
      sleep(1);

      sem_wait(&S[FULL]);

      sem_wait(&S[MUTEX]);
      item = shm_buffer[(*shm_buff_idx)--];
      printf("Consumer <= %d\n", item);
      sem_signal(&S[MUTEX]);

      sem_signal(&S[EMPTY]);
    }

    shmdt(S);
    shmdt(shm_buffer);

    exit(0);
  }

  /* producer */

  while (1)
  {
    item = rand() % RAND_RANGE;

    sleep(1);

    sem_wait(&S[EMPTY]);

    sem_wait(&S[MUTEX]);
    shm_buffer[++(*shm_buff_idx)] = item;
    printf("\nProducer => %d\n", shm_buffer[*shm_buff_idx]);
    sem_signal(&S[MUTEX]);

    sem_signal(&S[FULL]);
  }

  wait(NULL);

  shmdt(S);
  shmdt(shm_buffer);
  shmdt(shm_buff_idx);

  shmctl(shm_buffer_id, IPC_RMID, NULL);
  shmctl(S_id, IPC_RMID, NULL);
  shmctl(shm_buff_idx_id, IPC_RMID, NULL);

  return 0;
}