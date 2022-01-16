#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_handler (int sig); /* function prototype */

void main()
{

    struct sigaction my_action;

/* Part I: Catch SIGINT */

    my_action.sa_handler = my_handler;
    my_action.sa_flags = SA_RESTART;
    sigaction (SIGINT, &my_action, NULL);
    printf ("Catching SIGINT\n");
    sleep(3);
    printf (" No SIGINT within 3 seconds\n");
}

void my_handler (int sig)
{
    printf ("I got SIGINT, number %d\n", sig);
    exit(0);
}



