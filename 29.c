#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>

void main()
{
  key_t key;
  int msgid;
  
  key = ftok(".", 'a');
  msgid = msgget(key,0);
  
  msgctl(msgid, IPC_RMID, 0);
}

/*
patil@patil-Aspire-A515-51G:~/Documents/Test$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61050441 0          500        700        0            0           
0x6c050441 1          patil      0          0            0           

patil@patil-Aspire-A515-51G:~/Documents/Test$ gcc 29.c
patil@patil-Aspire-A515-51G:~/Documents/Test$ ./a.out
patil@patil-Aspire-A515-51G:~/Documents/Test$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x6c050441 1          patil      0          0            0           

*/
