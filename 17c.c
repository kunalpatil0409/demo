#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>


void main()
{
  
  int fd[2];
  pipe(fd);
  
  if(!fork())
  {
    close(1);
    close(fd[0]);
    fcntl(fd[1], F_DUPFD, 0);
    execlp("ls", "ls", "-l", (char*) NULL);
  }
  else
  {
    close(0);
    close(fd[1]);
    fcntl(fd[0], F_DUPFD, 0);
    execlp("wc", "wc",(char*) NULL);
  }
}



/*
patil@patil-Aspire-A515-51G:~/Documents/Test$ gcc 17c.c
patil@patil-Aspire-A515-51G:~/Documents/Test$ ./a.out
     11      92     493
patil@patil-Aspire-A515-51G:~/Documents/Test$ ls -l | wc
     11      92     493
*/
