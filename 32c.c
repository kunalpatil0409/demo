#include<sys/ipc.h>
#include<stdio.h>
#include<sys/sem.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int semid;
int main(){
    int r;
    key_t key = ftok(".",'a');
 
    
    if((semid = semget(key, 1, IPC_CREAT|IPC_EXCL|0766)) != -1)
	{
		semctl(semid, 0, SETVAL, 2);
	}
	else
	{
		semid = semget(key, 1, 0);
	}
   
	printf("semid : %d\n",semid);
    
    r = semctl(semid,0,GETVAL,0);
    printf("semaphore :  %d\n",r);
    
    struct sembuf sem_op = { 0, -1, 0 };
    printf("Waiting for lock\n");
    r=semop(semid, &sem_op, 1);
    if(r==-1){printf("Lockfailed\n");return -1;}

    sem_op.sem_op = 1;
    printf("Press any key to unlock\n");
	getchar();
	semop(semid, &sem_op, 1);
	printf("unlocked\n");
    return 0;
    
}
