#include <sys/resource.h> 
 #include <sys/time.h> 
 #include <unistd.h> 
 #include<stdio.h> 
  
 void main () 
 { 
   // Define and object of structure 
   // rlimit. 
   struct rlimit rl; 
  
   int h = getrlimit (RLIMIT_CPU, &rl); 
   if(h==-1)
   {
     perror("Error\n");
   }
  
   printf("\n Default value is : %lld\n", (long long int)rl.rlim_cur); 
  
}
