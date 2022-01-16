#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include <sys/stat.h>


int main()
{
    int val=mkfifo("demo1e",0777);
    if(val == -1)
        perror("Error");
    else printf("FIFO file was created successfully\n");
    return 0;
}
