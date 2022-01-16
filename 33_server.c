#include <sys/types.h>         
#include <sys/socket.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>


void main()
{
   struct sockaddr_in serv, cli;
   int sd, sz, nsd;
   char buf[80];
   sd = socket(AF_UNIX, SOCK_STREAM, 0);
   
   serv.sin_family = AF_UNIX;
   serv.sin_addr.s_addr = INADDR_ANY;
   serv.sin_port = htons(5546);
   
   bind(sd,(void *)(&serv), sizeof(serv));
   
   listen(sd,5);
   sz = sizeof(cli);
   nsd = accept(sd,(void *)(&cli),&sz);
   read(nsd, buf, sizeof(buf));
   printf("Message from client : %s\n", buf);
   write(nsd, "ACK from serber\n", 17);
}

/*
patil@patil-Aspire-A515-51G:~/Documents/Test$ gcc 33_client.c
patil@patil-Aspire-A515-51G:~/Documents/Test$ ./a.out
Message from server : ACK from serber

*/
