#include <sys/types.h>         
#include <sys/socket.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(int argc,char * argv[])
{
   struct sockaddr_in serv;
   int sd;
   char buf[80];
   sd = socket(AF_UNIX,SOCK_STREAM,0);
   
   serv.sin_family = AF_UNIX;
   serv.sin_addr.s_addr = INADDR_ANY;
   serv.sin_port = htons(9090);
   
   connect(sd,(void *)(&serv), sizeof(serv));
   write(sd, "Hello server\n", 14);
   read(sd, buf, sizeof(buf));
   printf("Message from server : %s\n", buf);
}

