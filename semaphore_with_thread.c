#include<stdio.h>

#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>

sem_t syn;
sem_t syn2;
 struct node{
int a,b;
};
void *add(void *data){
    sem_wait(&syn);

    struct node *d=(struct node *)data;

//cout<<"a + b = "<<d->a+d->b<<endl;
printf("a + b = %d ",d->a+d->b);
pthread_exit(0);
}
void *subtract(void *data){
     struct node *d=(struct node *)data;
    sem_wait(&syn2);
//cout<<"a - b = "<<d->a-d->b<<endl;
printf("a - b = %d ",d->a-d->b);
pthread_exit(0);
}

int main(){
pthread_t pid,pid2;
struct node data;
int _do;
//cin>>data.a>>data.b>>_do;
scanf("%d%d%d",&data.a,&data.b,&_do);
  if(sem_init(&syn, 0, 0) == -1||sem_init(&syn2, 0, 0) == -1){
     perror("Could not initialize mylock semaphore");
     exit(2);
  }
  if(_do==1){
    sem_post(&syn);

  }else if(_do==2){
  sem_post(&syn);
  }
//   pthread_create(&tid[i],NULL,modof3,(void *) &temp);
  pthread_create(&pid,NULL,add,(void *)&data);
  pthread_create(&pid2,NULL,subtract,(void *)&data);
  pthread_join(pid,NULL);
  pthread_join(pid2,NULL);
    sem_destroy(&syn);
sem_destroy(&syn2);
/**
If the value of the semaphore is negative, the calling process blocks; one of the blocked processes wakes up when another process calls sem_post.
http://www.csc.villanova.edu/~mdamian/threads/posixsem.html
*/


}
