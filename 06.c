#include <pthread.h>
#include <stdio.h>
#include <signal.h>

void * show(void * u)
{
  printf("New Thread\n");
}

int main()
{
   pthread_t tid;
   pthread_create(&tid, NULL, &show, NULL);
   pthread_create(&tid, NULL, &show, NULL);
   pthread_create(&tid, NULL, &show, NULL);
   pthread_join(tid,NULL);
   return 0;
}
