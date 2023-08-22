#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include "stdio.h"
#include <linux/sem.h>
#include <errno.h>

#define MAXNUMS 3 


int get_sem_val( int sid, int semnum);

int main( void )
{
    int sem_id;  
    int pid;  
    int rc;
    
    struct sembuf sem_op;   //信号集结构  
    union semun sem_val;    //信号量数值  
      
      
    //建立信号量集，其中只有一个信号量  
    //IPC_PRIVATE私有，只有本用户使用，如果为正整数，则为公共的；1为信号集的数量；  
    sem_id = semget(IPC_PRIVATE, 1 , IPC_CREAT | 0600 );
   
    if (sem_id == -1){  
        printf(" create sem error!\n ");  
        return(1);      
    }  
    
    printf("create %d sem success!\n", sem_id ); 
    
    //信号量初始化  
    sem_val.val = 0;   
    
    //设置信号量,0为第一个信号量，1为第二个信号量,...以此类推；SETVAL表示设置  
    rc = semctl(sem_id,0,SETVAL,sem_val);    
    if ( rc == -1 ){  
        printf("initlize sem error!\n");  
        return(1);      
    }  
    
    //创建进程  
    pid=fork();  
    
    if (pid == -1 ){  
        printf("fork error!\n");  
        return(1);             
    }     

    if(pid == 0)
    {  
        // child process, consumer
        for (int i=0 ;i < MAXNUMS; i++){  
            sem_op.sem_num=0;  
            sem_op.sem_op=-1;  
            sem_op.sem_flg=0;  
            
            semop( sem_id, &sem_op, 1); //操作信号量，每次-1  
            printf("%d consumer: %d\n", i, get_sem_val(sem_id,0));
            
            usleep(2000);
        }       
    }  
    else
    {
        // parent process, product      
        for (int i=0;i < MAXNUMS; i++){  
        
            sem_op.sem_num=0;  
            sem_op.sem_op=1;  
            sem_op.sem_flg=0;  
            semop(sem_id,&sem_op,1); //操作信号量，每次+1                   
            printf("%d product: %d\n", i, get_sem_val(sem_id,0));  
            
            //sleep(1);            
            usleep(1000);    
        }
        
         printf("output: done.\n");
    }  
    
    usleep(1000);   
   
    
    return(0);  
}

int get_sem_val( int sid, int semnum)
{  
    return( semctl(sid,semnum, GETVAL, 0) );  
}  
