#include <stdio.h>

#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex;

void * DoSomeThing(void *arg){
    int d= *(int *)arg;
     sem_wait(&mutex);
     //decrease the mutex int value
     //If the value of the semaphore is negative, the calling process blocks;
     // one of the blocked processes wakes up when another process calls sem_post.

     printf("%d  \n",d);


     sem_post(&mutex);
}
int main(){
    int n;
    n=10;
    pthread_t pid[n];
    if(sem_init(&mutex, 0, 5) == -1)
    {
        perror("Could not initialize mylock semaphore");
        exit(2);
    }
    for(int i=0;i<n;i++){
         pthread_create(&pid[i], NULL,DoSomeThing , (void*)& i);
    }
    for(int i=0;i<n;i++){
        pthread_join(pid[i], NULL);
         //pthread_create(&pid[i], NULL,DoSomeThing , NULL);
    }

}
