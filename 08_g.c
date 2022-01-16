#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <sys/time.h>

 
void sig_handler(int signum)
{
  printf("Inside handler function\n");
}
 
int main()
{
 
  struct itimerval tt;
   //First time
   tt.it_value.tv_sec=2;
   tt.it_value.tv_usec=0;
   
   //at every interval
   tt.it_interval.tv_sec=2;
   tt.it_interval.tv_usec=0;
 
  signal(SIGPROF ,sig_handler); // Register signal handler
 
  setitimer(ITIMER_PROF,&tt,NULL);
 
  for(int i=1;;i++){
 
    printf("%d : Inside main function\n",i);
    sleep(1);  // Delay for 1 second
   }
return 0;
}
