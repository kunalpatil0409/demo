#include <unistd.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <stdio.h>

struct ticketdb
{
   int tickno;
}tkt;

int main()
{
  int key,semid;
  key = ftok(".",'a');
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
  int fd = open("db.txt",O_CREAT | O_RDWR, 0777);
  perror("OPEN");
  read(fd,&tkt,sizeof(tkt));
  printf("Current ticket number + %d\n",tkt.tickno);
  printf("Before entering into the critical section\n");
  printf("Waiting to unlock....\n");
  semop(semid,&buf,1);
  printf("Inside critical section\n");
  printf("Enter to Unlock\n");
  getchar();
  tkt.tickno++;
  lseek(fd,0L,SEEK_SET);
  write(fd,&tkt,sizeof(tkt));
  perror("Write");
  printf("Ticket number updated : %d\n", tkt.tickno);
  buf.sem_op = 1;
  close(fd);
  semop(semid, &buf, 1);
  printf("Unlocked\n");
}
