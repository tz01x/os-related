#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<math.h>
#define null NULL
typedef struct node{
int upper,lower
}node;

void *doMath(void *arg){
 node a=*(  node *) arg;
//printf(" upper -> %d \n",a->upper);
//printf(" lower -> %d \n",a->lower);
//printf("\n");

for(int i=a.lower+1;i<a.upper;i++){
if(i%3==0){
//printf("->%d ",i);
}
}
pthread_exit(0);
}


int main(int argc,char *args[]){
//time
srand(time(null));
clock_t start,e;

int n=10;//number of thread
int delT=atoi(args[1])/n;//convert argument to int  and divide by number of thread
int a=0,b=0;

struct node temp;
pthread_t tid[n];


pthread_attr_t tattr;//initilaize attr
pthread_attr_init(&tattr);//register the attribute

start=clock();

for(int i=0;i<n;i++){

    b=a+delT;
    //a=b;
    temp.lower=a+1;
    temp.upper=b;
    pthread_create(&tid[i],&tattr,doMath,(void *) &temp);

    a=b;
}

for(int i=0;i<n;i++)
	pthread_join(tid[i],null);

e=clock();
printf("\n\ntotal secound %lf",((double)e-(double)start)/CLOCKS_PER_SEC);

//printf("\nend value: %ld \n",e);
return 0;

}
