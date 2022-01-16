#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/select.h>
#include<stdlib.h>
#include<fcntl.h>

void main()
{
  int fd;
  char buf[100];
  
  fd = open("myfifo", O_RDONLY);
  read(fd, buf, sizeof(buf));
  printf("Entered text is : %s\n", buf);
  
}
