#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

void main()
{
    char buff[100];
    int i,j,pipedes[2];
    i = pipe(pipedes);
    printf("i=%d\n",i);
    j = write(pipedes[1], "Hello\n", 7);
    read(pipedes[0], buff, j);
    printf("From pipd : %s\n", buff);
}
