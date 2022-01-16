#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/types.h>


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
  arg.val = 1;         // 1 for Binary semaphore
  
  semctl(semid, 0, SETVAL, arg);
}
