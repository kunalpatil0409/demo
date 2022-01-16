#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <pthread.h>


void main()
{
   struct sockaddr_in serv,cli;
   int sd, client_len, client_sockfd;
   char buf[50];
   
   sd = socket(AF_UNIX, SOCK_STREAM, 0);
   
   serv.sin_family = AF_UNIX;
   serv.sin_addr.s_addr = INADDR_ANY;
   serv.sin_port = htons(9095);
   
   bind(sd, (void *)(&serv), sizeof(serv));
   
   listen(sd,5);
   perror("listen");
   
   while(1) {


       printf("server waiting\n");

        /* Accept connection. */

       client_len = sizeof(cli);
       client_sockfd = accept(sd,(void *)&cli, &client_len);

       /* Fork to create a process for this client and perform a test to see whether we're the parent or the child. */

       if(fork() == 0) {


       read(client_sockfd, buf,sizeof(buf));
       //sleep(5);
       printf("Message from client : %s\n", buf);
       write(client_sockfd, "ACK from server\n", 17);
       close(client_sockfd);
       exit(0);
     }

     else
     {
        close(client_sockfd);
     }
   }
}


// Use cc 34b.c -lpthread

