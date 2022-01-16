#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void main()
{
   pid_t ppid=getpid();
   pid_t pid=fork();
   
   if(pid==-1)
   {
     perror("Error occured\n");
   }
   else if(pid>0)
   {
     //sleep(101);
     printf("Parent Process executed\n");                      //parent process exited
     exit(1);
   }
   else if(pid==0)
   {
     int g=getpid();
     printf("%d\n",g);
     printf("%d\n",ppid);
     kill(ppid,SIGKILL);
     sleep(31);                                               //child process still alive ,thus orphan process created
     printf("Child Process executed\n");
     
     exit(1);
   }
}
