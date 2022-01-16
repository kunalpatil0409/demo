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
   struct msqid_ds mq;
   
   key = ftok(".", 'a');
   msgid = msgget(key,0);
   
   mq.msg_perm.uid = 500;
   mq.msg_perm.gid = 500;
   mq.msg_perm.mode = 0700;
   
   msgctl(msgid, IPC_SET, &mq);
}
