#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <string.h>
#include <unistd.h> 
#include <signal.h>
#include <fcntl.h> 
#include <strings.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>


/* 

Socket Linux IO模型漫谈（6） 信号驱动IO模型 轩脉刃 博客园.html

    信号驱动IO模型主要是在UDP套接字上使用，
    在TCP套接字上几乎是没有什么使用的。 

    struct sigaction
    {
    　　void (*sa_handler) (int);
    　　sigset_t sa_mask;
    　　int sa_flags;
    　　void (*sa_restorer) (void);
    }

*/

void err_sys(const char *fmt, ...);

void* service_thread(void *arg);
void* clinet_thread(void *arg);

pthread_t *thread;
int* threadIds;
int curThIndex;
int portnumber; 
int listenfd1;

#define MAX_COUNT		10
#define CLINET_COUNT	1

void startWorkThread();
void startClientThread();
void startUDP();
void stopUDP();


int main( void )
{
    curThIndex = 0;
    portnumber = 4025;

	/* Golobal var initialization */
    if((( thread=(pthread_t* )malloc(sizeof(pthread_t)*MAX_COUNT))==NULL) 
     ||(( threadIds=(int* )malloc(sizeof(int)*MAX_COUNT))==NULL ))
        err_sys("main: Out Of Memory!\n");
    
    for(int i = 0; i< MAX_COUNT; ++i)
        threadIds[i] = 0;   
    
    startUDP();     
    
    for(int i = 0; i < CLINET_COUNT; ++i)
        startClientThread();
    
    printf("main: Waiting all thread end:\n"); 
    for(int i = 0; i< MAX_COUNT; ++i)
    {
        char* pRet;       
        
        if(threadIds[i] != 0)
        {
            if(pthread_join(thread[i],(void **)&pRet)!= 0)
                err_sys("main: join Thread[%d] Error：%s\n",i,strerror(errno));
            
			printf("main: Thread[%i] end, message=%s\n",i,pRet);
            free(pRet);
        }
    }
    
    free(thread);
    free(threadIds);
    stopUDP();
    return 0;
}

void startServiceThread()
{
    int thid = curThIndex++;
    threadIds[thid] = thid + 1;  
    pthread_t *pServiceThread = &(thread[thid]);   
    
    if(pthread_create(pServiceThread,NULL,service_thread,(void *)&(threadIds[thid]) )!=0)
        err_sys("main: Create serivce Thread[%d] Error：%s\n",threadIds[thid],strerror(errno));       
}

void do_sigio(int sig)
{
    int clifd, clilen;
    struct sockaddr_in cli_addr;
    char buffer[256];

    clifd = accept(listenfd1, (struct sockaddr *) &cli_addr, &clilen);
    
    bzero(buffer, 256);
    read(clifd, buffer, 255);
    
    printf("Server: receive message: %s\n", buffer);
}

void startUDP()
{
    //绑定监听7779端口的fd
    struct sockaddr_in serv_addr1;
    listenfd1 = socket(AF_INET, SOCK_DGRAM, 0);
    
    bzero((char *) &serv_addr1, sizeof(serv_addr1));
    serv_addr1.sin_family = AF_INET;
    serv_addr1.sin_port = htons(7779);
    serv_addr1.sin_addr.s_addr = INADDR_ANY;
    
    struct sigaction sigio_action;
    memset(&sigio_action, 0, sizeof(sigio_action));
    sigio_action.sa_flags = 0;
    sigio_action.sa_handler = do_sigio;
    
    sigaction(SIGIO, &sigio_action, NULL);

    fcntl(listenfd1, F_SETOWN, getpid());   //设置异步I/O所有权 
    
    //更新文件状态标记 
    //  O_ASYNC     当I/O可用的时候，允许SIGIO信号发送到进程组
    //  O_NONBLOCK  非阻塞I/O
    
    int flags; 
    flags = fcntl(listenfd1, F_GETFL, 0);   
    flags |= O_ASYNC | O_NONBLOCK;
    fcntl(listenfd1, F_SETFL, flags);     

    bind(listenfd1, (struct sockaddr *) &serv_addr1, sizeof(serv_addr1));
}

void stopUDP()
{
    close(listenfd1);
}

void* clinet_thread(void *arg)
{
    int thId = *((int*) arg);    
    printf("Client[%d]: starting：\n",thId);
    
    int socketfd, n;
    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    struct sockaddr_in serv_addr;
		
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(7779);
		
    connect(socketfd,(struct sockaddr *)  &serv_addr, sizeof(serv_addr));
		
    write(socketfd, "client message", 14);
}
