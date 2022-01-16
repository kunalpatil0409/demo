#include <sys/time.h>
#include<stdio.h> 

void main()
{
   struct itimerval tt;
   //First time
   tt.it_value.tv_sec=10;
   tt.it_value.tv_usec=10;
   
   //at every interval
   tt.it_interval.tv_sec=10;
   tt.it_interval.tv_usec=10;
   
   int n = setitimer(ITIMER_REAL,&tt,NULL);
   if(n!=0)
   {
      printf("Error\n");
   }
   
   while(1)
   {
     
   }
  
}
    
