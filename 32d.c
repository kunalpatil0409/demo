#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
  
    int semid;
    key_t key;
    
    key = ftok(".",'a');
    semid = semget(key,1,0);
    semctl(semid,IPC_RMID,0);
    perror("Delete");
}
    
