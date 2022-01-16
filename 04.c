#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

unsigned long long rdtsc()
{
  unsigned long long dst;
  __asm__ __volatile__ ("rdtsc" : "=a"(dst));
}

void main()
{
   int nano;
   unsigned long long int start,end;
   start = rdtsc();
   for(int i=0;i<=100;i++)
   {
     getppid();                                              //returns the process ID of the parent of the calling  process.
   }
   end = rdtsc();
   nano = (end-start)/2.9;                                   //because processor frequency is 2903MHz
   printf("The function takes %d nano seconds\n", nano);
}
