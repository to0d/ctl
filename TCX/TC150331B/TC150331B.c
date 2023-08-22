#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/msg.h>

#define MSG_FILE "." 
#define BUFFER 255
#define PERM S_IRUSR|S_IWUSR

struct msgtype {
    long mtype;
    char buffer[BUFFER+1];
};

int main()
{   
    
    struct msgtype msg;
    key_t key;
    int msgid;
    pid_t child;   
    
    if((child = fork()) == -1 )
    {
        printf("Fork Error: %s\n",strerror(errno));
        return(1);
    }
   
    
    if( child == 0)
    {
    // Child process
    
        // 系统建立IPC通讯 （消息队列、信号量和共享内存） 时必须指定一个ID值。
        // 通常情况下，该id值通过ftok函数得到。
        if((key=ftok(MSG_FILE,'a'))== -1)
        {
            fprintf(stderr,"Child: Creat Key Error: %s\n",strerror(errno));
            return(1);
        }
       
        //if((msgid=msgget(key,PERM|IPC_CREAT|IPC_EXCL))==-1)
        if((msgid=msgget(key,PERM|IPC_EXCL))== -1)
        {
            fprintf(stderr,"Child: Creat Message Error: %s\n",strerror(errno));
            return(1);
        }
        
        msgrcv(msgid,&msg,sizeof(struct msgtype),1,0);
        fprintf(stderr,"Child: Server Receive: %s\n",msg.buffer);
        msg.mtype=2;
        msgsnd(msgid,&msg,sizeof(struct msgtype),0);        
    }
    else
    { 
        // parent process, send message 
        sleep(1);
        
        if((key=ftok(MSG_FILE,'a'))== -1)
        {
            fprintf(stderr,"Parent: Creat Key Error: %s\n",strerror(errno));
            return(1);
        }
    
        if((msgid=msgget(key,PERM))== -1)
        {
            fprintf(stderr,"Parent: Creat Message Error: %s\n",strerror(errno));
            return(1);
        }
        
        msg.mtype=1;
        strncpy(msg.buffer,"Client Msg#1",BUFFER);
        msgsnd(msgid,&msg,sizeof(struct msgtype),0);
        memset(&msg,'\0',sizeof(struct msgtype));
        msgrcv(msgid,&msg,sizeof(struct msgtype),2,0);
        fprintf(stderr,"Parent: Client receive：%s\n",msg.buffer);   
    } 
     
    printf("output: done.\n");
    
    return(0);   
}
