#include <pthread.h>
#include <stdio.h>
#include <signal.h>

/*void thread_func(void)
{
   printf("Thread ID is : %ld", pthread_self());
}*/
int i=1;
void* foo(void* p){
    int i = *(int*) p;
    printf("Received value: %i", i);
    
    // Return reference to global variable:
    pthread_exit(&i);
}
void main()
{
  pthread_t mythread;
  pthread_create(&mythread, NULL, foo, NULL);
}
  
