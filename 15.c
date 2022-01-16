#include<stdio.h>
#include<sys/wait.h>
#include <unistd.h>


void main()
{
   char buff[100];
   int fd[2];
   
   pipe(fd);
   
   if(fork())
   {
      close(fd[0]); //closing the read end of 1st pipe
      printf("Enter message to the child : ");
      scanf("%[^\n]",buff);
      write(fd[1],buff, sizeof(buff));
   }
   else
   {
     close(fd[1]); //closing the write end of 1st pipe
     read(fd[0],buff,sizeof(buff));
     printf("Message from parent: %s\n",buff);
   }
}
