#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include <sys/stat.h>

int main()
{
    int val=mknod("19demo", S_IFIFO|0666, 0);
    if(val == -1)
        perror("Error");
    else printf("FIFO was created successfully\n");
    return 0;
}
