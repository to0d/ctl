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
    
    struct sembuf sem_op;   //�źż��ṹ  
    union semun sem_val;    //�ź�����ֵ  
      
      
    //�����ź�����������ֻ��һ���ź���  
    //IPC_PRIVATE˽�У�ֻ�б��û�ʹ�ã����Ϊ����������Ϊ�����ģ�1Ϊ�źż���������  
    sem_id = semget(IPC_PRIVATE, 1 , IPC_CREAT | 0600 );
   
    if (sem_id == -1){  
        printf(" create sem error!\n ");  
        return(1);      
    }  
    
    printf("create %d sem success!\n", sem_id ); 
    
    //�ź�����ʼ��  
    sem_val.val = 0;   
    
    //�����ź���,0Ϊ��һ���ź�����1Ϊ�ڶ����ź���,...�Դ����ƣ�SETVAL��ʾ����  
    rc = semctl(sem_id,0,SETVAL,sem_val);    
    if ( rc == -1 ){  
        printf("initlize sem error!\n");  
        return(1);      
    }  
    
    //��������  
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
            
            semop( sem_id, &sem_op, 1); //�����ź�����ÿ��-1  
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
            semop(sem_id,&sem_op,1); //�����ź�����ÿ��+1                   
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
