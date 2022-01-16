#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/select.h>
#include<stdlib.h>
#include<fcntl.h>

void main()
{

    int fd, retval;
    char buf[100];
    fd_set rfds;
    struct timeval tv;
    
    fd = open("myfifo", O_RDONLY);
    FD_ZERO(&rfds);                       //clears a set
    FD_SET(fd,&rfds);                     //add fd to set
    tv.tv_sec=10;
    tv.tv_usec=0;
    
    retval = select(fd+1, &rfds, NULL, NULL , &tv);
    if(retval)
    {
      printf("Data is available now..\n");
    }
    else
    {
      printf("No data available within 10 secs.\n");
      exit(0);
    }
    
    read(fd, buf, sizeof(buf));
    printf("The test from FIFO : %s\n", buf);
}
