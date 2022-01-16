#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{
    int fd,fd1;
    char buff1[100], buff2[100];
    
    fd = open("myfifo", O_WRONLY);
    fd1 = open("myfifo1", O_RDONLY);
    
    printf("Enter the text : ");
    scanf(" %[^\n]",buff1);
    write(fd,buff1,sizeof(buff1));
    
    read(fd1, buff1, sizeof(buff1));
    printf("Text from myfifo: %s\n",buff1);
}

/*
patil@patil-Aspire-A515-51G:~/Documents/Test$ cc -o write 21_w.c
patil@patil-Aspire-A515-51G:~/Documents/Test$ cc -o read 21_r.c
patil@patil-Aspire-A515-51G:~/Documents/Test$ ./write
Enter the text : hello
Text from myfifo: hii !
*/
