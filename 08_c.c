#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signum)
{
    printf("Inside Handler\n");
    exit(1);
}

int main()
{
    signal(SIGFPE, handler);

    int i, j;
    i=0;
    j = 9 / i;
    

    printf("After for loop");

    return 0;
}

