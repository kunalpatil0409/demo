#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void my_handler (int sig); /* function prototype */

int main()
 {

/* Part I: Catch SIGINT */
    signal (SIGINT, my_handler);
    printf ("Catching SIGINT\n");
    sleep(3);
    printf (" No SIGINT within 3 seconds\n");

/* Part II: Ignore SIGINT */
    signal (SIGINT, SIG_IGN);
    printf ("Ignoring SIGINT\n");
    sleep(3);
    printf ("No SIGINT within 3 seconds\n");

/* Part III: Default action for  SIGINT */
    signal (SIGINT, SIG_DFL);
    printf ("Default action for SIGINT\n");
    sleep(3);
    printf ("No SIGINT within 3 seconds\n");
    return 0;
}

/* User-defined signal handler function */
void my_handler (int sig) {
    printf ("I got SIGINT, number %d\n", sig);
    exit(0);
}
