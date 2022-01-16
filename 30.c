#include<stdio.h>
#include<sys/shm.h>

void main()
{
   int key,shmid,choice;
   char *ptr;
   
   key = ftok(".", 'g');
   shmid = shmget(key,1024,IPC_CREAT | 0744);
   //printf("%d\n",shmid);
   ptr = shmat(shmid,0,0);
   
   printf("Menu for shared memory : \n");
   printf("Reading : 1 \nWriting : 2 \nDetach Shared memory : 3 \nRemove shared memory : 4\n ");
   
   printf("Enter your choice : ");
   scanf("%d",&choice);
   
   switch(choice)
   {
     case 1:
          printf("Reading shared memory segment : %s\n",ptr);
          break;
     
     case 2:
          printf("Enter : ");
          scanf(" %[^\n]", ptr);
          break;
     case 3:
          shmdt(ptr);
     case 4:
          shmctl(shmid, IPC_RMID, NULL);
   }
} 
