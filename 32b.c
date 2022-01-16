#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include<fcntl.h>
#include <time.h>

void main()
{
  int shmid;
  key_t key;
  char *data;
  
  int semid;
  key=ftok(".",'z');
  struct sembuf buf = {0,-1,0} ; 
  if((semid = semget(key, 1 , IPC_CREAT | IPC_EXCL | 0766 )) != -1)
  {
     semctl(semid, 0, SETVAL, 1);
  }
  else
  {
     semid = semget(key, 1, 0);
  }
  
  printf("semid : %d\n",semid);
  
  printf("Before entering shared memory\n");
  printf("Waiting to unlock..\n");
  semop(semid,&buf,1);
  printf("Inside Shared Memory\n");
  shmid = shmget(key,1024,IPC_CREAT | 0744);
  data = shmat(shmid,0,0);
  printf("Entered shared memory\n ");
  printf("Enter data : ");
  scanf("%[^\n]",data);
  printf("Shared memory content : %s\n",data);
  printf("Press Enter to unlock\n");
  getchar();
  getchar();
  buf.sem_op=1;
  semop(semid,&buf,1);
  printf("Unlocked\n");

}
