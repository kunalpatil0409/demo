#include<stdio.h>
#include<unistd.h>

void main()
{
  
  int fd[2];
  pipe(fd);
  
  if(!fork())
  {
    close(1);
    close(fd[0]);
    dup(fd[1]);
    execlp("ls", "ls", "-l", (char*) NULL);
  }
  else
  {
    close(0);
    close(fd[1]);
    dup(fd[0]);
    execlp("wc", "wc",(char*) NULL);
  }
}


/*
patil@patil-Aspire-A515-51G:~/Documents/Test$ gcc 17a.c
patil@patil-Aspire-A515-51G:~/Documents/Test$ ./a.out
     24     209    1082
patil@patil-Aspire-A515-51G:~/Documents/Test$ ls -l | wc
     24     209    1082
*/
