#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>

void main()
{
   
   key_t key = ftok(".",'a');
   int h = msgget(key, IPC_CREAT | IPC_EXCL | 0744);
   
   printf("Key : %d\n", key);
   printf("Key value in hex 0x%0x\n",key);
   printf("Message UID : %d\n", h);
}


/*
patil@patil-Aspire-A515-51G:~/Documents/Test$ ./a.out
Key : 1627718721
Key value in hex 0x61050441
Message UID : -1
patil@patil-Aspire-A515-51G:~/Documents/Test$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61050441 0          patil      744        2            2           

*/
