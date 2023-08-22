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

void* new_thread(void *arg);

#define TH_COUNT 3

int main( void )
{
    pthread_t *thread;
    int* thId;
    
    if((( thread = (pthread_t *)malloc(sizeof(pthread_t)*TH_COUNT))==NULL)
     ||(( thId = (int* )malloc(sizeof(int)*TH_COUNT))==NULL ))
    {
        fprintf(stderr,"Out Of Memory!\n");
        return 1;
    }
    
    for(int i = 0; i< TH_COUNT; ++i)
    {
        thId[i] = i + 1;
        if(pthread_create(&thread[i],NULL, new_thread,(void *)&(thId[i]) )!=0 )
        {
            fprintf(stderr,"Create Thread[%d] Error£º%s\n\a",i,strerror(errno));
            return 1;
        }
        
    }
    
    for(int i = 0; i< TH_COUNT; ++i)
    {
        char* pRet;        
        if( pthread_join(thread[i],(void **)&pRet)!= 0 )
        {
            fprintf(stderr,"Create Thread[%d] Error£º%s\n\a",i,strerror(errno));
            return 1;
        }
        else
        {
            printf("%i: %s\n",i,pRet);
            free(pRet);
        }        
    }
    
    free(thread);
    free(thId);
    
    printf("output: done!\n");

    return 0;
}

void* new_thread(void *arg)
{   
    int thId = *((int*) arg);    
    char* pRet = (char *) malloc(256); 
    usleep( thId * 100 * 1000);
    sprintf(pRet,"Thread %d return.",thId);    
    pthread_exit(pRet);
}
