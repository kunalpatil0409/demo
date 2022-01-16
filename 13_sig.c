#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
  
void main()
{
   int pid;
   printf("Enter Process ID : ");
   scanf("%d", &pid);
   kill(pid,SIGSTOP);
   printf("SIGSTOP sent to process ID: %d \n", pid);
}


