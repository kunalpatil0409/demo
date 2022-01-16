#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void my_signal_handler(int sig)
{
    printf("Inside Signal Handler\n");
    
}

int main()
{
   signal(SIGSEGV, my_signal_handler); // initial set of signal handler
   printf ("Catching SIGINT\n");
    sleep(3);
    printf (" No SIGINT within 3 seconds\n");

}
