#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_rwlock_t g_lock;

void* thread_fun_read_lock(void *arg);
void* thread_fun_write_lock(void *arg);

void main_rwlock_read_lock();
void main_rwlock_write_lock();
void main_rwlock_read_and_write_lock();

int main(void)
{
    // init rwlock
    pthread_rwlock_init(&g_lock,NULL);
    
    // test 1
    main_rwlock_read_lock();
    
    // test 2
    main_rwlock_write_lock();
    
    // test 3
    main_rwlock_read_and_write_lock();
    
    // destroy lock
    pthread_rwlock_destroy(&g_lock);    
    
    printf("output: done!\n");
    
    return 0;
}

void main_rwlock_read_lock()
{
    printf("=========== main_rwlock_read_lock ================\n");
    
    pthread_t ptid;
    void *prc;
    
    printf("main: create thread\n");
    pthread_create(&ptid,NULL,thread_fun_read_lock,NULL);
    
    usleep(200);
    printf("main: rdlock\n");
    pthread_rwlock_rdlock(&g_lock);
    printf("main: get lock\n");
    
    
    usleep(200);
    printf("main: unlock\n");
    pthread_rwlock_unlock(&g_lock);
 
    printf("main: join\n");
    pthread_join(ptid,&prc);
    
    printf("main: child thread exit id=%d\n\n", *(int*)prc);
}


void main_rwlock_write_lock()
{
    printf("=========== main_rwlock_write_lock ================\n");
    
    pthread_t ptid;
    void *prc;
    
    printf("main: create thread\n");
    pthread_create(&ptid,NULL,thread_fun_write_lock,NULL);
    
    usleep(200);
    printf("main: wrlock\n");
    pthread_rwlock_wrlock(&g_lock);
    printf("main: get lock\n");
    
    usleep(200);
    printf("main: unlock\n");
    pthread_rwlock_unlock(&g_lock);
 
    printf("main: join\n");
    pthread_join(ptid,&prc);
    
    printf("main: child thread exit id=%d\n\n", *(int*)prc);
}

void main_rwlock_read_and_write_lock()
{
    printf("=========== main_rwlock_read_and_write_lock ================\n");
        
    pthread_t ptid1,ptid2;
	void *prc1, *prc2;
    
    printf("main: create thread #1\n");
	pthread_create(&ptid1,NULL,thread_fun_read_lock,NULL);
    
    printf("main: create thread #2\n");
	pthread_create(&ptid2,NULL,thread_fun_write_lock,NULL);
	
	usleep(200);
    printf("main: rdlock\n");
	pthread_rwlock_rdlock(&g_lock);    
    printf("main: get lock\n");
    
	usleep(200);
    printf("main: unlock\n");
	pthread_rwlock_unlock(&g_lock);

	pthread_join(ptid1,&prc1);
	printf("main: thread #1 exit id= %d\n", *(int*)prc1);
	
    pthread_join(ptid2,&prc2);
    printf("main: thread #2 exit id= %d\n", *(int*)prc2);
}


void* thread_fun_read_lock(void *arg)
{    
    printf("new :#1 rdlock\n");
    pthread_rwlock_rdlock(&g_lock);
    printf("new :#1 get lock\n");
    
    usleep(200);
    printf("new :#1 unlock\n");
    pthread_rwlock_unlock(&g_lock);    

    int* prc = (int*) malloc( sizeof(int));
    *prc = 1;    
    return (void*) prc;
}


void* thread_fun_write_lock(void *arg)
{    
    printf("new :#2 wrlock\n");
    pthread_rwlock_wrlock(&g_lock);
    printf("new :#2 get lock\n");
    
    usleep(200);
    printf("new :#2 unlock\n");
    pthread_rwlock_unlock(&g_lock);    

    int* prc = (int*) malloc( sizeof(int));
    *prc = 2;    
    return (void*) prc;
}
