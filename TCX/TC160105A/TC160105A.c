#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond  = PTHREAD_COND_INITIALIZER;

void* thread1(void*);
void* thread2(void*);

int main(void)
{
    pthread_t t_a;
	pthread_t t_b;

	pthread_create(&t_a,NULL,thread2,(void *)NULL);
	pthread_create(&t_b,NULL,thread1,(void *)NULL);
	pthread_join(t_b, NULL);
    
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
    
    printf("output: done!\n");
    
    return 0;
}

void* thread1(void* arg)
{
	for(int i = 1; i <= 1; ++i)
	{
		pthread_mutex_lock(&mutex);
		
        printf("thread_1: pthread_cond_signal, i=%d\n", i);
        pthread_cond_signal( &cond );
        
		pthread_mutex_unlock(&mutex);
		usleep(200);
	}
}

void* thread2(void* arg)
{
    for(int i = 1; i <= 1; ++i)
	{
		pthread_mutex_lock(&mutex);
        
		printf("thread_2: pthread_cond_wait, i=%d\n", i);
        pthread_cond_wait(&cond,&mutex);
        
	    pthread_mutex_unlock(&mutex);
	    usleep(200);
	}
}
