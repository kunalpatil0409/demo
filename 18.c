#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>

void main()
{
   int fd1[2],fd2[2];
   
   pipe(fd1);
   pipe(fd2);
   
   if(!fork())
   {
     dup2(fd1[1],1);
     close(fd1[0]);    //closing read end of pipe
     close(fd2[0]);
     close(fd2[1]);
     execlp("ls","ls","-Rl",(char*) NULL);
   }
   else
   {
     if(!fork())
     {
       dup2(fd1[0],0);   
       dup2(fd2[1],1);
       close(fd1[1]);
       close(fd2[0]);
       execlp("grep","grep","^d",(char*) NULL);
     }
     else
     {
       dup2(fd2[0],0);
       close(fd2[1]);
       close(fd1[0]);
       close(fd1[1]);
       execlp("wc","wc","-l", (char*) NULL);
     }
   }
}


/*
patil@patil-Aspire-A515-51G:~/Documents/Test$ gcc 18.c
patil@patil-Aspire-A515-51G:~/Documents/Test$ ./a.out
8
patil@patil-Aspire-A515-51G:~/Documents/Test$ mkdir i j k l
patil@patil-Aspire-A515-51G:~/Documents/Test$ ./a.out
12
patil@patil-Aspire-A515-51G:~/Documents/Test$ ls -Rl | grep ^d | wc -l
12
*/

   
