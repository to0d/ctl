#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

void* new_thread1(void *arg){
    int i = 0, j = 1;
    sleep(1);
    j *= 2;
    printf("new_thread1, j=%d!\n", j);
    pthread_exit(0);
}

void* new_thread2(void *arg){
    int i = 0, j = 1;
    sleep(5);
    j *= 5;
    printf("new_thread2, j=%d!\n", j);
    pthread_exit(0);
}

#define TH_COUNT 2

int main()
{
    int x = 0;
    pthread_t *thread;
    int* thId;
    
    if((( thread = (pthread_t *)malloc(sizeof(pthread_t)*TH_COUNT))==NULL)
     ||(( thId = (int* )malloc(sizeof(int)*TH_COUNT))==NULL ))
    {
        fprintf(stderr,"Out Of Memory!\n");
        return 1;
    }
    
    for(int i = 0; i< TH_COUNT; ++i){
        thId[i] = i + 1;
        if(pthread_create(&thread[i],NULL, i == 0 ? new_thread1 : new_thread2,(void *)&(thId[i]) )!=0 ){
            fprintf(stderr,"Create Thread[%d] Error：%s\n\a",i,strerror(errno));
            return 1;
        }
    }
    x += 2;
    for(int i = 0; i< TH_COUNT; ++i){
        char* pRet;        
        if( pthread_join(thread[i],(void **)&pRet)!= 0 ){
            fprintf(stderr,"Create Thread[%d] Error：%s\n\a",i,strerror(errno));
            return 1;
        }
    }
    
    free(thread);
    free(thId);
    
    printf("output: done!\n");

    return 0;
}

