#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_handler (int sig); /* function prototype */

void main()
{

    signal (SIGSTOP, my_handler);
    printf ("Catching SIGSTOP\n");
    sleep(15);
    printf (" No SIGSTOP within 15 seconds\n");
}

void my_handler (int sig) {
    printf ("I got SIGSTOP, number %d\n", sig);
    exit(0);
}

