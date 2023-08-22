#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t g_mut;

void* th_fn(void *arg)
{
    printf("new : try lock\n");
    pthread_mutex_lock(&g_mut); 
    printf("new : done lock\n");    
    
    usleep(300); 
    
    int* prc = (int*) malloc (sizeof(int));
    *prc = 10;

    printf("new : try unlock\n", *prc);
    pthread_mutex_unlock(&g_mut);
    printf("new : done unlock\n");     
      
    return (void*) prc;
}

int main(void)
{
    pthread_t ptid;
    void *prc;

    pthread_mutex_init(&g_mut,NULL);
    
    pthread_create(&ptid,NULL,th_fn,NULL);
    
    usleep(300);
    printf("main: try lock\n");
    pthread_mutex_lock(&g_mut);
    printf("main: done lock\n");    
    
    usleep(300); 
    printf("main: try unlock\n");
    pthread_mutex_unlock(&g_mut);
    printf("main: done unlock\n");
    
    printf("main: try join\n");
    pthread_join(ptid,&prc);
    printf("main: done join\n");
        
    printf("main: child thread exit id= %d\n", *((int*)prc));
    
    pthread_mutex_destroy(&g_mut);
    
    printf("output: done!\n");
    
    return 0;
}

