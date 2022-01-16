#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>

void main()
{
  
   int msgid, size;
   key_t key;
   
   struct msg
   {
     long int mtype;
     char message[80];
   }mq;
   
   key = ftok(".",'a');
   msgid = msgget(key,0);
   
   printf("Enter the message type to receive : ");
   scanf("%ld", &mq.mtype);
   
   msgrcv(msgid, &mq, sizeof(mq.message), mq.mtype, 0);
   printf("Message type : %ld", mq.mtype);
   printf("Message text : %s\n", mq.message);
}
  
