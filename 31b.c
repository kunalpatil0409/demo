#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>

union semun
{
  int val;
  struct semid_ds *buf;
  unsigned short int *array;
};

void main()
{

  union semun arg;
  int key, semid;
  
  key = ftok(".",'a');
  semid = semget(key, 1, IPC_CREAT | 0644);
  arg.val = 2;              // 2 for Counting Semaphore
  
  semctl(semid, 0, SETVAL, arg);
}
