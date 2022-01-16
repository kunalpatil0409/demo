#include <sys/msg.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>


struct ipc_perm msg_perm;
struct msqid_ds mq;
struct msginfo info;

void main()
{

   key_t key;
   int msgid;
   
   key = ftok(".", 'l');
   msgid = msgget(key,IPC_CREAT);
   msgctl(msgid , IPC_STAT, &mq);
   //printf("%d",msgid);
   printf("Effective UID of creater = %d\n", msg_perm.cuid);
   printf("Effective UID of owner = %d\n", msg_perm.uid);
   printf("Effective GID of owner = %d\n", msg_perm.gid);
   printf("Effective GID of creater = %d\n", msg_perm.cgid);
   printf("Permission = %03o\n", mq.msg_perm.mode & 0777);
   printf("Current number of messages in queue = %lu\n", mq.msg_qnum);
   printf("PID of last message send = %d\n", mq.msg_lspid);
   printf("PID of last message recv = %d\n", mq.msg_lrpid);
   printf("Time of last msgsnd = %s", ctime(&mq.msg_stime));
   printf("Time of last msgrcv = %s", ctime(&mq.msg_rtime));
   printf("Time of last change = %s", ctime(&mq.msg_ctime));
   printf("Maximum number of bytes allowed in queue = %lu\n", mq.msg_qbytes);
   printf("Current number of bytes in queue = %lu\n", mq.msg_cbytes);
}
   
       
//message queue created in 24.c
