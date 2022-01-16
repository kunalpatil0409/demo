#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{
    int fd,fd1;
    char buff1[100], buff2[100];
    
    fd = open("myfifo", O_RDONLY);
    fd1 = open("myfifo1", O_WRONLY);

    read(fd, buff2, sizeof(buff2));
    printf("Text from myfifo: %s\n",buff2);

    printf("Enter the text : ");
    scanf(" %[^\n]",buff1);
    write(fd1,buff1,sizeof(buff1));
    
    
    
}


/*
patil@patil-Aspire-A515-51G:~/Documents/Test$ ./read
Text from myfifo: hello
Enter the text : hii !
*/
