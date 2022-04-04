#include<pthread.h>
#include<stdio.h>
pthread_once_t once=PTHREAD_ONCE_INIT;
void *myinit()
{
printf("\n I am in init fun\n");
}
void *mythread(void *i)
{
printf("\i am in pthread:%d\n",(int *)i);
pthread_once(&once,(void*)myinit);
printf("\exit from mythread:%d\n",(int *)i);
}
int main()
{
pthread_t thread, thread1,thread2;
pthread_create(&thread,NULL,mythread,(void *)1);
pthread_create(&thread,NULL,mythread,(void *)2);
pthread_create(&thread,NULL,mythread,(void *)3);
printf("\n exit from main thread\n");
pthread_exit(NULL);
}

