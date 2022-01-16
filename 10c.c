#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void my_handler(int signum)
{
    printf("Inside Handler\n");
    exit(1);
}

int main()
{
    struct sigaction my_action;
    int i,j;
    my_action.sa_handler = my_handler;
    my_action.sa_flags = SA_RESTART;
    sigaction (SIGFPE, &my_action, NULL);
    
     i=0;
     j=10/i;

    return 0;
}

