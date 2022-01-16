#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>

void main()
{
  key_t key;
  int msgid, ret;
  struct msg
  {
    long int mytype;
    char message[100];
  }myq;
  
  key = ftok(".",'a');
  msgid = msgget(key,0);
  printf("Enter a message type to receive : ");
  scanf("%ld", &myq.mytype);
  ret = msgrcv(msgid, &myq, sizeof(myq.message), myq.mytype, IPC_NOWAIT | MSG_NOERROR);
  
  if(ret == -1)
  {
    exit(-1);
  }
  
  printf("Message type : %ld\n Message : %s\n", myq.mytype, myq.message);
}
