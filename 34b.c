#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <pthread.h>

void *handler(void *nsd)
{
   char buf[50];
   int *newSD = (int *)nsd;                                   //nsd = new socket descriptor
   read(*newSD, buf, sizeof(buf));
   printf("Message from client : %s\n", buf);
   write(*newSD, "ACK from server\n", 17);
   close(*newSD);
}

void main()
{
   struct sockaddr_in serv,cli;
   int sd, sz, nsd;
   
   sd = socket(AF_UNIX, SOCK_STREAM, 0);
   
   serv.sin_family = AF_UNIX;
   serv.sin_addr.s_addr = INADDR_ANY;
   serv.sin_port = htons(9090);
   
   bind(sd, (void *)(&serv), sizeof(serv));
   
   listen(sd,5);
   perror("listen");
   while(1)
   {
     sz = sizeof(cli);
     nsd = accept(sd, (void *)(&cli), &sz);
     pthread_t thread;
     int ret = pthread_create(&thread, NULL, handler, &nsd);
     if(ret==-1)
     {
        perror("Thread");
     }
   }
}


// Use cc 34b.c -lpthread

