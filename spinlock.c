#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include<bits/types.h>
#include<errno.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockthread(void *i)
{
int rc;
int count=0;
printf("Entered thread %d ,getting spin lock\n",(int *)i);
rc=pthread_spin_lock(&spinlock);
printf("wait spinlock thread holding lock");
sleep(5);

printf("%d thread unlock the spin lock\n",(int *)i);
rc=pthread_spin_unlock(&spinlock);
printf("%d thread complete\n",(int *)i);
return NULL;
}


int main(){

int rc=0;
pthread_t thread,thread1;
if(pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE)!=0)
perror("init");
printf("Main get spin lock\n");
rc=pthread_spin_lock(&spinlock);

printf("main create the spinlock thread\n");
rc=pthread_create(&thread,NULL,spinlockthread,(int *)1);

printf("main wait a bit holding the spin lock\n");
sleep(10);
printf("main now unlock the spin lock\n");
rc=pthread_spin_unlock(&spinlock);
if(rc==0)
printf("\n main thread successfully unlocked\n");
else 
printf("\n main thread successfully unlocked\n");

printf("main wait for the thread to end\n");
rc=pthread_join(thread,NULL);
printf("main completed\n");


return 0;
}
