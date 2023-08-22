#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <strings.h>

#include <stdarg.h>         /* ISO C variable aruments */
// for socket
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//#################################################################################
//
//        1) int socket(int domain, int type,int protocol)
//            domain：通讯协族.
//                    AF_UNIX:只能够用于单一的Unix 系统进程间通信
//                    AF_INET: 是针对Internet的,容许远程主机之间通信
//            type：  通讯协议 
//                    SOCK_STREAM TCP
//                    SOCK_DGRAM  UDP
//            protocol: 0
//            
//        2) int bind(int sockfd, struct sockaddr *my_addr, int addrlen)
//              当用socket()函数创建套接字以后，套接字在名称空间(网络地址族)中存在，
//              但没有任何地址给它赋值。bind()把用addr指定的地址赋值给用文件描述符
//              代表的套接字sockfd。addrlen指定了以addr所指向的地址结构体的字节长度。
//              一般来说，该操作称为“给套接字命名”。
//
//        3) int listen(int sockfd,int backlog);
//              被listen函数作用的套接字，sockfd之前由socket函数返回。
//              在被socket函数返回的套接字fd之时，它是一个主动连接的套接字，
//              也就是此时系统假设用户会对这个套接字调用connect函数，期待它主动与其它进程连接，
//              然后在服务器编程中，用户希望这个套接字可以接受外来的连接请求，也就是被动等待用户来连接。
//              由于系统默认时认为一个套接字是主动连接的，所以需要通过某种方式来告诉系统，
//              用户进程通过系统调用listen来完成这件事。
//
//        4) int accept(int sockfd, struct sockaddr *addr,int *addrlen)
//        5) int connect(int sockfd, struct sockaddr * serv_addr,int addrlen)
//
//##################################################################################################

void err_sys(const char *fmt, ...);

void* service_thread(void *arg);
void* clinet_thread(void *arg);

pthread_t *thread;
int* threadIds;
int curThIndex;
int portnumber; 

#define MAX_COUNT		10
#define CLINET_COUNT	2

void startWorkThread();
void startClientThread();
void startServiceThread();

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
    
    startServiceThread();     
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
    
    printf("output: done.\n");
    
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

void startClientThread()
{    
    sleep(1); //Wait service startup
    
    int thid = curThIndex++;
    threadIds[thid] = thid + 1; 
    pthread_t *pClientThread = &(thread[thid]);   
    
    if(pthread_create(pClientThread,NULL,clinet_thread,(void *)&(threadIds[thid]) )!=0)
        err_sys("main: Create client Thread[%d] Error：%s\n",threadIds[thid],strerror(errno));       
}

void* service_thread(void *arg)
{
    int thId = *((int*) arg);    
    printf("Service: Thread[%d] starting：\n",thId);
    char hello[]="Hello, TCP";
    
    int sockfd;
    int new_fd;
    int sin_size;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    
    /* 服务器端开始建立socket 描述符 */
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
        err_sys("Service: Socket error：%s\n\a",strerror(errno));
    
    /* 服务器端填充 sockaddr 结构 */
    bzero(&server_addr,sizeof(struct sockaddr_in));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    server_addr.sin_port=htons(portnumber);
    
    
    /* 捆绑sockfd 描述符 */
    if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))== -1)
        err_sys("Service: Bind error：%s\n\a",strerror(errno));
    
    /* 监听sockfd 描述符 */
    if(listen(sockfd,5)==-1)
        err_sys("Service: Listen error：%s\n\a",strerror(errno));

    /* 监听sockfd 描述符 */
    if(listen(sockfd,5)==-1)
        err_sys("Service: Listen error：%s\n\a",strerror(errno));
    
    int listenCount = 0;
    while(listenCount++ < CLINET_COUNT)
    {
        /* 服务器阻塞,直到客户程序建立连接 */
        sin_size = sizeof(struct sockaddr_in);
        if( (new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size))== -1 )
            err_sys("Service: Accept error：%s\n\a",strerror(errno));
        
        printf("Server: get connection from %s\n",inet_ntoa(client_addr.sin_addr));
        
        if(write(new_fd,hello,strlen(hello))==-1)
            err_sys("Service: Write Error：%s\n",strerror(errno));
        
        /* 这个通讯已经结束 */
        close(new_fd);
        /* 循环下一个 */
     }
     
     close(sockfd);
     char* pRet = (char *) malloc(256); 
     sprintf(pRet,"Service Thread %d return.",thId);    
     pthread_exit(pRet);
}

void* clinet_thread(void *arg)
{
    int thId = *((int*) arg);    
    printf("Client[%d]: starting：\n",thId);
    
    int sockfd;
    char buffer[1024];
    struct sockaddr_in server_addr;
    struct hostent *host;
    int nbytes;
    
    /* 客户端开始建立socket 描述符 */
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
        err_sys("Client[%d]: socket error：%s\n", thId, strerror(errno));
    
    if((host=gethostbyname("127.0.0.1"))==NULL)
        err_sys("Client[%d]: Gethostname error\n", thId);
    
    /* 客户程序填充服务端的资料 */
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(portnumber);
    server_addr.sin_addr=*((struct in_addr *)host->h_addr_list[0]);    
    
    /* 客户程序发起连接请求 */
    if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
        err_sys("Client[%d]: Connect Error：%s\a\n", thId, strerror(errno));
    
    /* 连接成功了 */
    if((nbytes=read(sockfd,buffer,1024))==-1)
        err_sys("Client[%d]: Read Error：%s\n", thId, strerror(errno));
    
    buffer[nbytes]='\0';
    printf("Client[%d]: received：%s\n",thId, buffer);
    
    /* 结束通讯 */
    close(sockfd);

    char* pRet = (char *) malloc(256); 
    sprintf(pRet,"Client Thread %d return.",thId);    
    pthread_exit(pRet);
}



/*
 * Print a message and return to caller.
 * Caller specifies "errnoflag".
 */
void err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
#define	MAXLINE	4096
   char   buf[MAXLINE];

   vsnprintf(buf, MAXLINE-1, fmt, ap);
   if (errnoflag)
      snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s",
        strerror(error));
   strcat(buf, "\n");
   fflush(stdout);      /* in case stdout and stderr are the same */
   fputs(buf, stderr);
   fflush(NULL);      /* flushes all stdio output streams */
}

/*
 *  * Fatal error related to a system call.
 *   * Print a message and terminate.
 *    */
void err_sys(const char *fmt, ...)
{
	 va_list ap;
	 va_start(ap, fmt);
	 err_doit(1, errno, fmt, ap);
	 va_end(ap);
	 exit(1);
}
