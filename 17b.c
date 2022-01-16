#include<stdio.h>
#include<unistd.h>

void main()
{
  
  int fd[2];
  pipe(fd);
  
  if(!fork())
  {
    close(fd[0]);
    dup2(fd[1],1);
    execlp("ls", "ls", "-l", (char*) NULL);
  }
  else
  {
    close(fd[1]);
    dup2(fd[0],0);
    execlp("wc", "wc",(char*) NULL);
  }
}

/*

patil@patil-Aspire-A515-51G:~/Documents/Test$ gcc 17b.c
patil@patil-Aspire-A515-51G:~/Documents/Test$ ./a.out
     10      83     444
patil@patil-Aspire-A515-51G:~/Documents/Test$ ls -l | wc
     10      83     444

*/

