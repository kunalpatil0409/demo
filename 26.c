#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>

void main()
{
   key_t key;
   int msgid, size;
   struct msg
   {
     long int mtype;
     char message[100];
   }myq;
   
   key = ftok(".", 'a');
   msgid = msgget(key, IPC_CREAT);
   if(msgid==-1)
   {
     perror("Error");
   }
   printf("%d\n",key);
   printf("%d\n",msgid);
   printf("Enter a message type : ");
   scanf("%ld", &myq.mtype);
   printf("Enter message text : ");
   scanf(" %[^\n] ", myq.message);
   size = strlen(myq.message);
   printf("%d\n",size);
   msgsnd(msgid, &myq, size+1, 0);
}
