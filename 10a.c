#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_handler (int sig,siginfo_t *si, void *unused); /* function prototype */


void main()
{

    struct sigaction my_action;
    int *ptr=NULL;
    long a;
/*SIGSEGV */

    my_action.sa_sigaction = my_handler;
    my_action.sa_flags = SA_RESTART;
    sigaction (SIGSEGV, &my_action, NULL);
    printf ("Catching SIGSEGV\n");
    a = *ptr;
    sleep(3);
    printf (" No SIGSEGV within 3 seconds\n");
}

void my_handler (int sig,siginfo_t *si, void *unused) {
    printf ("Got SIGSEGV at address: 0x%lx\n",(long) si->si_addr);
    exit(0);
}
